/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:32:37 by elopez            #+#    #+#             */
/*   Updated: 2018/01/14 20:17:46 by eLopez           ###   ########.fr       */
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
	mlx_string_put(rt->mlx, rt->win2, 563, 63, 0x00ff0000, "-7");
	mlx_string_put(rt->mlx, rt->win2, 623, 63, 0x0000ff00, "+8");
	mlx_string_put(rt->mlx, rt->win2, 683, 63, 0x0000ff00, "+9");
	mlx_string_put(rt->mlx, rt->win2, 743, 63, 0x00ff0000, "-");
	mlx_string_put(rt->mlx, rt->win2, 563, 123, 0x00ff0000, "-4");
	mlx_string_put(rt->mlx, rt->win2, 623, 123, 0x00f0f0f0, " 5");
	mlx_string_put(rt->mlx, rt->win2, 683, 123, 0x0000ff00, "+6");
	mlx_string_put(rt->mlx, rt->win2, 743, 123, 0x0000ff00, "+");
	mlx_string_put(rt->mlx, rt->win2, 563, 183, 0x00ff0000, "-1");
	mlx_string_put(rt->mlx, rt->win2, 623, 183, 0x00ff0000, "-2");
	mlx_string_put(rt->mlx, rt->win2, 683, 183, 0x0000ff00, "+3");
}

static void	putkeybrd(t_rt *rt)
{
	putbutton(rt, 460, 250);
	putbutton(rt, 520, 250);
	putbutton(rt, 400, 310);
	putbutton(rt, 460, 310);
	putbutton(rt, 520, 310);
	putbutton(rt, 580, 310);
	putbutton(rt, 440, 370);
	putbutton(rt, 500, 370);
	putbutton(rt, 560, 370);
	putbutton(rt, 620, 370);
	putbutton(rt, 680, 370);
	putbutton(rt, 740, 370);
	mlx_string_put(rt->mlx, rt->win2, 473, 263, 0x00ff0000, "-E");
	mlx_string_put(rt->mlx, rt->win2, 533, 263, 0x0000ff00, "+R");
	mlx_string_put(rt->mlx, rt->win2, 533, 323, 0x00ff0000, "-F");
	mlx_string_put(rt->mlx, rt->win2, 593, 323, 0x0000ff00, "+G");
	mlx_string_put(rt->mlx, rt->win2, 413, 323, 0x0000ff00, "+S");
	mlx_string_put(rt->mlx, rt->win2, 473, 323, 0x0000ff00, "+D");
	mlx_string_put(rt->mlx, rt->win2, 633, 383, 0x0000ff00, "+B");
	mlx_string_put(rt->mlx, rt->win2, 573, 383, 0x00ff0000, "-V");
	mlx_string_put(rt->mlx, rt->win2, 453, 383, 0x00ff0000, "-X");
	mlx_string_put(rt->mlx, rt->win2, 513, 383, 0x00ff0000, "-C");
	mlx_string_put(rt->mlx, rt->win2, 753, 383, 0x0000ff00, "+M");
	mlx_string_put(rt->mlx, rt->win2, 693, 383, 0x00ff0000, "-N");
}

static void	putinfo(t_rt *rt)
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
"using X,Y,Z-axis buttons. Applicable to cone/cylinder");
	mlx_string_put(rt->mlx, rt->win2, 10, 370, 0x00ff0000,
"Use 'E' / 'R' to modify intensity of Red");
	mlx_string_put(rt->mlx, rt->win2, 10, 395, 0x0000ff00,
"Use 'F' / 'G' to modify intensity of Green");
	mlx_string_put(rt->mlx, rt->win2, 10, 420, 0x000f0fff,
"Use 'V' / 'B' to modify intensity of Blue");
	mlx_string_put(rt->mlx, rt->win2, 10, 450, 0x00ff00ff,
"Use 'X' / 'S' to modify specular intensity");
	mlx_string_put(rt->mlx, rt->win2, 10, 475, 0x00ff00ff,
"Use 'C' / 'D' to modify diffuse intensity");
	mlx_string_put(rt->mlx, rt->win2, 10, 500, 0x00ff00ff,
"Use 'N' / 'M' to modify gloss intensity");
}//5

void	controls(t_rt *rt)
{
	putnumpad(rt);
	putkeybrd(rt);
	putinfo(rt);
	mlx_string_put(rt->mlx, rt->win2, 10, 525, 0x00ff00ff,
"Use UP/DOWN arrows to modify radius/angle of sphere/cone/cylinder");
	mlx_string_put(rt->mlx, rt->win2, 10, 20, 0x0000ff00,
"Change Brightness of Light with '-' / '+' signs");
	mlx_string_put(rt->mlx, rt->win2, 10, 65, 0x00f0f0f0,
"Click on an Object to Modify, then");
}
