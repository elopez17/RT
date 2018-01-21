/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 23:46:51 by elopez            #+#    #+#             */
/*   Updated: 2017/03/22 01:23:06 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	i = -1;
	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	while (++i < n)
		if (*(p1 + i) != *(p2 + i))
			return (*(p1 + i) - *(p2 + i));
	return (0);
}
