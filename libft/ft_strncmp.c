/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 21:55:11 by elopez            #+#    #+#             */
/*   Updated: 2017/03/23 01:17:20 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (*(s1 + i) != '\0' && *(s1 + i) == *(s2 + i) && i < n - 1)
		i++;
	if (n)
		return (*((unsigned char*)s1 + i) - *((unsigned char*)s2 + i));
	return (0);
}
