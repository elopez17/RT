/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:32:37 by oabdalha          #+#    #+#             */
/*   Updated: 2018/01/09 12:11:29 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void	init_rtv1(t_rtv1 **rt, char *file)
{
	*rt = (t_rtv1*)ft_memalloc(sizeof(t_rtv1));
	(*rt)->mlx = mlx_init();
	(*rt)->w.width = 800;
	(*rt)->w.height = 800;
	(*rt)->win = mlx_new_window((*rt)->mlx, (*rt)->w.width, (*rt)->w.height,
										"elopez & oabdalha @ 42");
	(*rt)->img = mlx_new_image((*rt)->mlx, (*rt)->w.width, (*rt)->w.height);
	(*rt)->addr = mlx_get_data_addr((*rt)->img, &((*rt)->bpp), &((*rt)->len),
													&((*rt)->endian));
	(*rt)->obj = (t_obj*)NULL;
	(*rt)->nodes = 0;
	(*rt)->cam.pos = (t_vect){0, 0, 0};
	(*rt)->cam.dir = (t_vect){0, 0, 0};
	(*rt)->cam.right = (t_vect){0, 0, 0};
	(*rt)->cam.down = (t_vect){0, 0, 0};
	(*rt)->cam.look_at = (t_vect){0, 0, 0};
	(*rt)->light = (t_vect){60, -30, 60};
	if (((*rt)->fd = open(file, O_RDONLY)) == -1)
		rtv1_error(1);
	parsefile(*rt);
}

int			main(int argc, char *argv[])
{
	t_rtv1		*rt;

	if (argc != 2)
		rtv1_error(0);
	init_rtv1(&rt, argv[1]);
	scene(rt);
	render(rt);
	mlx_hook(rt->win, 2, 0, &key_hook, &rt);
	mlx_hook(rt->win, 12, 0, &expose_hook, &rt);
	mlx_hook(rt->win, 17, 0, &close_hook, &rt);
	mlx_loop(rt->mlx);
	ft_memdel((void**)&rt);
	return (0);
}
