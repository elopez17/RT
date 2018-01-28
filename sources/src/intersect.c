/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 16:30:17 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/27 19:56:18 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

inline double	pickinter(double inter0, double inter1)
{
	if (inter0 >= EPS)
		return (inter0);
	return ((inter1 >= EPS) ? inter1 : -1);
}

double			findinterplane(t_ray ray, t_union u)
{
	double	a;
	double	b;

	a = vdot(ray.dir, u.plane.norm);
	if (a == 0)
		return (-1);
	b = vdot(u.plane.norm, vdiff(ray.origin,
								vmult(u.plane.norm, u.plane.dist)));
	return (-b / a);
}

double			findintersphere(t_ray ray, t_union u)
{
	t_quad	q;
	t_vect	dist;

	dist = vdiff(ray.origin, u.sphere.pos);
	q.a = pow(ray.dir.x, 2) + pow(ray.dir.y, 2) + pow(ray.dir.z, 2);
	q.b = (2 * dist.x * ray.dir.x) + (2 * dist.y * ray.dir.y) +
											(2 * dist.z * ray.dir.z);
	q.c = pow(dist.x, 2) + pow(dist.y, 2) +
						pow(dist.z, 2) - (u.sphere.radius * u.sphere.radius);
	if ((q.d = q.b * q.b - 4 * q.a * q.c) < 0)
		return (-1);
	q.rslt[0] = ((-q.b - sqrt(q.d)) / (2 * q.a));
	q.rslt[1] = ((-q.b + sqrt(q.d)) / (2 * q.a));
	return (pickinter(q.rslt[0], q.rslt[1]));
}

int				findintersect(t_ray *intersect, t_ray ray, t_rt *rt)
{
	double	*intersects;
	int		i;
	t_obj	*objects;

	i = -1;
	objects = rt->obj;
	intersects = (double*)malloc(sizeof(double) * rt->nodes);
	while (++i < rt->nodes)
	{
		(i != 0) ? objects = objects->next : 0;
		intersects[i] = objects->inter(ray, objects->u);
	}
	if ((i = winningobject(intersects, rt->nodes)) != -1)
	{
		intersect->origin = vadd(ray.origin, vmult(ray.dir, intersects[i]));
		intersect->dir = ray.dir;
	}
	ft_memdel((void**)&intersects);
	return (i);
}

int				winningobject(double *intersects, int nodes)
{
	double	max;
	int		i;
	int		index;

	i = -1;
	max = -1;
	index = 0;
	if (nodes == 0)
		return (-1);
	while (++i < nodes)
		if (intersects[i] > max)
			max = intersects[i];
	if (max < EPS)
		return (-1);
	while (--i >= 0)
		if (intersects[i] >= EPS && intersects[i] <= max)
		{
			max = intersects[i];
			index = i;
		}
	return (index);
}
