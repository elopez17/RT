/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 03:12:09 by elopez            #+#    #+#             */
/*   Updated: 2017/03/22 04:06:12 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;
	char	pc;

	pc = (char)c;
	slen = ft_strlen(s) + 1;
	while (slen--)
	{
		if (*(s + slen) == pc)
			return ((char*)(s + slen));
	}
	return (NULL);
}
