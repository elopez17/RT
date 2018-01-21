/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimttoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:40:20 by elopez            #+#    #+#             */
/*   Updated: 2017/09/12 20:08:16 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_str_len(uintmax_t n)
{
	size_t		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_uimttoa(uintmax_t n)
{
	char		*str;
	size_t		str_len;

	str_len = get_str_len(n);
	if (!(str = ft_strnew(str_len)))
		return (NULL);
	str[--str_len] = n % 10 + '0';
	while (n /= 10)
		str[--str_len] = n % 10 + '0';
	return (str);
}
