#include "fractol.h"

int			mandelbrot(t_fractol *fractol, t_complex c)
{
	int			iter;
	t_complex	z;
	double		r;

	iter = 0;
	z = complex_init(0, 0);
	while (iter < fractol->a.max_iter)
	{
		iter++;
		z = complex_power(z, fractol->a.power);
		z = complex_sum(z, c);
		r = z.re * z.re + z.im * z.im;
		if (r > 4)
			break ;
	}
	return (iter);
}

int			julia_motion(int x, int y, t_fractol *fractol)
{
	t_complex	min;

	if (fractol->a.motion_on && fractol->a.type == 1)
	{
		min = fractol->a.min;
		x = x - (WIDTH - fractol->a.img_size) / 2;
		y = y - (HEIGHT - fractol->a.img_size) / 2;
		if (x >= 0 && y >= 0 && x < fractol->a.img_size && y\
		< fractol->a.img_size)
		{
			fractol->a.c.re = x * fractol->a.size / fractol->a.img_size\
			+ min.re;
			fractol->a.c.im = y * fractol->a.size / fractol->a.img_size\
			+ min.im;
		}
		rendering(fractol);
	}
	return (0);
}

int			julia(t_fractol *fractol, t_complex z)
{
	double			r;
	int				iter;

	iter = 0;
	while (iter < fractol->a.max_iter)
	{
		z = complex_power(z, fractol->a.power);
		z = complex_sum(z, fractol->a.c);
		r = z.re * z.re + z.im * z.im;
		if (r > 4)
			break ;
		iter++;
	}
	return (iter);
}

int			burning(t_fractol *fractol, t_complex c)
{
	int			iter;
	t_complex	z;
	double		r;

	iter = 0;
	z = complex_init(0, 0);
	while (iter < fractol->a.max_iter)
	{
		iter++;
		z = complex_power(z, fractol->a.power);
		z = complex_sum_abs(z, c);
		r = z.re * z.re + z.im * z.im;
		if (r > 4)
			break ;
	}
	return (iter);
}

/*
		z = complex_tg(complex_div(z, c));
		z = complex_sum(z, c);
		кельтский знак
		z = complex_cos(complex_div(z, c));
		z = complex_sum(z, c);
		череп
		z = complex_cos(z);
		z = complex_div(z, c);
		остроугольный клевер (!)
		*******
	z = complex_init(3, 0);
	while (iter < fractol->a.max_iter)
	{
		iter++;
		z = complex_power(z, fractol->a.power);
		z = complex_tg(complex_multiply(c, z));
		z = complex_div(z, c);
		r = z.re * z.re + z.im * z.im;
		if (r > 200)
			break ;
	}
	Антошка power = 4
 */

//z = complex_init(0, 0);
//while (iter < fractol->a.max_iter)
//{
//iter++;
//z = complex_sum(z, c);
//z = complex_div(z, complex_derivative(z, fractol->a.power + 1));
//z = complex_cos(z);
//r = z.re * z.re + z.im * z.im;
//if (r > 4)
//break ;
//}
//какие-то цветочки