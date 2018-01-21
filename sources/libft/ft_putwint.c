/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 13:03:08 by elopez            #+#    #+#             */
/*   Updated: 2017/09/25 18:12:01 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwint(wint_t wc)
{
	char str[5];

	if (wc < (MB_CUR_MAX == 1 ? 0xFF : 0x7F))
		return (write(1, &wc, 1));
	else if (wc <= 0x7FF)
	{
		str[0] = ((wc & 0x7c0) >> 6) | 0xc0;
		str[1] = (wc & 0x3f) | 0x80;
		return (write(1, str, 2));
	}
	else if (wc <= 0xFFFF)
	{
		str[0] = ((wc & 0xf000) >> 12) | 0xe0;
		str[1] = ((wc & 0xfc0) >> 6) | 0x80;
		str[2] = (wc & 0x3f) | 0x80;
		return (write(1, str, 3));
	}
	if (wc > 0x1FFFFF)
		return (-1);
	str[0] = ((wc & 0x1c0000) >> 18) | 0xf0;
	str[1] = ((wc & 0x3f000) >> 12) | 0x80;
	str[2] = ((wc & 0xfc0) >> 6) | 0x80;
	str[3] = (wc & 0x3f) | 0x80;
	return (write(1, str, 4));
}
