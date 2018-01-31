/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:35:44 by gguiulfo          #+#    #+#             */
/*   Updated: 2018/01/30 17:33:04 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	greyscale_filter(char *image)
{
	unsigned char	*filter;
	int				sum;
	int				i;

	filter = (unsigned char *)image;
	i = 0;
	while (i < 2560000)
	{
		sum = (filter[i] + filter[i + 1] + filter[i + 2]) / 3;
		filter[i] = sum;
		filter[i + 1] = sum;
		filter[i + 2] = sum;
		i += 4;
	}
}

void	natural_greyscale_filter(char *image)
{
	unsigned char	*filter;
	int				sum;
	int				i;

	filter = (unsigned char *)image;
	i = 0;
	while (i < 2560000)
	{
		sum = (0.21 * filter[i]) + (0.72 * filter[i + 1]) +
													(0.07 * filter[i + 2]);
		filter[i] = sum;
		filter[i + 1] = sum;
		filter[i + 2] = sum;
		i += 4;
	}
}

void	whitegreyscale_filter(char *image)
{
	unsigned char	*filter;
	int				sum;
	int				i;

	filter = (unsigned char *)image;
	i = 0;
	while (i < 2560000)
	{
		sum = 128 - (filter[i] + filter[i + 1] + filter[i + 2]) / 3;
		filter[i] = sum;
		filter[i + 1] = sum;
		filter[i + 2] = sum;
		i += 4;
	}
}

void	whitescale_filter(char *image)
{
	unsigned char	*filter;
	int				sum;
	int				i;

	filter = (unsigned char *)image;
	i = 0;
	while (i < 2560000)
	{
		sum = 255 - (filter[i] + filter[i + 1] + filter[i + 2]) / 3;
		filter[i] = sum;
		filter[i + 1] = sum;
		filter[i + 2] = sum;
		i += 4;
	}
}

void	natural_whitegreyscale_filter(char *image)
{
	unsigned char	*filter;
	int				sum;
	int				i;

	filter = (unsigned char *)image;
	i = 0;
	while (i < 2560000)
	{
		sum = 128 - (0.21 * filter[i]) + (0.72 * filter[i + 1]) +
													(0.07 * filter[i + 2]);
		filter[i] = sum;
		filter[i + 1] = sum;
		filter[i + 2] = sum;
		i += 4;
	}
}
