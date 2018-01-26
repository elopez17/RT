/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 01:37:58 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/25 21:03:21 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	mod_sphere(int key, t_obj **obj)
{
	key == KEYUP ? (*obj)->u.sphere.radius += 0.3 : 0;
	key == KEYDOWN ? (*obj)->u.sphere.radius -= 0.3 : 0;
	key == KEY7 ? (*obj)->u.sphere.pos.x -= 2 : 0;
	if (key == KEY9)
		(*obj)->u.sphere.pos.x += 2;
	else if (key == KEY4)
		(*obj)->u.sphere.pos.y += 2;
	else if (key == KEY6)
		(*obj)->u.sphere.pos.y -= 2;
	else if (key == KEY1)
		(*obj)->u.sphere.pos.z -= 2;
	else if (key == KEY3)
		(*obj)->u.sphere.pos.z += 2;
	else if (key == KEYR)
		(*obj)->clr.red += 20;
	else if (key == KEYE)
		(*obj)->clr.red -= 20;
	else if (key == KEYG)
		(*obj)->clr.green += 20;
	else if (key == KEYF)
		(*obj)->clr.green -= 20;
	else if (key == KEYB)
		(*obj)->clr.blue += 20;
	else if (key == KEYV)
		(*obj)->clr.blue -= 20;
}

static void	mod_plane(int key, t_obj **obj)
{
	if (key == KEY8)
		++(*obj)->u.plane.dist;
	else if (key == KEY2)
		--(*obj)->u.plane.dist;
	else if (key == KEYR)
		(*obj)->clr.red += 20;
	else if (key == KEYE)
		(*obj)->clr.red -= 20;
	else if (key == KEYG)
		(*obj)->clr.green += 20;
	else if (key == KEYF)
		(*obj)->clr.green -= 20;
	else if (key == KEYB)
		(*obj)->clr.blue += 20;
	else if (key == KEYV)
		(*obj)->clr.blue -= 20;
}

void		move_obj(int key, t_obj **object, int toggle)
{
	(key == KEY0 && toggle && (*object)->io_refl > 0.0) ? (*object)->io_refl -= 0.1 : 0;
	(key == KEYDOT && toggle && (*object)->io_refl < 1.0) ? (*object)->io_refl += 0.1 : 0;
	(key == KEY0 && !toggle && (*object)->ior >= 1.1) ? (*object)->ior -= 0.1 : 0;
	(key == KEYDOT && !toggle && (*object)->ior <= 1.9) ? (*object)->ior += 0.1 : 0;
	(key == KEYRIGHT) ? (*object)->reflect ^= 1 : 0;
	if (key == KEYRIGHT)
		(*object)->refract = (!(*object)->reflect) ? 1 : 0;
	if (key == KEYS && (*object)->spec < 1.0f)
		(*object)->spec += 0.3;
	else if (key == KEYX && (*object)->spec > 0.0f)
		(*object)->spec -= 0.3;
	else if (key == KEYLEFT && ((*object)->reflect = 0) == 0)
		(*object)->refract = 0;
	else if (key == KEYD && (*object)->diff < 1.0f)
		(*object)->diff += 0.3;
	else if (key == KEYC && (*object)->diff > 0.0f)
		(*object)->diff -= 0.3;
	else if (key == KEYN && (*object)->m > 2)
		(*object)->m -= 3;
	else if (key == KEYM && ((*object)->m < 20))
		(*object)->m += 3;
	else if ((*object)->type == 1)
		mod_sphere(key, object);
	else if ((*object)->type == 2)
		mod_plane(key, object);
	else if ((*object)->type == 3)
		mod_cone(key, object, toggle);
	else if ((*object)->type == 4)
		mod_cylind(key, object, toggle);
	((*object)->type == 5) ? mod_cube(key, object, toggle) : 0;
}
