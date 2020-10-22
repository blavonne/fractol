#include "fractol.h"

int			main(int argc, char **argv)
{
	t_fractol	fractol;

	check_argv(argc, argv);
	read_argv(argv[1], &fractol);
	mlx_hook(fractol.mlx.win_ptr, 2, 1L << 0, deal_key, &fractol);
	mlx_hook(fractol.mlx.win_ptr, 4, 1L << 2, zoom_a, &fractol);
//	if (fractol.a.type == 1)
//		mlx_hook(fractol.mlx.win_ptr, 6, 1L << 6, set_julia_c, &fractol);
	mlx_hook(fractol.mlx.win_ptr, 17, 0, clean_exit, &fractol);
	mlx_loop(fractol.mlx.mlx_ptr);
	return 0;
}
