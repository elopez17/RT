/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:47:13 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/26 20:11:54 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

pthread_mutex_t g_lock;
static int		g_count = -1;

static t_rgb	color_at(t_ray *intersect, int index, t_rt *rt, int depth)
{
	t_obj	*tmp;
	int		i;
	t_rgb	final[3];
	t_ray	ray[2];
	double	eta;
	double	cosi;
	int		inside = 0;

	if (index == -1 || depth == 3)
		return ((t_rgb){0, 0, 0});
	tmp = rt->obj;
	while (--index >= 0)
		tmp = tmp->next;
	i = -1;
	final[0] = (t_rgb){0, 0, 0};
	while (++i < rt->nlights)
		final[0] = coloradd(final[0],
				addlight(rt, intersect, tmp, rt->light[i]));
	if (!tmp->reflect && !tmp->refract)
		return (final[0]);
	if (tmp->reflect)
	{
	final[1] = (t_rgb){0, 0, 0};
	ray[0].origin = vadd(intersect->origin, vmult(tmp->norm, 1e-4));
	ray[0].dir = vadd(intersect->dir,
				vmult(vmult(tmp->norm, 2), -vdot(tmp->norm, intersect->dir)));
	index = findintersect(intersect, ray[0], rt);
	final[1] = color_at(intersect, index, rt, depth + 1);
	}
	if (!tmp->refract)
		return (coloravg(colorscalar(final[0], tmp->io_refl),
				colorscalar(final[1], 2 - tmp->io_refl)));
	if (vdot(tmp->norm, intersect->dir) > 0) tmp->norm = invert(tmp->norm), inside = 1;
	eta = (inside) ? tmp->ior : (1 / tmp->ior);
	cosi = -vdot(intersect->dir, tmp->norm);
	ray[1].origin = vdiff(intersect->origin, vmult(tmp->norm, 1e-4));
	ray[1].dir = normalize(vadd(vmult(intersect->dir, eta),
vmult(tmp->norm, (eta * cosi - sqrt(1.0 - eta * eta * (1.0 - cosi * cosi))))));
	index = findintersect(intersect, ray[1], rt);
	final[2] = color_at(intersect, index, rt, depth + 1);
	if (!tmp->reflect)
		return (final[2]);
	return (colorscalar(coloradd(coloradd(final[0], final[1]), final[2])
				, 0.3333));
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
	(++g_count < 4) ? ft_printf("%{gr}%s", "####################") : 0;
	pthread_mutex_unlock(&g_lock);
	pthread_exit(0);
	return (rt);
}
