/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 19:48:50 by elopez            #+#    #+#             */
/*   Updated: 2017/03/23 20:33:43 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	new_slen;
	size_t	i;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	new_slen = ft_strlen(s2) + ft_strlen(s1);
	new_s = ft_strnew(new_slen);
	if (!new_s)
		return (NULL);
	while (*s1)
		*(new_s + ++i) = *(s1++);
	while (*s2)
		*(new_s + ++i) = *(s2++);
	*(new_s + ++i) = '\0';
	return (new_s);
}
