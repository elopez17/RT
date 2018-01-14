/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 01:37:58 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/13 18:53:58 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	mod_sphere(int key, t_obj** obj)
{
	if (key == KEY7)
		--(*obj)->u.sphere.pos.x;
	else if (key == KEY9)
		++(*obj)->u.sphere.pos.x;
	else if (key == KEY4)
		--(*obj)->u.sphere.pos.y;
	else if (key == KEY6)
		++(*obj)->u.sphere.pos.y;
	else if (key == KEY1)
		--(*obj)->u.sphere.pos.z;
	else if (key == KEY3)
		++(*obj)->u.sphere.pos.z;
	else if (key == KEYR)
		(*obj)->u.sphere.clr.red += 10;
	else if (key == KEYE)
		(*obj)->u.sphere.clr.red -= 10;
	else if (key == KEYG)
		(*obj)->u.sphere.clr.green += 10;
	else if (key == KEYF)
		(*obj)->u.sphere.clr.green -= 10;
	else if (key == KEYB)
		(*obj)->u.sphere.clr.blue += 10;
	else if (key == KEYV)
		(*obj)->u.sphere.clr.blue -= 10;
}

static void	mod_plane(int key, t_obj** obj)
{
	if (key == KEY8)
		++(*obj)->u.plane.dist;
	else if (key == KEY2)
		--(*obj)->u.plane.dist;
	else if (key == KEYR)
		(*obj)->u.plane.clr.red += 10;
	else if (key == KEYE)
		(*obj)->u.plane.clr.red -= 10;
	else if (key == KEYG)
		(*obj)->u.plane.clr.green += 10;
	else if (key == KEYF)
		(*obj)->u.plane.clr.green -= 10;
	else if (key == KEYB)
		(*obj)->u.plane.clr.blue += 10;
	else if (key == KEYV)
		(*obj)->u.plane.clr.blue -= 10;
}

static void	mod_cone(int key, t_obj** obj)
{
	if (key == KEY7)
		--(*obj)->u.cone.pos.x;
	else if (key == KEY9)
		++(*obj)->u.cone.pos.x;
	else if (key == KEY4)
		--(*obj)->u.cone.pos.y;
	else if (key == KEY6)
		++(*obj)->u.cone.pos.y;
	else if (key == KEY1)
		--(*obj)->u.cone.pos.z;
	else if (key == KEY3)
		++(*obj)->u.cone.pos.z;
	else if (key == KEYR)
		(*obj)->u.cone.clr.red += 10;
	else if (key == KEYE)
		(*obj)->u.cone.clr.red -= 10;
	else if (key == KEYG)
		(*obj)->u.cone.clr.green += 10;
	else if (key == KEYF)
		(*obj)->u.cone.clr.green -= 10;
	else if (key == KEYB)
		(*obj)->u.cone.clr.blue += 10;
	else if (key == KEYV)
		(*obj)->u.cone.clr.blue -= 10;
}

static void	mod_cylind(int key, t_obj** obj)
{
	if (key == KEY7)
		--(*obj)->u.cylinder.pos.x;
	else if (key == KEY9)
		++(*obj)->u.cylinder.pos.x;
	else if (key == KEY4)
		--(*obj)->u.cylinder.pos.y;
	else if (key == KEY6)
		++(*obj)->u.cylinder.pos.y;
	else if (key == KEY1)
		--(*obj)->u.cylinder.pos.z;
	else if (key == KEY3)
		++(*obj)->u.cylinder.pos.z;
	else if (key == KEYR)
		(*obj)->u.cylinder.clr.red += 10;
	else if (key == KEYE)
		(*obj)->u.cylinder.clr.red -= 10;
	else if (key == KEYG)
		(*obj)->u.cylinder.clr.green += 10;
	else if (key == KEYF)
		(*obj)->u.cylinder.clr.green -= 10;
	else if (key == KEYB)
		(*obj)->u.cylinder.clr.blue += 10;
	else if (key == KEYV)
		(*obj)->u.cylinder.clr.blue -= 10;
}

void	move_obj(int key, t_obj **object)
{
	if ((*object)->type == 1)
		mod_sphere(key, object);
	else if ((*object)->type == 2)
		mod_plane(key, object);
	else if ((*object)->type == 3)
		mod_cone(key, object);
	else if ((*object)->type == 4)
		mod_cylind(key, object);
}
