/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:32:37 by elopez            #+#    #+#             */
/*   Updated: 2018/01/09 09:55:33 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int		expose_hook(t_rtv1 **rt)
{
	render(*rt);
	return (0);
}

int		key_hook(int key, t_rtv1 **rt)
{
	if (key == KEYESC)
	{
		mlx_destroy_image((*rt)->mlx, (*rt)->img);
		mlx_destroy_window((*rt)->mlx, (*rt)->win);
		ft_memdel((void**)rt);
		exit(0);
	}
	return (0);
}

int		close_hook(t_rtv1 **rt)
{
	key_hook(KEYESC, rt);
	return (0);
}
