/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 18:01:49 by elopez            #+#    #+#             */
/*   Updated: 2018/01/09 12:47:56 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

double	ft_atod(const char *s)
{
	double	result;
	double	fact;
	int		point_seen;
	int		d;

	point_seen = 0;
	result = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t' ||
	*s == '\v' || *s == '\r' || *s == '\f' || *s == '+')
		++s;
	fact = (*s == '-' && s++) ? -1 : 1;
	while ((*s >= '0' && *s <= '9') || *s == '.')
	{
		(*s == '.') ? point_seen = 1 : 0;
		if ((d = *s++ - '0') >= 0 && d <= 9)
		{
			(point_seen) ? fact /= 10.0L : 0;
			result = result * 10.0L + (double)d;
		}
	}
	return (result * fact);
}
