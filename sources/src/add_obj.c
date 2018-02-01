/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:02:14 by evanheum          #+#    #+#             */
/*   Updated: 2018/01/31 17:48:42 by oabdalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#define INIT(obj)({obj->refract = 0;obj->reflect = 0;})

void	addsphere(t_rt **rt)
{
	t_obj	*obj;

	obj = (t_obj*)malloc(sizeof(t_obj));
	obj->type = 1;
	obj->u.sphere.pos = (t_vect){0, 0, 0};
	obj->u.sphere.radius = 1;
	obj->u.sphere.clr = (t_rgb){220, 90, 90};
	obj->normal = &sphere_norm;
	obj->inter = &findintersphere;
	obj->clr = obj->u.sphere.clr;
	obj->reflect = 1;
	obj->refract = 0;
	obj->transparent = 0;
	obj->ior = 1.3;
	obj->io_refl = 1.0;
	obj->io_trans = 0.9;
	obj->spec = 0.3;
	obj->diff = 0.6;
	obj->amb = 0.2;
	obj->m = 4;
	obj->next = (*rt)->obj;
	(*rt)->obj = obj;
	(*rt)->current = (*rt)->obj;
	++(*rt)->nodes;
}

void	addplane(t_rt **rt)
{
	t_obj	*obj;

	obj = (t_obj*)malloc(sizeof(t_obj));
	obj->type = 2;
	obj->u.plane.norm = (t_vect){0, 1, 0};
	obj->u.plane.dist = 1;
	obj->u.plane.clr = (t_rgb){150, 150, 50};
	obj->normal = &plane_norm;
	obj->inter = &findinterplane;
	obj->clr = obj->u.plane.clr;
	obj->reflect = 0;
	obj->refract = 0;
	obj->transparent = 0;
	obj->ior = 1.3;
	obj->io_refl = 1.0;
	obj->io_trans = 0.9;
	obj->spec = 0.3;
	obj->diff = 0.6;
	obj->amb = 0.2;
	obj->m = 4;
	obj->next = (*rt)->obj;
	(*rt)->obj = obj;
	(*rt)->current = (*rt)->obj;
	++(*rt)->nodes;
}

void	addcone(t_rt **rt)
{
	t_obj	*obj;

	obj = (t_obj*)malloc(sizeof(t_obj));
	obj->type = 3;
	obj->u.cone.pos = (t_vect){0, 0, 0};
	obj->u.cone.dir = (t_vect){0, 1, 0};
	obj->u.cone.a = (M_PI / 180) * 20;
	obj->u.cone.clr = (t_rgb){200, 80, 50};
	obj->normal = &cone_norm;
	obj->inter = &findintercone;
	obj->clr = obj->u.cone.clr;
	obj->reflect = 0;
	obj->refract = 0;
	obj->transparent = 0;
	obj->ior = 1.3;
	obj->io_refl = 1.0;
	obj->io_trans = 0.9;
	obj->spec = 0.3;
	obj->diff = 0.6;
	obj->amb = 0.2;
	obj->m = 4;
	obj->next = (*rt)->obj;
	(*rt)->obj = obj;
	(*rt)->current = (*rt)->obj;
	++(*rt)->nodes;
}

void	addcylin(t_rt **rt)
{
	t_obj	*obj;

	obj = (t_obj*)malloc(sizeof(t_obj));
	obj->type = 4;
	obj->u.cylinder.pos = (t_vect){0, 0, 0};
	obj->u.cylinder.dir = (t_vect){0, 1, 0};
	obj->u.cylinder.radius = 1;
	obj->u.cylinder.clr = (t_rgb){50, 180, 180};
	obj->normal = &cylinder_norm;
	obj->inter = &findintercylinder;
	obj->clr = obj->u.cylinder.clr;
	obj->reflect = 1;
	obj->refract = 0;
	obj->transparent = 0;
	obj->ior = 1.3;
	obj->io_refl = 1.0;
	obj->io_trans = 0.9;
	obj->spec = 0.3;
	obj->diff = 0.6;
	obj->amb = 0.2;
	obj->m = 4;
	obj->next = (*rt)->obj;
	(*rt)->obj = obj;
	(*rt)->current = (*rt)->obj;
	++(*rt)->nodes;
}

void	addcube(t_rt **rt)
{
	t_obj	*obj;

	obj = (t_obj*)malloc(sizeof(t_obj));
	obj->type = 5;
	obj->u.cube.pos = (t_vect){0, 0, 0};
	obj->u.cube.min = vdiff(obj->u.cube.pos, (t_vect){1, 1, 1});
	obj->u.cube.max = vadd(obj->u.cube.pos, (t_vect){1, 1, 1});
	obj->u.cube.len = 1;
	obj->u.cube.clr = (t_rgb){150, 100, 190};
	obj->normal = &cube_norm;
	obj->inter = &findintercube;
	obj->clr = obj->u.cube.clr;
	INIT(obj);
	obj->transparent = 0;
	obj->ior = 1.3;
	obj->io_refl = 1.0;
	obj->io_trans = 0.9;
	obj->spec = 0.3;
	obj->diff = 0.6;
	obj->amb = 0.2;
	obj->m = 4;
	obj->next = (*rt)->obj;
	(*rt)->obj = obj;
	(*rt)->current = (*rt)->obj;
	++(*rt)->nodes;
}
