/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:32:37 by elopez            #+#    #+#             */
/*   Updated: 2018/01/19 01:19:13 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

inline t_vect	normalize(t_vect v)
{
	double	magnitude;

	magnitude = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	if (magnitude == 0)
		magnitude = 1;
	return ((t_vect){v.x / magnitude, v.y / magnitude, v.z / magnitude});
}

inline t_vect	invert(t_vect v)
{
	return ((t_vect){-v.x, -v.y, -v.z});
}

inline double	vdot(t_vect v1, t_vect v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

inline t_vect	vcross(t_vect v1, t_vect v2)
{
	return ((t_vect){v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x});
}

inline t_vect	vadd(t_vect v1, t_vect v2)
{
	return ((t_vect){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
}
