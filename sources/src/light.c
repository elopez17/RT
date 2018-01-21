/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:36:04 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/20 22:53:55 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_rgb	lighting(t_obj *obj, t_ray *intersect, t_vect light, int shadow)
{
	t_vect	light_dir;
	t_vect	h;
	double	cos_a;

	obj->norm = obj->normal(obj->u, intersect->origin);
	light_dir = normalize(vdiff(light, intersect->origin));
	h = vdiv(vdiff(light_dir, intersect->dir),
			vlen(vdiff(light_dir, intersect->dir)));
	cos_a = fabs(vdot(light_dir, obj->norm));
	if (!shadow && cos_a >= 0.0f && cos_a <= 1.0f)
		return (coloradd(colorscalar(obj->clr, 0.2 + obj->diff * cos_a), color\
scalar((t_rgb){255,255,255}, obj->spec * pow(vdot(obj->norm, h), obj->m))));
	return (colorscalar(obj->clr, 0.2));
}

t_rgb	addlight(t_rt *rt, t_ray *intersect, t_obj *obj, t_vect light)
{
	t_obj	*tmp;
	t_ray	shadow;
	t_dist	d;
	double	*intersects;

	shadow.origin = intersect->origin;
	shadow.dir = normalize(vdiff(light, intersect->origin));
	d.dist = vdiff(light, intersect->origin);
	d.dist_mag = sqrt(pow(d.dist.x, 2) + pow(d.dist.y, 2) + pow(d.dist.z, 2));
	intersects = (double*)malloc(sizeof(double) * rt->nodes);
	d.i = -1;
	tmp = rt->obj;
	while (++d.i < rt->nodes)
	{
		(d.i != 0) ? tmp = tmp->next : 0;
		intersects[d.i] = tmp->inter(shadow, tmp->u);
	}
	while (--d.i >= 0)
		if (intersects[d.i] >= EPS && intersects[d.i] < d.dist_mag - 0.005)
		{
			ft_memdel((void**)&intersects);
			return (lighting(obj, intersect, light, 1));
		}
	ft_memdel((void**)&intersects);
	return (lighting(obj, intersect, light, 0));
}