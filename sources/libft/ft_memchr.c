/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 23:24:15 by elopez            #+#    #+#             */
/*   Updated: 2017/03/21 23:36:33 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*sc;
	size_t		i;

	i = -1;
	sc = (const char*)s;
	while (++i < n)
	{
		if (*(sc + i) == (char)c)
		{
			return ((void*)sc + i);
		}
	}
	return (NULL);
}
