#include <rt.h>

void	inv_filt(char **image)
{
	int i;

	i = -1;
	while (++i < 2560000)
	{
		if (((i + 1) % 4) == 0)
			continue ;
		image[0][i] = 255 - image[0][i];
	}
}
