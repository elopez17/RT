/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:06:13 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/10 20:07:42 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_vect		cone_norm(t_cone cone, t_vect point)
{
	t_vect	normal;

	normal = vadd(point, invert(cone.pos));
	normal = vadd(normal, invert(vmult(cone.dir, vdot(cone.dir,
						normal))));
	return (normalize(normal));
}

double		findintercone(t_ray ray, t_cone cone)
{
	t_quad	q;

	q.a = pow(cos(cone.a), 2) * vsqr(vdiff(ray.dir, vmult(cone.dir,
vdot(ray.dir, cone.dir)))) - pow(sin(cone.a), 2) * vdot(ray.dir,
cone.dir) * vdot(ray.dir, cone.dir);
	q.b = 2 * pow(cos(cone.a), 2) * vdot(vdiff(ray.dir, vmult(cone.dir, vdot(
ray.dir, cone.dir))), vdiff(vdiff(ray.origin, cone.pos), vmult(cone.dir, vdot(
vdiff(ray.origin, cone.pos), cone.dir)))) - 2 * pow(sin(cone.a), 2) * vdot(
ray.dir, cone.dir) * vdot(vdiff(ray.origin, cone.pos), cone.dir);
	q.c = pow(cos(cone.a), 2) * vsqr(vdiff(vdiff(ray.origin, cone.pos), vmult(
cone.dir, vdot(vdiff(ray.origin, cone.pos), cone.dir)))) - pow(sin(cone.a), 2) *
vdot(vdiff(ray.origin, cone.pos), cone.dir) * vdot(vdiff(ray.origin, cone.pos),
		cone.dir);
	if ((q.d = q.b * q.b - 4 * q.a * q.c) < 0)
		return (-1);
	q.rslt[0] = (-q.b - sqrt(q.d)) / (2 * q.a);
	q.rslt[1] = (-q.b + sqrt(q.d)) / (2 * q.a);
	return (pickinter(q.rslt[0], q.rslt[1]));
}

t_vect		cylinder_norm(t_cylinder cylinder, t_vect point)
{
	t_vect	normal;

	normal = vdiff(point, cylinder.pos);
	normal = vdiff(normal, vmult(cylinder.dir, vdot(cylinder.dir,
					normal)));
	return (normalize(normal));
}

double		findintercylinder(t_ray ray, t_cylinder cyl)
{
	t_quad	q;

	q.a = vsqr(vdiff(ray.dir, vmult(cyl.dir, vdot(ray.dir, cyl.dir))));
	q.b = 2 * vdot(vdiff(ray.dir, vmult(cyl.dir, vdot(ray.dir, cyl.dir))),
vdiff(vdiff(ray.origin, cyl.pos), vmult(cyl.dir, vdot(vdiff(ray.origin,
													cyl.pos), cyl.dir))));
	q.c = vsqr(vdiff(vdiff(ray.origin, cyl.pos), vmult(cyl.dir,
vdot(vdiff(ray.origin, cyl.pos), cyl.dir)))) - cyl.radius * cyl.radius;
	if ((q.d = q.b * q.b - 4 * q.a * q.c) < 0)
		return (-1);
	q.rslt[0] = (-q.b - sqrt(q.d)) / (2 * q.a);
	q.rslt[1] = (-q.b + sqrt(q.d)) / (2 * q.a);
	return (pickinter(q.rslt[0], q.rslt[1]));
}
