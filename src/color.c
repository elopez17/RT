/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:32:37 by elopez            #+#    #+#             */
/*   Updated: 2017/01/08 13:37:50 by oabdalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

double	brightness(t_rgb color)
{
	return ((color.red + color.green + color.blue) / 3.0);
}

t_rgb	colorscalar(t_rgb color, double scalar)
{
	return ((t_rgb){color.red * scalar,
			color.green * scalar,
			color.blue * scalar});
}

t_rgb	coloradd(t_rgb clr1, t_rgb clr2)
{
	return ((t_rgb){clr1.red + clr2.red,
			clr1.green + clr2.green,
			clr1.blue + clr2.blue});
}

t_rgb	colormult(t_rgb clr1, t_rgb clr2)
{
	return ((t_rgb){clr1.red * clr2.red,
			clr1.green * clr2.green,
			clr1.blue * clr2.blue});
}

t_rgb	coloravg(t_rgb clr1, t_rgb clr2)
{
	return ((t_rgb){(clr1.red + clr2.red) / 2,
			(clr1.green + clr2.green) / 2,
			(clr1.blue + clr2.blue) / 2});
}
