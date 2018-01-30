/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:32:37 by elopez            #+#    #+#             */
/*   Updated: 2018/01/30 11:41:11 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int		expose_hook(t_rt **rt)
{
	draw(*rt);
	return (0);
}

int		mousepress(int key, int x, int y, t_rt **rt)
{
	t_xy	pixel;
	t_ray	ray;
	t_ray	intersect;
	int		index;

	if (key != 1)
		return (0);
	pixel = (t_xy){(double)x, (double)y};
	set_ray_xy(*rt, &ray, &pixel);
	if ((index = findintersect(&intersect, ray, *rt)) != -1)
	{
		(*rt)->current = (*rt)->obj;
		while (--index >= 0)
			(*rt)->current = (*rt)->current->next;
	}
	return (0);
}

int		(*filter_ptr[]) (char *iimage) =
{
	&inv_filt,
	&filter_two,
	&filter_three,
	&filter_four,
	&filter_five,
	&filter_six,
	&filter_seven,
	NULL,
};

void	swap_filter(char *image)
{
	static int i = 0;

	if (filter_ptr[i])
		(*filter_ptr[i++])(image);
	else
		i = 0;
}

int		key_hook(int key, t_rt **rt)
{
	t_obj *tmp;

	(key == KTOP1) ? addsphere(rt) : 0;
	(key == KTOP2) ? addplane(rt) : 0;
	(key == KTOP3) ? addcone(rt) : 0;
	(key == KTOP4) ? addcylin(rt) : 0;
	(key == KTOP5) ? addcube(rt) : 0;
	(key == KEY5) ? (*rt)->toggle ^= 1 : 0;
	if (key == KEYESC)
	{
		while ((*rt)->obj != NULL)
		{
			tmp = (*rt)->obj->next;
			ft_memdel((void**)&(*rt)->obj);
			(*rt)->obj = tmp;
		}
		mlx_destroy_image((*rt)->mlx, (*rt)->img);
		mlx_destroy_window((*rt)->mlx, (*rt)->win);
		mlx_destroy_window((*rt)->mlx, (*rt)->win2);
		ft_memdel((void**)&(*rt)->light);
		ft_memdel((void**)rt);
		exit(0);
	}
	else if ((*rt)->current != NULL)
		move_obj(key, &(*rt)->current, (*rt)->toggle);
	multithread(*rt);
	(key == KEYENT) ? swap_filter((*rt)->addr) : 0;
	draw(*rt);
	return (0);
}

int		close_hook(t_rt **rt)
{
	key_hook(KEYESC, rt);
	return (0);
}
