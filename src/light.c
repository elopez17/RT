/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:36:04 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/16 01:01:11 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_rgb	lighting2(t_obj *obj, t_ray *intersect, t_vect light, int shadow)
{
	t_vect	light_dir;
	t_vect	obj_norm;
	t_vect	h;
	t_rgb	final;
	double	cos_a;

	light_dir = normalize(vdiff(light, intersect->origin));
	h = vdiv(vadd(light_dir, invert(intersect->dir)), vlen(vadd(light_dir, invert(intersect->dir))));
	if (obj->type == 3)
	{
		obj_norm = cone_norm(obj->u.cone, intersect->origin);
		cos_a = vdot(light_dir, obj_norm);
		if (shadow == 0 && cos_a >= 0.0f && cos_a <= 1.0f)
			final = coloradd(colorscalar(obj->u.cone.clr, 0.2 + obj->diff * cos_a), colorscalar((t_rgb){255,255,255}, obj->spec * pow(vdot(obj_norm, h), obj->m)));
		else
			final = colorscalar(obj->u.cone.clr, 0.2);
	}
	else if (obj->type == 5)
	{
		obj_norm = vcross(obj->u.cube.min, obj->u.cube.max);
		cos_a = fabs(vdot(light_dir, obj_norm));
		if (shadow == 0)
			final = coloradd(colorscalar(obj->u.cube.clr, 0.2 + obj->diff * cos_a), colorscalar((t_rgb){255,255,255}, obj->spec * pow(vdot(obj_norm, h), obj->m)));
		else
			final = colorscalar(obj->u.cube.clr, 0.2);
	}
	else
	{
		obj_norm = cylinder_norm(obj->u.cylinder, intersect->origin);
		cos_a = vdot(light_dir, obj_norm);
		if (shadow == 0 && cos_a >= 0.0f && cos_a <= 1.0f)
			final = coloradd(colorscalar(obj->u.cylinder.clr, 0.2 + obj->diff * cos_a), colorscalar((t_rgb){255,255,255}, obj->spec * pow(vdot(obj_norm, h), obj->m)));
		else
			final = colorscalar(obj->u.cylinder.clr, 0.2);
	}
	return (final);
}//2lines

t_rgb	lighting(t_obj *obj, t_ray *intersect, t_vect light, int shadow)
{
	t_vect	light_dir;
	t_vect	obj_norm;
	t_vect	h;
	t_rgb	final;
	double	cos_a;

	light_dir = normalize(vdiff(light, intersect->origin));
	h = vdiv(vadd(light_dir, invert(intersect->dir)), vlen(vadd(light_dir, invert(intersect->dir))));
	if (obj->type == 1)
	{
		obj_norm = sphere_norm(obj->u.sphere, intersect->origin);
		cos_a = vdot(light_dir, obj_norm);
		if (shadow == 0 && cos_a >= 0.0f && cos_a <= 1.0f)
			final = coloradd(colorscalar(obj->u.sphere.clr, 0.2 + obj->diff * cos_a), colorscalar((t_rgb){255,255,255}, obj->spec * pow(vdot(obj_norm, h), obj->m)));
		else
			final = colorscalar(obj->u.sphere.clr, 0.2);
		return (final);
	}
	else if (obj->type == 2)
	{
		obj_norm = obj->u.plane.norm;
		cos_a = fabs(vdot(light_dir, obj_norm));
		if (shadow == 0)
			final = coloradd(colorscalar(obj->u.plane.clr, 0.2 + obj->diff * cos_a), colorscalar((t_rgb){255,255,255}, 0 * pow(vdot(obj_norm, h), obj->m)));
		else
			final = colorscalar(obj->u.plane.clr, 0.2);
		return (final);
	}
	return (lighting2(obj, intersect, light, shadow));
}//4lines

t_rgb	addlight(t_rt *rt, t_ray *intersect, t_obj *obj, t_vect light)
{
	t_ray	shadow;
	t_rgb	clr;
	t_dist	d;
	int		index;
	double	*intersects;

	clr = (t_rgb){0, 0, 0};
	shadow.origin = intersect->origin;
	shadow.dir = normalize(vadd(light, invert(intersect->origin)));
	d.dist = vadd(light, invert(intersect->origin));
	d.dist_mag = sqrt((d.dist.x * d.dist.x) + (d.dist.y * d.dist.y) + (d.dist.z * d.dist.z));
	intersects = findintersects(shadow, rt);
	index = -1;
	while (++index < rt->nodes)
		if (intersects[index] >= 0.0000000001 && intersects[index] < d.dist_mag + 0.005)
		{
			clr = lighting(obj, intersect, light, 1);
			break ;
		}
	ft_memdel((void**)&intersects);
	if (index == rt->nodes)
		clr = lighting(obj, intersect, light, 0);
	return (clr);
}
