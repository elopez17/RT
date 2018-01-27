/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:32:37 by oabdalha          #+#    #+#             */
/*   Updated: 2018/01/26 18:02:05 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	init_rt(t_rt **rt, char *file)
{
	*rt = (t_rt*)ft_memalloc(sizeof(t_rt));
	(*rt)->mlx = mlx_init();
	(*rt)->w.width = 800;
	(*rt)->w.height = 800;
	(*rt)->win = mlx_new_window((*rt)->mlx, (*rt)->w.width, (*rt)->w.height,
										"elopez & oabdalha @ 42");
	(*rt)->win2 = mlx_new_window((*rt)->mlx, (*rt)->w.width, 575,
										"Controls");
	(*rt)->img = mlx_new_image((*rt)->mlx, (*rt)->w.width, (*rt)->w.height);
	(*rt)->addr = mlx_get_data_addr((*rt)->img, &((*rt)->bpp), &((*rt)->len),
													&((*rt)->endian));
	(*rt)->obj = (t_obj*)NULL;
	(*rt)->current = (*rt)->obj;
	(*rt)->nodes = 0;
	(*rt)->nlights = 0;
	(*rt)->toggle = 0;
	(*rt)->cam.pos = (t_vect){0, -3, 5};
	(*rt)->cam.look_at = (t_vect){0, 0, 0};
	if (((*rt)->fd = open(file, O_RDONLY)) == -1)
		rt_error(1);
	parsefile(*rt);
	if ((*rt)->obj == NULL || (*rt)->nodes == 0 || (*rt)->nlights == 0)
		rt_error(2);
}

int			main(int argc, char *argv[])
{
	t_rt		*rt;

	if (argc != 2 || !ft_strstr(argv[1], ".rt"))
		rt_error(0);
	init_rt(&rt, argv[1]);
	controls(rt);
	multithread(rt);
	draw(rt);
	mlx_hook(rt->win, 2, 0, &key_hook, &rt);
	mlx_hook(rt->win, 4, 0, &mousepress, &rt);
	mlx_hook(rt->win, 12, 0, &expose_hook, &rt);
	mlx_hook(rt->win, 17, 0, &close_hook, &rt);
	mlx_loop(rt->mlx);
	return (0);
}
