/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 01:37:58 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/21 18:05:28 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#define LEN (t_vect){(*obj)->u.cube.len, (*obj)->u.cube.len, (*obj)->u.cube.len}
#define CYLX (*obj)->u.cylinder.dir.x
#define CONX (*obj)->u.cone.dir.x

void	mod_cone(int key, t_obj **obj, int toggle)
{
	key == KEYUP ? (*obj)->u.cone.a += 0.035 : 0;
	key == KEYDOWN && (*obj)->u.cone.a > 0.1 ? (*obj)->u.cone.a -= 0.035 : 0;
	(key == KEY7 && toggle && CONX > -0.9) ? CONX -= 0.1 : 0;
	(key == KEY9 && toggle && CONX < 0.9) ? CONX += 0.1 : 0;
	if (key == KEY4 && toggle && (*obj)->u.cone.dir.y > -0.9)
		(*obj)->u.cone.dir.y -= 0.1;
	else if (key == KEY6 && toggle && (*obj)->u.cone.dir.y < 0.9)
		(*obj)->u.cone.dir.y += 0.1;
	else if (key == KEY1 && toggle && (*obj)->u.cone.dir.z > -0.9)
		(*obj)->u.cone.dir.z -= 0.1;
	else if (key == KEY3 && toggle && (*obj)->u.cone.dir.z < 0.9)
		(*obj)->u.cone.dir.z += 0.1;
	(key == KEY7 && !toggle) ? (*obj)->u.cone.pos.x -= 2 : 0;
	(key == KEY9 && !toggle) ? (*obj)->u.cone.pos.x += 2 : 0;
	(key == KEY4 && !toggle) ? (*obj)->u.cone.pos.y += 2 : 0;
	(key == KEY6 && !toggle) ? (*obj)->u.cone.pos.y -= 2 : 0;
	(key == KEY1 && !toggle) ? (*obj)->u.cone.pos.z -= 2 : 0;
	(key == KEY3 && !toggle) ? (*obj)->u.cone.pos.z += 2 : 0;
	(key == KEYR) ? (*obj)->clr.red += 20 : 0;
	(key == KEYE) ? (*obj)->clr.red -= 20 : 0;
	(key == KEYG) ? (*obj)->clr.green += 20 : 0;
	(key == KEYF) ? (*obj)->clr.green -= 20 : 0;
	(key == KEYB) ? (*obj)->clr.blue += 20 : 0;
	(key == KEYV) ? (*obj)->clr.blue -= 20 : 0;
	(*obj)->u.cone.dir = normalize((*obj)->u.cone.dir);
}

void	mod_cube(int key, t_obj **obj, int toggle)
{
	key == KEYUP ? (*obj)->u.cube.len += 0.5 : 0;
	key == KEYDOWN ? (*obj)->u.cube.len -= 0.5 : 0;
	(key == KEY7) ? (*obj)->u.cube.pos.x -= 2 : 0;
	(key == KEY9) ? (*obj)->u.cube.pos.x += 2 : 0;
	(key == KEY4) ? (*obj)->u.cube.pos.y += 2 : 0;
	if (key == KEY6)
		(*obj)->u.cube.pos.y -= 2;
	else if (key == KEY1)
		(*obj)->u.cube.pos.z -= 2;
	else if (key == KEY3)
		(*obj)->u.cube.pos.z += 2;
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
	(*obj)->u.cube.min = vdiff((*obj)->u.cube.pos, LEN);
	(*obj)->u.cube.max = vadd((*obj)->u.cube.pos, LEN);
}

void	mod_cylind(int key, t_obj **obj, int toggle)
{
	key == KEYUP ? (*obj)->u.cylinder.radius += 0.3 : 0;
	key == KEYDOWN ? (*obj)->u.cylinder.radius -= 0.3 : 0;
	(key == KEY7 && toggle && CYLX > -0.9) ? CYLX -= 0.1 : 0;
	(key == KEY9 && toggle && CYLX < 0.9) ? CYLX += 0.1 : 0;
	if (key == KEY4 && toggle && (*obj)->u.cylinder.dir.y > -0.9)
		(*obj)->u.cylinder.dir.y -= 0.1;
	else if (key == KEY6 && toggle && (*obj)->u.cylinder.dir.y < 0.9)
		(*obj)->u.cylinder.dir.y += 0.1;
	else if (key == KEY1 && toggle && (*obj)->u.cylinder.dir.z > -0.9)
		(*obj)->u.cylinder.dir.z -= 0.1;
	else if (key == KEY3 && toggle && (*obj)->u.cylinder.dir.z < 0.9)
		(*obj)->u.cylinder.dir.z += 0.1;
	(key == KEY7 && !toggle) ? (*obj)->u.cylinder.pos.x -= 2 : 0;
	(key == KEY9 && !toggle) ? (*obj)->u.cylinder.pos.x += 2 : 0;
	(key == KEY4 && !toggle) ? (*obj)->u.cylinder.pos.y += 2 : 0;
	(key == KEY6 && !toggle) ? (*obj)->u.cylinder.pos.y -= 2 : 0;
	(key == KEY1 && !toggle) ? (*obj)->u.cylinder.pos.z -= 2 : 0;
	(key == KEY3 && !toggle) ? (*obj)->u.cylinder.pos.z += 2 : 0;
	(key == KEYR) ? (*obj)->clr.red += 20 : 0;
	(key == KEYE) ? (*obj)->clr.red -= 20 : 0;
	(key == KEYG) ? (*obj)->clr.green += 20 : 0;
	(key == KEYF) ? (*obj)->clr.green -= 20 : 0;
	(key == KEYB) ? (*obj)->clr.blue += 20 : 0;
	(key == KEYV) ? (*obj)->clr.blue -= 20 : 0;
	(*obj)->u.cylinder.dir = normalize((*obj)->u.cylinder.dir);
}
