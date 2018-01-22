/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:32:37 by oabdalha          #+#    #+#             */
/*   Updated: 2018/01/19 15:51:53 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

inline t_vect	plane_norm(t_union u, t_vect point)
{
	if (point.x)
		;
	return (u.plane.norm);
}

inline t_vect	sphere_norm(t_union u, t_vect point)
{
	return (normalize(vdiff(point, u.sphere.pos)));
}

inline t_vect	cone_norm(t_union u, t_vect point)
{
	t_vect	normal;

	normal = vdiff(point, u.cone.pos);
	normal = vdiff(normal, vmult(u.cone.dir, vdot(u.cone.dir, normal)));
	return (normalize(normal));
}

inline t_vect	cylinder_norm(t_union u, t_vect point)
{
	t_vect	normal;

	normal = vdiff(point, u.cylinder.pos);
	normal = vdiff(normal, vmult(u.cylinder.dir, vdot(u.cylinder.dir,
					normal)));
	return (normalize(normal));
}

inline t_vect	cube_norm(t_union u, t_vect point)
{
	t_vect	normal;

	if (fabs(point.x - u.cube.min.x) < EPS)
		normal = (t_vect){-1, 0, 0};
	else if (fabs(point.x - u.cube.max.x) < EPS)
		normal = (t_vect){1, 0, 0};
	else if (fabs(point.y - u.cube.min.y) < EPS)
		normal = (t_vect){0, -1, 0};
	else if (fabs(point.y - u.cube.max.y) < EPS)
		normal = (t_vect){0, 1, 0};
	else if (fabs(point.z - u.cube.min.z) < EPS)
		normal = (t_vect){0, 0, -1};
	else if (fabs(point.z - u.cube.max.z) < EPS)
		normal = (t_vect){0, 0, 1};
	return (normal);
}
