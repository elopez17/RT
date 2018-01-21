/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:47:13 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/20 21:23:56 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

pthread_mutex_t g_lock;

static t_rgb	color_at(t_ray *intersection, int index, t_rt *rt, int depth)
{
	t_obj	*tmp;
	int		i;
	t_rgb	final[2];
	t_ray	ray;

	if (index == -1 || depth == 3)
		return ((t_rgb){0, 0, 0});
	tmp = rt->obj;
	while (--index >= 0)
		tmp = tmp->next;
	i = -1;
	final[0] = (t_rgb){0, 0, 0};
	while (++i < rt->nlights)
		final[0] = coloradd(final[0],
							addlight(rt, intersection, tmp, rt->light[i]));
	if (!tmp->shine)
		return (colorscalar(final[0], rt->bright));
	final[1] = (t_rgb){0, 0, 0};
	ray.origin = intersection->origin;
	ray.dir = vadd(intersection->dir,
	vmult(vmult(tmp->norm, 2), -vdot(tmp->norm, intersection->dir)));
	index = findintersect(intersection, ray, rt);
	final[1] = color_at(intersection, index, rt, depth + 1);
	return (colorscalar(coloravg(final[0], final[1]), rt->bright));
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
	if (max < EPS)
		return (-1);
	while (--i >= 0)
		if (intersects[i] >= EPS && intersects[i] <= max)
		{
			max = intersects[i];
			index = i;
		}
	return (index);
}

void			set_ray_xy(t_rt *rt, t_ray *ray, t_xy *pixel)
{
	t_xy		dir;

	dir.x = pixel->x / rt->w.width;
	dir.y = (rt->w.height - pixel->y) / rt->w.height;
	ray->origin = rt->cam.pos;
	ray->dir = normalize(vadd(rt->cam.dir, vadd(vmult(rt->cam.right,
					dir.x - 0.5), vmult(rt->cam.down, dir.y - 0.5))));
}

void			*scene(void *rt)
{
	t_xy		pixel;
	t_ray		ray;
	t_ray		intersection;
	int			index;
	t_rt		*p_rt;

	p_rt = (t_rt*)rt;
	pixel.y = p_rt->ystart - 1;
	pthread_mutex_lock(&g_lock);
	while (++pixel.y < p_rt->ymax)
	{
		pixel.x = -1;
		while (++pixel.x < p_rt->w.width)
		{
			set_ray_xy(p_rt, &ray, &pixel);
			index = findintersect(&intersection, ray, p_rt);
			putpixel(p_rt, pixel.x, pixel.y,
									color_at(&intersection, index, p_rt, 0));
		}
	}
	pthread_mutex_unlock(&g_lock);
	pthread_exit(0);
	return (rt);
}