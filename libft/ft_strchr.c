/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 01:49:58 by elopez            #+#    #+#             */
/*   Updated: 2017/03/22 03:06:11 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	slen;
	char	pc;

	pc = (char)c;
	slen = ft_strlen(s);
	i = -1;
	if (c == '\0')
		return ((char*)(s + slen));
	else
	{
		while (*(s + ++i))
		{
			if (*(s + i) == pc)
			{
				return ((char*)s + i);
			}
		}
	}
	return (NULL);
}
