#include "fractol.h"

void	algebaic_init(t_algebraic *fractol, char type)
{
	fractol->max_iter = 255;
	fractol->type = type;
	fractol->color_shift = 0;
	fractol->draw_a[0] = &mandelbrot;
	fractol->draw_a[1] = &julia;
	fractol->draw_a[2] = &burning;
	fractol->img_size = ft_min(WIDTH, HEIGHT); // размер реального поля вывода фрактала
	fractol->min.re = -2.0; //
	fractol->min.im = -2.0; // координаты левого верхнего угла поля вывода
	fractol->max.re = 2.0;
	fractol->max.im = 2.0;
	fractol->power = 2;
	fractol->size = fractol->max.re - fractol->min.re; // размер поля вывода
	fractol->c = complex_init(-0.55, -0.55);
	fractol->motion_on = 0;
}
