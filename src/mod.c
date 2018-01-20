/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 01:37:58 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/20 02:38:32 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	mod_sphere(int key, t_obj** obj)
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
		(*obj)->u.sphere.clr.red += 20;
	else if (key == KEYE)
		(*obj)->u.sphere.clr.red -= 20;
	else if (key == KEYG)
		(*obj)->u.sphere.clr.green += 20;
	else if (key == KEYF)
		(*obj)->u.sphere.clr.green -= 20;
	else if (key == KEYB)
		(*obj)->u.sphere.clr.blue += 20;
	else if (key == KEYV)
		(*obj)->u.sphere.clr.blue -= 20;
}

static void	mod_plane(int key, t_obj** obj)
{
	if (key == KEY8)
		++(*obj)->u.plane.dist;
	else if (key == KEY2)
		--(*obj)->u.plane.dist;
	else if (key == KEYR)
		(*obj)->u.plane.clr.red += 20;
	else if (key == KEYE)
		(*obj)->u.plane.clr.red -= 20;
	else if (key == KEYG)
		(*obj)->u.plane.clr.green += 20;
	else if (key == KEYF)
		(*obj)->u.plane.clr.green -= 20;
	else if (key == KEYB)
		(*obj)->u.plane.clr.blue += 20;
	else if (key == KEYV)
		(*obj)->u.plane.clr.blue -= 20;
}

static void	mod_cone(int key, t_obj** obj, int toggle)
{
	key == KEYUP ? (*obj)->u.cone.a += 0.035 : 0;
	key == KEYDOWN && (*obj)->u.cone.a > 0.1 ? (*obj)->u.cone.a -= 0.035 : 0;
	if (key == KEY7 && toggle && (*obj)->u.cone.dir.x > -0.9)
		(*obj)->u.cone.dir.x -= 0.1;
	if (key == KEY9 && toggle && (*obj)->u.cone.dir.x < 0.9)
		(*obj)->u.cone.dir.x += 0.1;
	else if (key == KEY4 && toggle && (*obj)->u.cone.dir.y > -0.9)
		(*obj)->u.cone.dir.y -= 0.1;
	else if (key == KEY6 && toggle && (*obj)->u.cone.dir.y < 0.9)
		(*obj)->u.cone.dir.y += 0.1;
	else if (key == KEY1 && toggle && (*obj)->u.cone.dir.z > -0.9)
		(*obj)->u.cone.dir.z -= 0.1;
	else if (key == KEY3 && toggle && (*obj)->u.cone.dir.z < 0.9)
		(*obj)->u.cone.dir.z += 0.1;
	if (key == KEY7 && !toggle)
		(*obj)->u.cone.pos.x -= 2;
	if (key == KEY9 && !toggle)
		(*obj)->u.cone.pos.x += 2;
	else if (key == KEY4 && !toggle)
		(*obj)->u.cone.pos.y += 2;
	else if (key == KEY6 && !toggle)
		(*obj)->u.cone.pos.y -= 2;
	else if (key == KEY1 && !toggle)
		(*obj)->u.cone.pos.z -= 2;
	else if (key == KEY3 && !toggle)
		(*obj)->u.cone.pos.z += 2;
	else if (key == KEYR)
		(*obj)->u.cone.clr.red += 20;
	else if (key == KEYE)
		(*obj)->u.cone.clr.red -= 20;
	else if (key == KEYG)
		(*obj)->u.cone.clr.green += 20;
	else if (key == KEYF)
		(*obj)->u.cone.clr.green -= 20;
	else if (key == KEYB)
		(*obj)->u.cone.clr.blue += 20;
	else if (key == KEYV)
		(*obj)->u.cone.clr.blue -= 20;
	(*obj)->u.cone.dir = normalize((*obj)->u.cone.dir);
}// 14 lines

