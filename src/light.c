/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:36:04 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/20 03:06:02 by elopez           ###   ########.fr       */
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

t_rgb	lighting2(t_obj *obj, t_ray *intersect, t_vect light, int shadow)
{
	t_vect	light_dir;
	t_vect	h;
	t_rgb	final;
	double	cos_a;

	light_dir = normalize(vdiff(light, intersect->origin));
	h = vdiv(vdiff(light_dir, intersect->dir), vlen(vdiff(light_dir, intersect->dir)));
	if (obj->type == 3)
	{
		obj->norm = cone_norm(obj->u.cone, intersect->origin);
		cos_a = vdot(light_dir, obj->norm);
		if (shadow == 0 && cos_a >= 0.0f && cos_a <= 1.0f)
			final = coloradd(colorscalar(obj->u.cone.clr, 0.2 + obj->diff * cos_a), colorscalar((t_rgb){255,255,255}, obj->spec * pow(vdot(obj->norm, h), obj->m)));
		else
			final = colorscalar(obj->u.cone.clr, 0.2);
	}
	else if (obj->type == 5)
	{
		obj->norm = cube_norm(obj->u.cube, intersect->origin);
		cos_a = fabs(vdot(light_dir, obj->norm));
		if (shadow == 0)
			final = coloradd(colorscalar(obj->u.cube.clr, 0.2 + obj->diff * cos_a), colorscalar((t_rgb){255,255,255}, obj->spec * pow(vdot(obj->norm, h), obj->m)));
		else
			final = colorscalar(obj->u.cube.clr, 0.2);
	}
	else
	{
		obj->norm = cylinder_norm(obj->u.cylinder, intersect->origin);
		cos_a = vdot(light_dir, obj->norm);
		if (shadow == 0 && cos_a >= 0.0f && cos_a <= 1.0f)
			final = coloradd(colorscalar(obj->u.cylinder.clr, 0.2 + obj->diff * cos_a), colorscalar((t_rgb){255,255,255}, obj->spec * pow(vdot(obj->norm, h), obj->m)));
		else
			final = colorscalar(obj->u.cylinder.clr, 0.2);
	}
	return (final);
}// 10lines

t_rgb	lighting(t_obj *obj, t_ray *intersect, t_vect light, int shadow)
{
	t_vect	light_dir;
	t_vect	h;
	t_rgb	final;
//	t_rgb	obj_clr;
	double	cos_a;

	light_dir = normalize(vdiff(light, intersect->origin));
	h = vdiv(vdiff(light_dir, intersect->dir), vlen(vdiff(light_dir, intersect->dir)));
	if (obj->type == 1)
	{
		obj->norm = sphere_norm(obj->u.sphere, intersect->origin);
		cos_a = vdot(light_dir, obj->norm);
		if (!shadow && cos_a >= 0.0f && cos_a <= 1.0f)
			final = coloradd(colorscalar(obj->u.sphere.clr, 0.2 + obj->diff * cos_a),
				colorscalar((t_rgb){255,255,255}, obj->spec * pow(vdot(obj->norm, h), obj->m)));
		else
			final = colorscalar(obj->u.sphere.clr, 0.2);
		return (final);
	}
	else if (obj->type == 2)
	{
		obj->norm = obj->u.plane.norm;
		cos_a = fabs(vdot(light_dir, obj->norm));
		if (shadow == 0)
			final = coloradd(colorscalar(obj->u.plane.clr, 0.2 + obj->diff * cos_a), colorscalar((t_rgb){255,255,255}, obj->spec * pow(vdot(obj->norm, h), obj->m)));
		else
			final = colorscalar(obj->u.plane.clr, 0.2);
		return (final);
	}
	return (lighting2(obj, intersect, light, shadow));
}// 3lines

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
