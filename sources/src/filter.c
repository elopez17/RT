#include <rt.h>

// GOOD
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

// GOOD
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


// OK
void	filter_three(char *image)
{
	int i;

	i = -1;
	while (++i < 2560000)
	{
		if (((i + 1) % 2) == 0)
			continue ;
		image[i] = 128 - abs(image[i]);
	}
}

// OK
void	filter_four(char *image)
{
	int i;

	i = -1;
	while (++i < 2560000)
	{
		if (((i + 1) % 2) == 0)
			continue ;
		image[i] = 128 - cos(image[i]);
	}
}

// OK
void	filter_five(char *image)
{
	int i;

	i = -1;
	while (++i < 2560000)
	{
		if (((i + 1) % 2) == 0)
			continue ;
		image[i] = 127 - cos(image[i]) + abs(image[i]);
	}
}

// REPEATED
// void	inv_filt(char *image)
// {
// 	int i;
//
// 	i = -1;
// 	while (++i < 2560000)
// 	{
// 		if (((i + 1) % 2) == 0)
// 			continue ;
// 		image[i] = 128 + sin(image[i]) + cos(image[i]);
// 	}
// }

// REPEATED
// void	inv_filt(char *image)
// {
// 	int i;
//
// 	i = -1;
// 	while (++i < 2560000)
// 	{
// 		if (((i + 1) % 2) == 0)
// 			continue ;
// 		image[i] = 128 + (sin(image[i]) - cos(image[i]) + abs(image[i]));
// 	}
// }
//
// NOT GOOD
// void	inv_filt(char *image)
// {
// 	int i;
//
// 	i = -1;
// 	while (++i < 2560000)
// 	{
// 		if (((i + 1) % 2) == 0)
// 			continue ;
// 		image[i] -= arc4random();
// 	}
// }

// GOOD
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
