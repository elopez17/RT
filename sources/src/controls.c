/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:32:37 by elopez            #+#    #+#             */
/*   Updated: 2018/01/30 14:42:21 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	putkeybrd2(t_rt *rt)
{
	mlx_string_put(rt->mlx, rt->win2, 258, 403, 0x00ff0000, "1");
	mlx_string_put(rt->mlx, rt->win2, 318, 403, 0x00ff0000, "2");
	mlx_string_put(rt->mlx, rt->win2, 378, 403, 0x00ff0000, "3");
	mlx_string_put(rt->mlx, rt->win2, 438, 403, 0x00ff0000, "4");
	mlx_string_put(rt->mlx, rt->win2, 498, 403, 0x00ff0000, "5");
	mlx_string_put(rt->mlx, rt->win2, 473, 463, 0x00ff0000, "-E");
	mlx_string_put(rt->mlx, rt->win2, 533, 463, 0x0000ff00, "+R");
	mlx_string_put(rt->mlx, rt->win2, 533, 523, 0x00ff0000, "-F");
	mlx_string_put(rt->mlx, rt->win2, 593, 523, 0x0000ff00, "+G");
	mlx_string_put(rt->mlx, rt->win2, 413, 523, 0x0000ff00, "+S");
	mlx_string_put(rt->mlx, rt->win2, 473, 523, 0x0000ff00, "+D");
	mlx_string_put(rt->mlx, rt->win2, 633, 583, 0x0000ff00, "+B");
	mlx_string_put(rt->mlx, rt->win2, 573, 583, 0x00ff0000, "-V");
	mlx_string_put(rt->mlx, rt->win2, 453, 583, 0x00ff0000, "-X");
	mlx_string_put(rt->mlx, rt->win2, 513, 583, 0x00ff0000, "-C");
	mlx_string_put(rt->mlx, rt->win2, 753, 583, 0x0000ff00, "+M");
	mlx_string_put(rt->mlx, rt->win2, 693, 583, 0x00ff0000, "-N");
}

static void	putkeybrd(t_rt *rt)
{
	putbutton(rt, 460, 450);
	putbutton(rt, 520, 450);
	putbutton(rt, 400, 510);
	putbutton(rt, 460, 510);
	putbutton(rt, 520, 510);
	putbutton(rt, 580, 510);
	putbutton(rt, 440, 570);
	putbutton(rt, 500, 570);
	putbutton(rt, 560, 570);
	putbutton(rt, 620, 570);
	putbutton(rt, 680, 570);
	putbutton(rt, 740, 570);
	putbutton(rt, 480, 390);
	putbutton(rt, 420, 390);
	putbutton(rt, 360, 390);
	putbutton(rt, 300, 390);
	putbutton(rt, 240, 390);
}

static void	putinfo2(t_rt *rt)
{
	mlx_string_put(rt->mlx, rt->win2, 10, 95, 0x0000ff00,
"Use '7' / '9' to move sphere/cone/cylinder on X-axis");
	mlx_string_put(rt->mlx, rt->win2, 10, 120, 0x00ffff00,
"Use '4' / '6' to move sphere/cone/cylinder on Y-axis");
	mlx_string_put(rt->mlx, rt->win2, 10, 145, 0x0000ffff,
"Use '1' / '3' to move sphere/cone/cylinder on Z-axis");
	mlx_string_put(rt->mlx, rt->win2, 10, 170, 0x0000ff00,
"Use '2' / '8' to move plane nearer/further from center");
	mlx_string_put(rt->mlx, rt->win2, 10, 195, 0x00f0f0f0,
"Use '5' to toggle between rotation/translation");
	mlx_string_put(rt->mlx, rt->win2, 10, 215, 0x00f0f0f0,
"Using X,Y,Z-axis buttons. Applicable to cone/cylinder");
	mlx_string_put(rt->mlx, rt->win2, 10, 20, 0x0000ff00,
"Use 'ENT' on numpad for filters");
	mlx_string_put(rt->mlx, rt->win2, 10, 320, 0x00f0f0f0,
"Using 1-5 on the keys on top QWERTY /");
	mlx_string_put(rt->mlx, rt->win2, 10, 345, 0x00f0f0f0,
"insert sphere, plane, cone, cylinder, cube respectively.");
	mlx_string_put(rt->mlx, rt->win2, 10, 570, 0x00ff0000,
"Use 'E' / 'R' to modify intensity of Red");
	mlx_string_put(rt->mlx, rt->win2, 10, 595, 0x0000ff00,
"Use 'F' / 'G' to modify intensity of Green");
	mlx_string_put(rt->mlx, rt->win2, 10, 620, 0x000f0fff,
"Use 'V' / 'B' to modify intensity of Blue");
}

static void	putinfo(t_rt *rt)
{
	mlx_string_put(rt->mlx, rt->win2, 10, 650, 0x00ff00ff,
"Use 'X' / 'S' to modify Specular intensity");
	mlx_string_put(rt->mlx, rt->win2, 10, 675, 0x00ff00ff,
"Use 'C' / 'D' to modify Diffuse intensity");
	mlx_string_put(rt->mlx, rt->win2, 10, 700, 0x00ff00ff,
"Use 'N' / 'M' to modify Gloss intensity");
	mlx_string_put(rt->mlx, rt->win2, 10, 240, 0x00ff00ff,
"Use '-' / '+' to modify Ambient intensity");
	mlx_string_put(rt->mlx, rt->win2, 10, 275, 0x0000ff00,
"Use '0' / '.' to modify index of refract/reflect/transparency");
	mlx_string_put(rt->mlx, rt->win2, 10, 450, 0x00f0f0f0,
"Use UP/DOWN arrows to modify");
	mlx_string_put(rt->mlx, rt->win2, 10, 475, 0x00f0f0f0,
"radius/angle of sphere/cone/cylinder");
	mlx_string_put(rt->mlx, rt->win2, 10, 500, 0x00ff00ff,
"Use RIGHT arrow to make object");
	mlx_string_put(rt->mlx, rt->win2, 10, 520, 0x00ff00ff,
"reflect/transparent/refract");
	mlx_string_put(rt->mlx, rt->win2, 10, 545, 0x00ff00ff,
"Use LEFT arrow to turn it off");
	mlx_string_put(rt->mlx, rt->win2, 10, 60, 0x00f0f0f0,
"Click on an Object to Modify, then");
}

void		controls(t_rt *rt)
{
	putnumpad(rt);
	putkeybrd(rt);
	putkeybrd2(rt);
	putinfo(rt);
	putinfo2(rt);
}
