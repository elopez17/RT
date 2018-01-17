/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:47:13 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/16 22:00:42 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

double			norm_vect(t_vect v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}

static t_rgb	color_at(t_ray *intersection, int index, t_rt *rt)
{
	t_obj	*tmp;
	int		i;
	t_rgb	final[2];
	double	*intersects;
	t_ray	ray;

	if (index == -1)
		return ((t_rgb){0, 0, 0});
	tmp = rt->obj;
	while (--index >= 0)
		tmp = tmp->next;
	i = -1;
	final[0] = (t_rgb){0, 0, 0};
	final[1] = (t_rgb){0, 0, 0};
	while (++i < rt->nlights)
		final[0] = coloradd(final[0], addlight(rt, intersection, tmp, rt->light[i]));
	if (tmp->shine > 0)
	{
		ray.origin = intersection->origin;
		ray.dir = vadd(intersection->dir,
		vmult(vmult(tmp->norm, 2), -vdot(tmp->norm, intersection->dir)));
		intersects = findintersects(ray, rt);
		if ((index = winningobject(intersects, rt->nodes)) != -1)
		{
			intersection->origin = vadd(ray.origin, vmult(ray.dir,
				intersects[index]));
			intersection->dir = ray.dir;
			final[1] = color_at(intersection, index, rt);
		}
		ft_memdel((void**)&intersects);
	}
	return (colorscalar(coloradd(final[0], final[1]), rt->bright));
}

int				winningobject(double *intersects, int nodes)
{
	double	max;
	int		i;
	int		index;

	i = -1;
	max = -1;
	index = 0;
	if (nodes == 0)
		return (-1);
	while (++i < nodes)
		if (intersects[i] > max)
			max = intersects[i];
	if (max < 0.00000001)
		return (-1);
	while (--i >= 0)
		if (intersects[i] >= 0.00000001 && intersects[i] <= max)
		{
			max = intersects[i];
			index = i;
		}
	return (index);
}

void			setxy(t_rt *rt, t_ray *ray, t_xy *pixel)
{
	t_xy		dir;

	dir.x = pixel->x / rt->w.width;
	dir.y = (rt->w.height - pixel->y) / rt->w.height;
	ray->origin = rt->cam.pos;
	ray->dir = normalize(vadd(rt->cam.dir, vadd(vmult(rt->cam.right,
					dir.x - 0.5), vmult(rt->cam.down, dir.y - 0.5))));
}

void			scene(t_rt *rt)
{
	t_xy		pixel;
	t_ray		ray;
	double		*intersects;
	t_ray		intersection;
	int			index;

	pixel.y = -1;
	while (++pixel.y < rt->w.height)
	{
		pixel.x = -1;
		while (++pixel.x < rt->w.width)
		{
			setxy(rt, &ray, &pixel);
			intersects = findintersects(ray, rt);
			if ((index = winningobject(intersects, rt->nodes)) != -1)
			{
				intersection.origin = vadd(ray.origin, vmult(ray.dir,
							intersects[index]));
				intersection.dir = ray.dir;
			}
			putpixel(rt, pixel.x, pixel.y, color_at(&intersection, index, rt));
			ft_memdel((void**)&intersects);
		}
	}
}
