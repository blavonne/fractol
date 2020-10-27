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
		z = complex_power(z, fractol->a.power);
		z = complex_sum_abs(z, c);
		r = z.re * z.re + z.im * z.im;
		if (r > 4)
			break ;
	}
	return (iter);
}

//int			antoshka(t_fractol *fractol, t_complex c)
//{
//	int			iter;
//	t_complex	z;
//	double		r;
//
//	iter = 0;
//	z = complex_init(3, 0);
//	while (iter < fractol->a.max_iter)
//	{
//		iter++;
//		z = complex_power(z, fractol->a.power);
//		z = complex_tg(complex_multiply(c, z));
//		z = complex_div(z, c);
//		r = z.re * z.re + z.im * z.im;
//		if (r > 200)
//			break ;
//	}
//	return (iter);
//}

int			antoshka(t_fractol *fractol, t_complex c)
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
		complex_sin(complex_tg(z)), fractol->a.power + 1), fractol->a.power +
				2));
//		z = complex_multiply(z, c);
		r = z.re * z.re + z.im * z.im;
		if (r > 100) //более резкий и яркий при увеличении
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