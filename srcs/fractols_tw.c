#include "fractol.h"

int			trident(t_fractol *fractol, t_complex c)//trident
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
		z = complex_tg(complex_div(z, c));
		z = complex_sum(z, c);
		r = z.re * z.re + z.im * z.im;
		if (r > 4)
			break ;
	}
	return (iter);
}

int			turtle(t_fractol *fractol, t_complex c)//turtle
{
	int			iter;
	t_complex	z;
	double		r;

	iter = 0;
	z = complex_init(0, 1);
	while (iter < fractol->a.max_iter)
	{
		iter++;
		z = complex_sum(z, c);
		z = complex_div(z, complex_derivative(complex_derivative(\
		complex_sin(complex_tg(z)), fractol->a.power + 1),\
		fractol->a.power + 2));
		r = z.re * z.re + z.im * z.im;
		if (r > 100)
			break ;
	}
	return (iter);
}

int			web(t_fractol *fractol, t_complex c)
{
	int			iter;
	t_complex	z;
	t_complex	tmp;
	double		r;

	iter = 0;
	z = c;
	while (iter < fractol->a.max_iter)
	{
		iter++;
		z = complex_power(z, fractol->a.power + 2);
		c = complex_sin(z);
		c.re -= 1;
		tmp = complex_sin(z);
		tmp.re = -tmp.re;
		tmp.im = -tmp.im;
		tmp = complex_sum(complex_multiply(z, complex_cos(z)), tmp);
		tmp.re += 1;
		z = complex_div(tmp, complex_cos(z));
		z = complex_sin(z);
		r = z.re * z.re + z.im * z.im;
		if (r > 4 || r == 1. / 0. || r == 0. / 0.)
			break ;
	}
	return (iter);
}
