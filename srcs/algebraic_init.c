#include "fractol.h"

void	algebaic_init(t_algebraic *fractol)
{
	fractol->max_iter = 155;
	fractol->color_shift = 0;
	fractol->type = 0;
	fractol->draw_algebraic[0] = &mandelbrot;
	fractol->draw_algebraic[1] = &julia;
	fractol->img_size = ft_min(WIDTH, HEIGHT); // размер реального поля вывода фрактала
	fractol->min.re = -2.0; //
	fractol->min.im = -2.0; // координаты левого верхнего угла поля вывода
	fractol->size = 4.0; // размер поля вывода
}

void	restore_to_default_a(t_fractol *fractol)
{
	fractol->a.max_iter = 155;
	fractol->a.color_shift = 0;
	fractol->a.min.re = -2.0; //
	fractol->a.min.im = -2.0; // координаты левого верхнего угла поля вывода
	fractol->a.size = 4.0; // размер поля вывода
	ft_memset(fractol->mlx.image.img, 255, fractol->a.img_size *\
	fractol->a.img_size * sizeof(int));
}
