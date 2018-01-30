/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:32:37 by elopez            #+#    #+#             */
/*   Updated: 2018/01/20 21:24:49 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	putbutton(t_rt *rt, int x, int y)
{
	int i;

	i = -1;
	while (++i < 50)
	{
		mlx_pixel_put(rt->mlx, rt->win2, x + i, y, 0xf0f0f0);
		mlx_pixel_put(rt->mlx, rt->win2, x, y + i, 0xf0f0f0);
		mlx_pixel_put(rt->mlx, rt->win2, x + i, y + 50, 0xf0f0f0);
		mlx_pixel_put(rt->mlx, rt->win2, x + 50, y + i, 0xf0f0f0);
	}
}

static void	putbutton_l(t_rt *rt, int x, int y)
{
	int i;

	i = -1;
	while (++i < 110)
	{
		if (i < 50)
		{
			mlx_pixel_put(rt->mlx, rt->win2, x + i, y, 0xf0f0f0);
			mlx_pixel_put(rt->mlx, rt->win2, x + i, y + 110, 0xf0f0f0);
		}
		mlx_pixel_put(rt->mlx, rt->win2, x, y + i, 0xf0f0f0);
		mlx_pixel_put(rt->mlx, rt->win2, x + 50, y + i, 0xf0f0f0);
	}
}

static void	putbutton_w(t_rt *rt, int x, int y)
{
	int i;

	i = -1;
	while (++i < 110)
	{
		if (i < 50)
		{
			mlx_pixel_put(rt->mlx, rt->win2, x + 110, y + i, 0xf0f0f0);
			mlx_pixel_put(rt->mlx, rt->win2, x, y + i, 0xf0f0f0);
		}
		mlx_pixel_put(rt->mlx, rt->win2, x + i, y, 0xf0f0f0);
		mlx_pixel_put(rt->mlx, rt->win2, x + i, y + 50, 0xf0f0f0);
	}
}

static void	putnumpad(t_rt *rt)
{
	mlx_string_put(rt->mlx, rt->win2, 550, 20, 0x00f0f0f0,
			"Using the Number Pad:");
	putbutton(rt, 550, 50);
	putbutton(rt, 610, 50);
	putbutton(rt, 670, 50);
	putbutton(rt, 730, 50);
	putbutton(rt, 550, 110);
	putbutton(rt, 610, 110);
	putbutton(rt, 670, 110);
	putbutton(rt, 730, 110);
	putbutton(rt, 550, 170);
	putbutton(rt, 610, 170);
	putbutton(rt, 670, 170);
	putbutton_l(rt, 730, 170);
	putbutton_w(rt, 550, 230);
	putbutton(rt, 670, 230);
	mlx_string_put(rt->mlx, rt->win2, 563, 63, 0x00ff0000, "-7");
	mlx_string_put(rt->mlx, rt->win2, 623, 63, 0x0000ff00, "+8");
	mlx_string_put(rt->mlx, rt->win2, 683, 63, 0x0000ff00, "+9");
	mlx_string_put(rt->mlx, rt->win2, 743, 63, 0x00ff0000, "-");
	mlx_string_put(rt->mlx, rt->win2, 563, 123, 0x00ff0000, "-4");
	mlx_string_put(rt->mlx, rt->win2, 623, 123, 0x00f0f0f0, " 5");
	mlx_string_put(rt->mlx, rt->win2, 683, 123, 0x0000ff00, "+6");
	mlx_string_put(rt->mlx, rt->win2, 743, 123, 0x0000ff00, "+");
	mlx_string_put(rt->mlx, rt->win2, 743, 183, 0x0000ff00, "ENT");
	mlx_string_put(rt->mlx, rt->win2, 623, 243, 0x00ff0000, "-0");
	mlx_string_put(rt->mlx, rt->win2, 683, 243, 0x0000ff00, "+.");
	mlx_string_put(rt->mlx, rt->win2, 563, 183, 0x00ff0000, "-1");
	mlx_string_put(rt->mlx, rt->win2, 623, 183, 0x00ff0000, "-2");
	mlx_string_put(rt->mlx, rt->win2, 683, 183, 0x0000ff00, "+3");
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

static void	putinfo(t_rt *rt)
{
	mlx_string_put(rt->mlx, rt->win2, 10, 70, 0x0000ff00,
"Use '7' / '9' to move sphere/cone/cylinder on X-axis");
	mlx_string_put(rt->mlx, rt->win2, 10, 95, 0x0000ff00,
"sphere/cone/cylinder on X-axis");
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
	mlx_string_put(rt->mlx, rt->win2, 10, 235, 0x00f0f0f0,
"Using ENT / any key - Invert Color");
	mlx_string_put(rt->mlx, rt->win2, 10, 295, 0x00f0f0f0,
"Using 1-5 on the keys on top QWERTY /");
	mlx_string_put(rt->mlx, rt->win2, 10, 315, 0x00f0f0f0,
"insert sphere, plane, cone, cylinder, cube respectively.");
	mlx_string_put(rt->mlx, rt->win2, 10, 570, 0x00ff0000,
"Use 'E' / 'R' to modify intensity of Red");
	mlx_string_put(rt->mlx, rt->win2, 10, 595, 0x0000ff00,
"Use 'F' / 'G' to modify intensity of Green");
	mlx_string_put(rt->mlx, rt->win2, 10, 620, 0x000f0fff,
"Use 'V' / 'B' to modify intensity of Blue");
	mlx_string_put(rt->mlx, rt->win2, 10, 650, 0x00ff00ff,
"Use 'X' / 'S' to modify specular intensity");
	mlx_string_put(rt->mlx, rt->win2, 10, 675, 0x00ff00ff,
"Use 'C' / 'D' to modify diffuse intensity");
	mlx_string_put(rt->mlx, rt->win2, 10, 700, 0x00ff00ff,
"Use 'N' / 'M' to modify gloss intensity");
}

void		controls(t_rt *rt)
{
	putnumpad(rt);
	putkeybrd(rt);
	putinfo(rt);
	mlx_string_put(rt->mlx, rt->win2, 10, 450, 0x00f0f0f0,
"Use UP/DOWN arrows to modify");
	mlx_string_put(rt->mlx, rt->win2, 10, 475, 0x00f0f0f0,
"radius/angle of sphere/cone/cylinder");
mlx_string_put(rt->mlx, rt->win2, 10, 500, 0x00ff00ff,
"Use LEFT/RIGHT arrows to make");
mlx_string_put(rt->mlx, rt->win2, 10, 525, 0x00ff00ff,
"object nonreflect/reflect/refract");
	mlx_string_put(rt->mlx, rt->win2, 10, 20, 0x00ff00ff,
"Change ambient coefficient of each obj '-' / '+'");
	mlx_string_put(rt->mlx, rt->win2, 10, 45, 0x00f0f0f0,
"Click on an Object to Modify, then");
}
