/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:35:44 by gguiulfo          #+#    #+#             */
/*   Updated: 2018/01/30 17:30:12 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	inv_filt(char *image)
{
	int i;

	i = -1;
	while (++i < 2560000)
	{
		if (((i + 1) % 4) == 0)
			continue ;
		image[i] = 255 - image[i];
	}
}

void	filter_two(char *image)
{
	int i;

	i = -1;
	while (++i < 2560000)
	{
		if (((i + 1) % 4) == 0)
			continue ;
		image[i] = 128 - abs(image[i]);
	}
}

void	filter_six(char *image)
{
	int i;

	i = -1;
	while (++i < 2560000)
	{
		if (((i + 1) % 2) == 0)
			continue ;
		image[i] = (image[i] || -image[i]);
	}
}

void	filter_seven(char *image)
{
	int i;

	i = -1;
	while (++i < 2560000)
	{
		if (((i + 1) % 2) == 0)
			continue ;
		image[i] = image[i] / 128 + 50;
	}
}
