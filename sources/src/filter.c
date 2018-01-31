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

void	greyscale_filter(char *image)
{
	unsigned char *filter;

	filter = (unsigned char *)image;
	for (int i = 0; i < 2560000; i += 4)
	{
		int sum = (filter[i] + filter[i + 1] + filter[i + 2]) / 3;
		filter[i] = sum;
		filter[i + 1] = sum;
		filter[i + 2] = sum;
	}
}

void	natural_greyscale_filter(char *image)
{
	unsigned char *filter;

	filter = (unsigned char *)image;
	for (int i = 0; i < 2560000; i += 4)
	{
		int sum = (0.21 * filter[i]) + (0.72 * filter[i + 1]) + (0.07 * filter[i + 2]);
		filter[i] = sum;
		filter[i + 1] = sum;
		filter[i + 2] = sum;
	}
}

void	whitegreyscale_filter(char *image)
{
	unsigned char *filter;

	filter = (unsigned char *)image;
	for (int i = 0; i < 2560000; i += 4)
	{
		int sum = 128 - (filter[i] + filter[i + 1] + filter[i + 2]) / 3;
		filter[i] = sum;
		filter[i + 1] = sum;
		filter[i + 2] = sum;
	}
}

void	whitescale_filter(char *image)
{
	unsigned char *filter;

	filter = (unsigned char *)image;
	for (int i = 0; i < 2560000; i += 4)
	{
		int sum = 255 - (filter[i] + filter[i + 1] + filter[i + 2]) / 3;
		filter[i] = sum;
		filter[i + 1] = sum;
		filter[i + 2] = sum;
	}
}

void	natural_whitegreyscale_filter(char *image)
{
	unsigned char *filter;

	filter = (unsigned char *)image;
	for (int i = 0; i < 2560000; i += 4)
	{
		int sum = 128 - (0.21 * filter[i]) + (0.72 * filter[i + 1]) + (0.07 * filter[i + 2]);
		filter[i] = sum;
		filter[i + 1] = sum;
		filter[i + 2] = sum;
	}
}
