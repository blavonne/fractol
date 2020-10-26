#include "fractol.h"

void	win_destroy(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
}

void	mlx_destroy(t_mlx *mlx)
{
	free(mlx->mlx);
}

void	img_destroy(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->image.ptr);
	mlx_destroy_image(mlx->mlx, mlx->background.ptr);
}

void	destroy_fractol(t_fractol *fractol)
{
	img_destroy(&fractol->mlx);
	win_destroy(&fractol->mlx);
	mlx_destroy(&fractol->mlx);
	if (fractol->type)
		clean_knot(fractol);
}

void			clean_knot(t_fractol *fractol)
{
	free(fractol->g.kn);
	fractol->g.kn = NULL;
}

int				clean_exit(void *param)
{
	destroy_fractol((t_fractol *)param);
	exit(0);
}