static void	mod_cube(int key, t_obj** obj, int toggle)
{
	key == KEYUP ? (*obj)->u.cube.len += 0.5 : 0;
	key == KEYDOWN ? (*obj)->u.cube.len -= 0.5 : 0;
	if (key == KEY7)
		(*obj)->u.cube.pos.x -= 2;
	if (key == KEY9)
		(*obj)->u.cube.pos.x += 2;
	else if (key == KEY4)
		(*obj)->u.cube.pos.y += 2;
	else if (key == KEY6)
		(*obj)->u.cube.pos.y -= 2;
	else if (key == KEY1)
		(*obj)->u.cube.pos.z -= 2;
	else if (key == KEY3)
		(*obj)->u.cube.pos.z += 2;
	else if (key == KEYR)
		(*obj)->u.cube.clr.red += 20;
	else if (key == KEYE)
		(*obj)->u.cube.clr.red -= 20;
	else if (key == KEYG)
		(*obj)->u.cube.clr.green += 20;
	else if (key == KEYF)
		(*obj)->u.cube.clr.green -= 20;
	else if (key == KEYB)
		(*obj)->u.cube.clr.blue += 20;
	else if (key == KEYV)
		(*obj)->u.cube.clr.blue -= 20;
	(*obj)->u.cube.min = vdiff((*obj)->u.cube.pos, (t_vect){(*obj)->u.cube.len, (*obj)->u.cube.len, (*obj)->u.cube.len});
	(*obj)->u.cube.max = vadd((*obj)->u.cube.pos, (t_vect){(*obj)->u.cube.len, (*obj)->u.cube.len, (*obj)->u.cube.len});
}// 3 lines

static void	mod_cylind(int key, t_obj** obj, int toggle)
{
	key == KEYUP ? (*obj)->u.cylinder.radius += 0.3 : 0;
	key == KEYDOWN ? (*obj)->u.cylinder.radius -= 0.3 : 0;
	if (key == KEY7 && toggle && (*obj)->u.cylinder.dir.x > -0.9)
		(*obj)->u.cylinder.dir.x -= 0.1;
	if (key == KEY9 && toggle && (*obj)->u.cylinder.dir.x < 0.9)
		(*obj)->u.cylinder.dir.x += 0.1;
	else if (key == KEY4 && toggle && (*obj)->u.cylinder.dir.y > -0.9)
		(*obj)->u.cylinder.dir.y -= 0.1;
	else if (key == KEY6 && toggle && (*obj)->u.cylinder.dir.y < 0.9)
		(*obj)->u.cylinder.dir.y += 0.1;
	else if (key == KEY1 && toggle && (*obj)->u.cylinder.dir.z > -0.9)
		(*obj)->u.cylinder.dir.z -= 0.1;
	else if (key == KEY3 && toggle && (*obj)->u.cylinder.dir.z < 0.9)
		(*obj)->u.cylinder.dir.z += 0.1;
	if (key == KEY7 && !toggle)
		(*obj)->u.cylinder.pos.x -= 2;
	if (key == KEY9 && !toggle)
		(*obj)->u.cylinder.pos.x += 2;
	else if (key == KEY4 && !toggle)
		(*obj)->u.cylinder.pos.y += 2;
	else if (key == KEY6 && !toggle)
		(*obj)->u.cylinder.pos.y -= 2;
	else if (key == KEY1 && !toggle)
		(*obj)->u.cylinder.pos.z -= 2;
	else if (key == KEY3 && !toggle)
		(*obj)->u.cylinder.pos.z += 2;
	else if (key == KEYR)
		(*obj)->u.cylinder.clr.red += 20;
	else if (key == KEYE)
		(*obj)->u.cylinder.clr.red -= 20;
	else if (key == KEYG)
		(*obj)->u.cylinder.clr.green += 20;
	else if (key == KEYF)
		(*obj)->u.cylinder.clr.green -= 20;
	else if (key == KEYB)
		(*obj)->u.cylinder.clr.blue += 20;
	else if (key == KEYV)
		(*obj)->u.cylinder.clr.blue -= 20;
	(*obj)->u.cylinder.dir = normalize((*obj)->u.cylinder.dir);
}// 14 lines

void	move_obj(int key, t_obj **object, int toggle)
{
	if (key == KEYS && (*object)->spec < 1.0f)
		(*object)->spec += 0.3;
	else if (key == KEYX && (*object)->spec > 0.0f)
		(*object)->spec -= 0.3;
	else if (key == KEYLEFT && (*object)->shine == 1)
		--(*object)->shine;
	else if (key == KEYRIGHT && (*object)->shine == 0)
		++(*object)->shine;
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
