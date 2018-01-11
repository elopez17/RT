/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:33:42 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/06 18:51:05 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	putpixel(t_rtv1 *rt, int x, int y, t_rgb color)
{
	int i;

	if (x < 0 || x >= rt->w.width || y < 0 || y >= rt->w.height)
		return ;
	i = (rt->bpp / 8) * x + rt->len * y;
	if (rt->endian == 0)
	{
		rt->addr[i++] = (color.blue > 255) ? 255 : color.blue;
		rt->addr[i++] = (color.green > 255) ? 255 : color.green;
		rt->addr[i++] = (color.red > 255) ? 255 : color.red;
		rt->addr[i++] = 0;
	}
}
