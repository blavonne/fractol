#include "fractol.h"

void	win_destroy(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
}

void	mlx_destroy(t_mlx *mlx)
{
	free(mlx->mlx_ptr);
}

void	img_destroy(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->image.ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->background.ptr);
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
