/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 23:20:59 by elopez            #+#    #+#             */
/*   Updated: 2017/09/20 16:41:14 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcharlen(const wchar_t *s)
{
	size_t i;
	size_t bytes;

	i = 0;
	bytes = 0;
	while (s[i])
	{
		if (s[i] < ((MB_CUR_MAX == 1) ? 0xFF : 0x7F))
			++bytes;
		else if (s[i] <= 0x7ff)
			bytes += 2;
		else if (s[i] <= 0xffff)
			bytes += 3;
		else if (s[i] <= 0x1fffff)
			bytes += 4;
		++i;
	}
	return (bytes);
}
