/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:32:37 by elopez            #+#    #+#             */
/*   Updated: 2018/01/30 14:42:57 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void		putbutton(t_rt *rt, int x, int y)
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

void		putbutton_l(t_rt *rt, int x, int y)
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

void		putbutton_w(t_rt *rt, int x, int y)
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

static void	putnumpad2(t_rt *rt)
{
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

void		putnumpad(t_rt *rt)
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
	putnumpad2(rt);
}
