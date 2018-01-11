/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 22:14:08 by elopez            #+#    #+#             */
/*   Updated: 2017/03/21 23:18:54 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*p_dst;
	char	*p_src;
	size_t	j;

	j = -1;
	p_dst = (char*)dst;
	p_src = (char*)src;
	if (p_src < p_dst)
	{
		while (len > 0)
		{
			len--;
			*(p_dst + len) = *(p_src + len);
		}
	}
	else
		while (++j < len)
			*(p_dst + j) = *(p_src + j);
	return (dst);
}
