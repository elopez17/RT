/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:06:13 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/30 12:38:51 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#define SWAPD(a, b)({double tmp = a; a = b; b = tmp;})

double		findintercube(t_ray ray, t_union u)
{
	t_vect	min;
	t_vect	max;

	min.x = (u.cube.min.x - ray.origin.x) / (ray.dir.x == 0 ? EPS : ray.dir.x);
	max.x = (u.cube.max.x - ray.origin.x) / (ray.dir.x == 0 ? EPS : ray.dir.x);
	min.y = (u.cube.min.y - ray.origin.y) / (ray.dir.y == 0 ? EPS : ray.dir.y);
	max.y = (u.cube.max.y - ray.origin.y) / (ray.dir.y == 0 ? EPS : ray.dir.y);
	min.z = (u.cube.min.z - ray.origin.z) / (ray.dir.z == 0 ? EPS : ray.dir.z);
	max.z = (u.cube.max.z - ray.origin.z) / (ray.dir.z == 0 ? EPS : ray.dir.z);
	if (min.x > max.x)
		SWAPD(min.x, max.x);
	if (min.y > max.y)
		SWAPD(min.y, max.y);
	if ((min.x > max.y) || (min.y > max.x))
		return (-1);
	(min.y > min.x) ? min.x = min.y : 0;
	(max.y < max.x) ? max.x = max.y : 0;
	if (min.z > max.z)
		SWAPD(min.z, max.z);
	if ((min.x > max.z) || (min.z > max.x))
		return (-1);
	(min.z > min.x) ? min.x = min.z : 0;
	(max.z < max.x) ? max.x = max.z : 0;
	return (pickinter(min.x, max.x));
}

double		findintercone(t_ray ray, t_union u)
{
	t_quad	q;
	double	cos_a;
	double	sin_a;

	cos_a = cos(u.cone.a);
	sin_a = sin(u.cone.a);
	q.a = pow(cos_a, 2) * vsqr(vdiff(ray.dir, vmult(u.cone.dir, vdot(ray.dir,
u.cone.dir)))) - pow(sin_a, 2) * vdot(ray.dir, u.cone.dir) *
													vdot(ray.dir, u.cone.dir);
	q.b = 2 * pow(cos_a, 2) * vdot(vdiff(ray.dir, vmult(u.cone.dir, vdot(
ray.dir, u.cone.dir))), vdiff(vdiff(ray.origin, u.cone.pos), vmult(u.cone.dir,
vdot(vdiff(ray.origin, u.cone.pos), u.cone.dir)))) - 2 * pow(sin_a, 2) * vdot(
ray.dir, u.cone.dir) * vdot(vdiff(ray.origin, u.cone.pos), u.cone.dir);
	q.c = pow(cos_a, 2) * vsqr(vdiff(vdiff(ray.origin, u.cone.pos), vmult(
u.cone.dir, vdot(vdiff(ray.origin, u.cone.pos), u.cone.dir)))) - pow(sin_a, 2) *
vdot(vdiff(ray.origin, u.cone.pos), u.cone.dir) * vdot(
vdiff(ray.origin, u.cone.pos), u.cone.dir);
	if ((q.d = q.b * q.b - 4 * q.a * q.c) < 0)
		return (-1);
	q.rslt[0] = (-q.b - sqrt(q.d)) / (2 * q.a);
	q.rslt[1] = (-q.b + sqrt(q.d)) / (2 * q.a);
	return (pickinter(q.rslt[0], q.rslt[1]));
}

double		findintercylinder(t_ray ray, t_union u)
{
	t_quad	q;

	q.a = vsqr(vdiff(ray.dir, vmult(u.cylinder.dir, vdot(ray.dir,
						u.cylinder.dir))));
	q.b = 2 * vdot(vdiff(ray.dir, vmult(u.cylinder.dir, vdot(ray.dir,
u.cylinder.dir))), vdiff(vdiff(ray.origin, u.cylinder.pos), vmult(
u.cylinder.dir, vdot(vdiff(ray.origin, u.cylinder.pos), u.cylinder.dir))));
	q.c = vsqr(vdiff(vdiff(ray.origin, u.cylinder.pos), vmult(u.cylinder.dir,
vdot(vdiff(ray.origin, u.cylinder.pos), u.cylinder.dir)))) -
										u.cylinder.radius * u.cylinder.radius;
	if ((q.d = q.b * q.b - 4 * q.a * q.c) < 0)
		return (-1);
	q.rslt[0] = (-q.b - sqrt(q.d)) / (2 * q.a);
	q.rslt[1] = (-q.b + sqrt(q.d)) / (2 * q.a);
	return (pickinter(q.rslt[0], q.rslt[1]));
}
