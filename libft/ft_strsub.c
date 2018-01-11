/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 19:21:46 by elopez            #+#    #+#             */
/*   Updated: 2017/03/23 19:47:06 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*sub_s;
	unsigned int	i;

	i = -1;
	if (!s)
		return (NULL);
	sub_s = ft_strnew(len);
	if (!sub_s)
		return (NULL);
	while (++i < len && s)
		*(sub_s + i) = *(s + start++);
	return (sub_s);
}
