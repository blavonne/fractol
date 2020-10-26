#include "graphics_base.h"

t_complex	complex_sum(t_complex z, t_complex c)
{
	t_complex	sum;

	sum.re = z.re + c.re;
	sum.im = z.im + c.im;
	return (sum);
}

t_complex	complex_sum_abs(t_complex z, t_complex c)
{
	double	t;

	t = fabs(z.re + c.re);
	z.im = fabs(z.im + c.im);
	z.re = t;
	return (z);
}

t_complex	abs_pow_sum(t_complex z, t_complex c, int power)
{
	double	t;

	z = complex_power(z, power);
	t = fabs(z.re + c.re);
	z.im = fabs(z.im + c.im);
	z.re = t;
	return (z);
}

t_complex	complex_multiply(t_complex a, t_complex b)
{
	t_complex	res;

	res.re = a.re * b.re - a.im * b.im;
	res.im = a.re * b.im + a.im * b.re;
	return (res);
}

t_complex	complex_power(t_complex z, int power)
{
	t_complex	tmp;
	int			i;

	tmp = z;
	i = 1;
	while (i++ < power)
		z = complex_multiply(z, tmp);
	return (z);
}

t_complex	complex_div(t_complex z1, t_complex z2)
{
	t_complex	division;

	division.re = (z1.re * z2.re + z1.im * z2.im) / (pow(z2.re, 2) +\
	pow(z2.im, 2));
	division.im = (z2.re * z1.im - z1.re * z2.im) / (pow(z2.re, 2) +\
	pow(z2.im, 2));
	return (division);
}

t_complex	complex_sin(t_complex z)
{
	t_complex	res;

	res.re = sin(z.re) * cosh(z.im);
	res.re = cos(z.re) * sinh(z.im);
	return (res);
}

t_complex	complex_cos(t_complex z)
{
	t_complex	res;

	res.re = cos(z.re) * cosh(z.im);
	res.im = -sin(z.re) * sinh(z.im);
	return (res);
}

t_complex	complex_tg(t_complex z)
{
	t_complex	res;

	res = complex_div(complex_sin(z), complex_cos(z));
	return (res);
}