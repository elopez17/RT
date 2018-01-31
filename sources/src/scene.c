/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:47:13 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/30 13:02:31 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#define IRFL tmp->io_refl
#define ITRN tmp->io_trans

pthread_mutex_t g_lock;
static int		g_count = -1;

static t_rgb	color_at(t_ray *intersect, int index, t_rt *rt, int depth)
{
	t_obj	*tmp;
	int		i;
	t_rgb	final[2];

	if (index == -1 || depth == 3)
		return ((t_rgb){0, 0, 0});
	tmp = rt->obj;
	while (--index >= 0)
		tmp = tmp->next;
	i = -1;
	final[0] = (t_rgb){0, 0, 0};
	while (++i < rt->nlights)
		final[0] = cadd(final[0], addlight(rt, intersect, tmp, rt->light[i]));
	if (!tmp->reflect && !tmp->refract && !tmp->transparent)
		return (final[0]);
	final[1] = refl_refr(tmp, intersect, rt, depth);
	if (tmp->reflect)
		return (cavg(cscalar(final[0], IRFL), cscalar(final[1], 2 - IRFL)));
	if (tmp->transparent)
		return (cavg(cscalar(final[0], ITRN), cscalar(final[1], 2 - ITRN)));
	return (final[1]);
}

t_rgb			refl_refr(t_obj *tmp, t_ray *intersect, t_rt *rt, int depth)
{
	t_ray	ray;
	double	eta;
	double	cosi;
	double	inside;
	int		index;

	ray.origin = intersect->origin;
	if (tmp->transparent)
		ray.dir = intersect->dir;
	else if (tmp->reflect)
		ray.dir = vadd(intersect->dir,
				vmult(vmult(tmp->norm, 2), -vdot(tmp->norm, intersect->dir)));
	else if (tmp->refract)
	{
		if ((inside = vdot(tmp->norm, intersect->dir)) > 0)
			tmp->norm = invert(tmp->norm);
		eta = (inside > 0) ? tmp->ior : (1 / tmp->ior);
		cosi = -vdot(intersect->dir, tmp->norm);
		ray.origin = vdiff(intersect->origin, vmult(tmp->norm, 1e-4));
		ray.dir = normalize(vadd(vmult(intersect->dir, eta), vmult(tmp->norm,
				(eta * cosi - sqrt(1.0 - eta * eta * (1.0 - cosi * cosi))))));
	}
	index = findintersect(intersect, ray, rt);
	return (color_at(intersect, index, rt, depth + 1));
}

inline void		set_ray_xy(t_rt *rt, t_ray *ray, t_xy *pixel)
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
	(++g_count < 4) ? ft_printf("%{gr}%s", "████████████████████") : 0;
	pthread_mutex_unlock(&g_lock);
	pthread_exit(0);
	return (rt);
}
