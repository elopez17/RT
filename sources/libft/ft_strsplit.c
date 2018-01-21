/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 22:50:07 by elopez            #+#    #+#             */
/*   Updated: 2017/10/21 09:44:52 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		nwords;
	char	**str2;

	nwords = ft_countwords(s, c);
	if (!s || !(str2 = (char **)malloc(sizeof(*str2) * (nwords + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < nwords)
	{
		k = 0;
		if (!(str2[i] = ft_strnew(ft_word_len(&s[j], c) + 1)))
			str2[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			str2[i][k++] = s[j++];
		str2[i][k] = '\0';
	}
	str2[i] = 0;
	return (str2);
}
