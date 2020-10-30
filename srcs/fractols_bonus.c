#include "fractol.h"

int			antoshka(t_fractol *fractol, t_complex c)
{
	int			iter;
	t_complex	z;
	double		r;

	iter = 0;
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
	return (iter);
}

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

int			ring_ring(t_fractol *fractol, t_complex c)//ring_ring
{
	int			iter;
	t_complex	z;
	double		r;

	iter = 0;
	z = complex_init(0, 0);
	while (iter < fractol->a.max_iter)
	{
		iter++;
		z = complex_sum(z, c);
		z = complex_power(z, fractol->a.power);
		z = complex_derivative(z, fractol->a.power + 1);
		z = complex_tg(z);
		r = z.re * z.re + z.im * z.im;
		if (r > 4)
			break ;
	}
	return (iter);
}

int			cactus(t_fractol *fractol, t_complex c)//cactus
{
	int			iter;
	t_complex	z;
	double		r;

	iter = 0;
	z = complex_init(2, 0);
	while (iter < fractol->a.max_iter)
	{
		iter++;
		z = complex_power(z, fractol->a.power);
		z = complex_sum(z, c);
		z = complex_derivative(complex_div(z, c), fractol->a.power + 1);
		r = z.re * z.re + z.im * z.im;
		if (r > 100)
			break ;
	}
	return (iter);
}

int			leaf(t_fractol *fractol, t_complex c)//leaf
{
	int			iter;
	t_complex	z;
	double		r;

	iter = 0;
	z = fractol->a.c;
	while (iter < fractol->a.max_iter)
	{
		iter++;
		z = complex_power(z, fractol->a.power - 1);
		z = complex_cos(z);
		z = complex_div(z, c);
		r = z.re * z.re + z.im * z.im;
		if (r > 1000)
			break ;
	}
	return (iter);
}

int			peacock(t_fractol *fractol, t_complex c)//peacock
{
	int			iter;
	t_complex	z;
	double		r;

	iter = 0;
	z =  complex_init(0 ,0);
	while (iter < fractol->a.max_iter)
	{
		iter++;
		z = complex_power(z, fractol->a.power);
		z = complex_sin(complex_div(z, c));
		z = complex_sum(z, c);
		r = z.re * z.re + z.im * z.im;
		if (r > 4)
			break ;
	}
	return (iter);
}

/*
** Classic newton should have
** power.re = -power.re;
** power.im = -power.im;
** instead of
** power = complex_multiply(power, (t_complex){.re = -1, .im = -1});
*/

int			newton(t_fractol *fractol, t_complex c)
{
	int			iter;
	t_complex	z;
	t_complex	der;
	t_complex	power;
	double		r;

	iter = 0;
	z = c;
	while (iter < fractol->a.max_iter)
	{
		iter++;
		power = complex_power(z, fractol->a.power + 1);
		power.re -= 1;
		der = complex_derivative(z, fractol->a.power + 1);
		power = complex_div(power, der);
		power = complex_multiply(power, (t_complex){.re = -1, .im = -1});
		z = complex_sum(z, power);
		r = z.re * z.re + z.im * z.im;
		if (r > 200)
			break ;
	}
	return (iter);
}