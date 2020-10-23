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
		z = abs_pow_sum(z, c, fractol->a.power);
		r = z.re * z.re + z.im * z.im;
		if (r > 4)
			break ;
	}
	return (iter);
}
