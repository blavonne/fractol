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

int			batman(t_fractol *fractol, t_complex c)
{
	int			iter;
	t_complex	z;
	t_complex	tmp;
	t_complex	tmp2;
	double		r;

	iter = 0;
	z = c;
	while (iter < fractol->a.max_iter)
	{
		iter++;
		z = complex_power(z, 5);
		tmp = complex_sin(z);
		tmp2 = tmp;
		tmp.re -= 1;
		tmp2.re = -tmp2.re;
		tmp2.im = -tmp2.im;
		tmp2 = complex_sum(complex_multiply(z, complex_cos(z)), tmp2);
		tmp2.re += 1;
		z = complex_div(tmp2, complex_cos(z));
		z = complex_sum(z, c);
		r = z.re * z.re + z.im * z.im;
		if (r > 4 || r == 1. / 0. || r == 0. / 0.)
			break ;
	}
	return (iter);
}

int			butterfly(t_fractol *fractol, t_complex c)
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
		power.re = -power.re;
		power.im = -power.im;
		z = complex_sum(z, power);
		z = complex_div(z, (t_complex){.re = M_PI_2, .im = M_PI});
		z = complex_sin(z);
		r = z.re * z.re + z.im * z.im;
		if (r > 500 || r == 1. / 0. || r == 0. / 0.)
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

int			circle(t_fractol *fractol, t_complex c)
{
	int			iter;
	t_complex	z;
	t_complex	tmp;
	t_complex	der;
	double		r;

	iter = 0;
	z = c;
	while (iter < fractol->a.max_iter)
	{
		iter++;
		z = complex_power(z, 4);
		tmp = complex_sin(z);
		tmp.re -= 1;
		der = complex_cos(z);
		der = complex_div(tmp, der);
		der.re = -der.re;
		der.im = -der.im;
		z = complex_sum(z, der);
		r = z.re * z.re + z.im * z.im;
		if (r > 200 || r == 1. / 0. || r == 0. / 0.)
			break ;
	}
	return (iter);
}
