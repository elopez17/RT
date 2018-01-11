/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:06:13 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/08 15:00:25 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_vect		cone_norm(t_cone cone, t_vect point)
{
	t_vect	normal;

	normal = vadd(point, invert(cone.pos));
	normal = vadd(normal, invert(vmult(cone.dir, vdot(cone.dir,
						normal))));
	return (normalize(normal));
}

static int	checkheight(t_ray ray, t_cone cone, double rslt[2])
{
	t_vect	inter;

	inter = vadd(ray.origin, vmult(ray.dir, rslt[0]));
	if (cone.h - vlen(vdiff(vdiff(inter, cone.pos), vdiff(vdiff(inter, cone.pos)
, vmult(cone.dir, vdot(cone.dir, vdiff(inter, cone.pos)))))) < 0)
	{
		inter = vadd(ray.origin, vmult(ray.dir, rslt[1]));
		if (cone.h - vlen(vdiff(vdiff(inter, cone.pos), vdiff(vdiff(inter,
cone.pos), vmult(cone.dir, vdot(cone.dir, vdiff(inter, cone.pos)))))) < 0)
			return (-1);
	}
	return (0);
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
	if (checkheight(ray, cone, q.rslt) == -1)
		return (-1);
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
	t_vect	inter;

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
	inter = vadd(ray.origin, vmult(ray.dir, q.rslt[0]));
	if (cyl.h - vlen(vdiff(vdiff(inter, cyl.pos), vmult(
						cylinder_norm(cyl, inter), cyl.radius))) < 0)
	{
		inter = vadd(ray.origin, vmult(ray.dir, q.rslt[1]));
		if (cyl.h - vlen(vdiff(vdiff(inter, cyl.pos), vmult(
							cylinder_norm(cyl, inter), cyl.radius))) < 0)
			return (-1);
	}
	return (pickinter(q.rslt[0], q.rslt[1]));
}
