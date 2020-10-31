#include "fractol.h"

static char	set_schema(char type)
{
	printf("set_schema type %d\n", type);//del
	if (type >= 0 && type <= 2)
		return (type);
	else if ((type >= 3 && type <= 6) || type == 10)
		return (2);
	else if (type == 7)
		return (3);
	else if (type == 8)
		return (4);
	else if (type == 9)
		return (5);
	return (0);
}

void		algebaic_init(t_algebraic *fractol, char type)
{
	fractol->max_iter = 255;
	fractol->type = type;
	fractol->color_schema = set_schema(type);
	fractol->draw_a[0] = &mandelbrot;
	fractol->draw_a[1] = &julia;
	fractol->draw_a[2] = &burning;
	fractol->draw_a[3] = &antoshka;
	fractol->draw_a[4] = &trident;
	fractol->draw_a[5] = &turtle;
	fractol->draw_a[6] = &ring_ring;
	fractol->draw_a[7] = &cactus;
	fractol->draw_a[8] = &leaf;
	fractol->draw_a[9] = &peacock;
	fractol->draw_a[10] = &newton;
	fractol->draw_a[11] = &web;
	fractol->draw_a[12] = &web2;
	fractol->draw_a[13] = &graffiti;
	fractol->draw_a[14] = &circle;
	fractol->draw_a[15] = &batman;
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
