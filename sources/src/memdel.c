#include <rt.h>

void	rt_memdel(t_rt **rt)
{
	mlx_destroy_image((*rt)->mlx, (*rt)->img);
	mlx_destroy_window((*rt)->mlx, (*rt)->win);
	mlx_destroy_window((*rt)->mlx, (*rt)->win2);
	ft_memdel((void**)&(*rt)->light);
	ft_memdel((void**)rt);
}
