/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:06:13 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/20 19:51:52 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

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
