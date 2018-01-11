/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 18:01:49 by elopez            #+#    #+#             */
/*   Updated: 2018/01/09 12:46:51 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

float	ft_atof(const char *s)
{
	float	result;
	float	fact;
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
			(point_seen) ? fact /= 10.0f : 0;
			result = result * 10.0f + (float)d;
		}
	}
	return (result * fact);
}
