/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 23:25:16 by elopez            #+#    #+#             */
/*   Updated: 2017/03/20 00:01:58 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[len])
	{
		len++;
	}
	dup = (char *)malloc(sizeof(*dup) * (len + 1));
	if (dup == NULL)
		return (NULL);
	else
	{
		while (i < len)
		{
			dup[i] = s[i];
			i++;
		}
		dup[i] = '\0';
		return (dup);
	}
}
