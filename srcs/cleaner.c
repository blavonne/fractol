#include "fractol.h"

static void	img_destroy(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->image.ptr);
	mlx_destroy_image(mlx->mlx, mlx->background.ptr);
	if (mlx->help.ptr)
		mlx_destroy_image(mlx->mlx, mlx->help.ptr);
}

static void	clean_knot(t_fractol *fractol)
{
	free(fractol->g.kn);
	fractol->g.kn = NULL;
}

static void	destroy_fractol(t_fractol *fractol)
{
	img_destroy(&fractol->mlx);
	mlx_destroy_window(fractol->mlx.mlx, fractol->mlx.win);
	mlx_destroy_display(fractol->mlx.mlx);
	if (fractol->type)
		clean_knot(fractol);
}

int			clean_exit(void *param)
{
	destroy_fractol((t_fractol *)param);
	exit(0);
}
