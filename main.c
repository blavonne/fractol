#include "fractol.h"

int			main(int argc, char **argv)
{
	t_fractol	fractol;

	check_argv(argc, argv);
	read_argv(argv[1], &fractol);
	mlx_expose_hook(fractol.mlx.win, rendering, &fractol);
	mlx_key_hook(fractol.mlx.win, key_pressed, &fractol);
	mlx_hook(fractol.mlx.win, 4, 1L << 2, zoom_a, &fractol);
	mlx_hook(fractol.mlx.win, 17, 1L << 17, clean_exit, &fractol);
	mlx_loop(fractol.mlx.mlx);
	return 0;
}
