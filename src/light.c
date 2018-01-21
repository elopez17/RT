/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:36:04 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/20 05:27:45 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_vect	cube_norm(t_cube cube, t_vect point)
{
	t_vect	normal;

	if(fabs(point.x - cube.min.x) < 0.00000001)
		normal = (t_vect){-1, 0, 0};
	else if(fabs(point.x - cube.max.x) < 0.00000001)
		normal = (t_vect){1, 0, 0};
	else if(fabs(point.y - cube.min.y) < 0.00000001)
		normal = (t_vect){0, -1, 0};
	else if(fabs(point.y - cube.max.y) < 0.00000001)
		normal = (t_vect){0, 1, 0};
	else if(fabs(point.z - cube.min.z) < 0.00000001)
		normal = (t_vect){0, 0, -1};
	else if(fabs(point.z - cube.max.z) < 0.00000001)
		normal = (t_vect){0, 0, 1};
	return (normal);
}

static inline void	sphere(t_obj **obj, t_vect normal, t_rgb clr)
{
	(*obj)->norm = normal;
	(*obj)->clr = clr;
}

t_rgb	lighting(t_obj *obj, t_ray *intersect, t_vect light, int shadow)
{
	t_vect	light_dir;
	t_vect	h;
	t_rgb	obj_clr;
	double	cos_a;

	if (obj->type == 1)
	{
		sphere(&obj, sphere_norm(obj->u.sphere, intersect->origin),
				obj->u.sphere.clr);
//		obj->norm = sphere_norm(obj->u.sphere, intersect->origin);
		obj_clr = obj->clr;
	}
	else if (obj->type == 2)
	{
		obj->norm = obj->u.plane.norm;
		obj_clr = obj->u.plane.clr;
	}
	else if (obj->type == 3)
	{
		obj->norm = cone_norm(obj->u.cone, intersect->origin);
		obj_clr = obj->u.cone.clr;
	}
	else if (obj->type == 4)
	{
		obj->norm = cylinder_norm(obj->u.cylinder, intersect->origin);
		obj_clr = obj->u.cylinder.clr;
	}
	else
	{
		obj->norm = cube_norm(obj->u.cube, intersect->origin);
		obj_clr = obj->u.cube.clr;
	}
	light_dir = normalize(vdiff(light, intersect->origin));
	h = vdiv(vdiff(light_dir, intersect->dir),
			vlen(vdiff(light_dir, intersect->dir)));
	cos_a = fabs(vdot(light_dir, obj->norm));
	if (!shadow && cos_a >= 0.0f && cos_a <= 1.0f)
		return (coloradd(colorscalar(obj_clr, 0.2 + obj->diff * cos_a), color\
scalar((t_rgb){255,255,255}, obj->spec * pow(vdot(obj->norm, h), obj->m))));
	return (colorscalar(obj_clr, 0.2));
}// 13lines

t_rgb	addlight(t_rt *rt, t_ray *intersect, t_obj *obj, t_vect light)
{
	t_ray	shadow;
	t_rgb	clr;
	t_dist	d;
	int		index;
	double	*intersects;

	clr = (t_rgb){0, 0, 0};
	shadow.origin = intersect->origin;
	shadow.dir = normalize(vdiff(light, intersect->origin));
	d.dist = vdiff(light, intersect->origin);
	d.dist_mag = sqrt((d.dist.x * d.dist.x) + (d.dist.y * d.dist.y) + (d.dist.z * d.dist.z));
	intersects = findintersects(shadow, rt);
	index = -1;
	while (++index < rt->nodes)
		if (intersects[index] >= 0.00000001 && intersects[index] < d.dist_mag - 0.005)
		{
			clr = lighting(obj, intersect, light, 1);
			break ;
		}
	ft_memdel((void**)&intersects);
	if (index == rt->nodes)
		clr = lighting(obj, intersect, light, 0);
	return (clr);
}
