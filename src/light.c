/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:36:04 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/13 16:53:34 by eLopez           ###   ########.fr       */
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
	double	specular;
	double	m;
	double	diffuse;

	diffuse = 0.6;
	m = 15;
	specular = 0.4;
	light_dir = normalize(vdiff(light, intersect->origin));
	h = vdiv(vadd(light_dir, invert(intersect->dir)), vlen(vadd(light_dir, invert(intersect->dir))));
	if (obj->type == 3)
	{
		obj_norm = cone_norm(obj->u.cone, intersect->origin);
		cos_a = vdot(light_dir, obj_norm);
		if (shadow == 0 && cos_a >= 0.0f && cos_a <= 1.0f)
			final = coloradd(colorscalar(obj->u.cone.clr, 0.2 + diffuse * cos_a), colorscalar((t_rgb){255,255,255}, specular * pow(vdot(obj_norm, h), m)));
		else
			final = colorscalar(obj->u.cone.clr, 0.2);
	}
	else
	{
		obj_norm = cylinder_norm(obj->u.cylinder, intersect->origin);
		cos_a = vdot(light_dir, obj_norm);
		if (shadow == 0 && cos_a >= 0.0f && cos_a <= 1.0f)
			final = coloradd(colorscalar(obj->u.cylinder.clr, 0.2 + diffuse * cos_a), colorscalar((t_rgb){255,255,255}, specular * pow(vdot(obj_norm, h), m)));
		else
			final = colorscalar(obj->u.cylinder.clr, 0.2);
	}
	return (final);
}

t_rgb	lighting(t_obj *obj, t_ray *intersect, t_vect light, int shadow)
{
	t_vect	light_dir;
	t_vect	obj_norm;
	t_vect	h;
	t_rgb	final;
	double	cos_a;
	double	specular;
	double	m;
	double	diffuse;

	diffuse = 0.6;
	m = 15;
	specular = 0.4;
	light_dir = normalize(vdiff(light, intersect->origin));
	h = vdiv(vadd(light_dir, invert(intersect->dir)), vlen(vadd(light_dir, invert(intersect->dir))));
	if (obj->type == 1)
	{
		obj_norm = sphere_norm(obj->u.sphere, intersect->origin);
		cos_a = vdot(light_dir, obj_norm);
		if (shadow == 0 && cos_a >= 0.0f && cos_a <= 1.0f)
			final = coloradd(colorscalar(obj->u.sphere.clr, 0.2 + diffuse * cos_a), colorscalar((t_rgb){255,255,255}, specular * pow(vdot(obj_norm, h), m)));
		else
			final = colorscalar(obj->u.sphere.clr, 0.2);
		return (final);
	}
	else if (obj->type == 2)
	{
		obj_norm = obj->u.plane.norm;
		cos_a = fabs(vdot(light_dir, obj_norm));
		if (shadow == 0 && cos_a >= 0.0f && cos_a <= 1.0f)
			final = coloradd(colorscalar(obj->u.plane.clr, 0.2 + diffuse * cos_a), colorscalar((t_rgb){255,255,255}, specular * pow(vdot(obj_norm, h), m)));
		else
			final = colorscalar(obj->u.plane.clr, 0.2);
		return (final);
	}
	return (lighting2(obj, intersect, light, shadow));
}
