/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:32:37 by elopez            #+#    #+#             */
/*   Updated: 2017/01/08 13:37:50 by oabdalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_vect	vmult(t_vect v, double scalar)
{
	return ((t_vect){v.x * scalar, v.y * scalar, v.z * scalar});
}

t_vect	vdiff(t_vect v1, t_vect v2)
{
	return ((t_vect){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z});
}

double	vsqr(t_vect v)
{
	return (vdot(v, v));
}

double	vlen(t_vect v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}
