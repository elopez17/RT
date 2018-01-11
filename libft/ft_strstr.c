/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 04:08:30 by elopez            #+#    #+#             */
/*   Updated: 2017/03/22 05:06:17 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char *p_big;
	const char *p_little;

	if (*little == '\0')
		return ((char*)big);
	while (*big != '\0')
	{
		p_big = big;
		p_little = little;
		while (*p_little != '\0' && *p_big == *p_little)
		{
			p_big++;
			p_little++;
		}
		if (*p_little == '\0')
			return ((char*)big);
		big++;
	}
	return (NULL);
}
