/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:50:51 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/10 20:09:53 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	draw(t_rt *rt)
{
	mlx_clear_window(rt->mlx, rt->win);
	mlx_put_image_to_window(rt->mlx, rt->win, rt->img, 0, 0);
}
