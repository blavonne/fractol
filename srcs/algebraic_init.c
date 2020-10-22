#include "fractol.h"

void	algebaic_init(t_algebraic *fractol, char type)
{
	fractol->max_iter = 255;
	fractol->color_shift = 0;
	fractol->type = type;
	fractol->draw_a[0] = &mandelbrot;
	fractol->draw_a[1] = &julia;
	fractol->draw_a[2] = &burning;
	fractol->img_size = ft_min(WIDTH, HEIGHT); // размер реального поля вывода фрактала
	fractol->min.re = -2.0; //
	fractol->min.im = -2.0; // координаты левого верхнего угла поля вывода
	fractol->max.re = 2.0;
	fractol->max.im = 2.0;
	fractol->size = fractol->max.re - fractol->min.re; // размер поля вывода
	fractol->c = complex_init(1, 1);
}

void	restore_to_default_a(t_fractol *fractol)
{
	fractol->a.max_iter = 255;
	fractol->a.color_shift = 0;
	fractol->a.min.re = -2.0; //
	fractol->a.min.im = -2.0; // координаты левого верхнего угла поля вывода
	fractol->a.size = 4.0; // размер поля вывода
	ft_memset(fractol->mlx.image.img, 255, fractol->a.img_size *\
	fractol->a.img_size * sizeof(int));
}
