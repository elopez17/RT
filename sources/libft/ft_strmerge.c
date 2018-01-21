/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 13:03:25 by elopez            #+#    #+#             */
/*   Updated: 2017/09/21 20:31:29 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmerge(char *s1, char *s2)
{
	char *new_str;

	if (!s1 || !s2)
	{
		if (s1)
			ft_strdel(&s1);
		if (s2)
			ft_strdel(&s2);
		return (NULL);
	}
	new_str = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (new_str);
}

char	*ft_strmer(char *s1, char *s2)
{
	char *new_str;

	if (!s1 || !s2)
	{
		if (s1)
			ft_strdel(&s1);
		if (s2)
			ft_strdel(&s2);
		return (NULL);
	}
	new_str = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (new_str);
}
