#include "graphics_base.h"

t_complex	complex_init(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

t_complex	complex_square(t_complex z)
{
	double	a;

	a = z.re * z.re - z.im * z.im;
	z.im = 2 * z.re * z.im;
	z.re = a;
	return (z);
}

t_complex	complex_sum(t_complex z, t_complex c)
{
	t_complex	sum;

	sum.re = z.re + c.re;
	sum.im = z.im + c.im;
	return (sum);
}

t_complex	complex_square_abs(t_complex z)
{
	double	a;

	a = fabs(z.re * z.re - z.im * z.im);
	z.im = fabs(2 * z.re * z.im);
	z.re = a;
	return (z);
}

t_complex	complex_sum_abs(t_complex z, t_complex c)
{
	t_complex	sum;

	sum.re = fabs(z.re + c.re);
	sum.im = fabs(z.im + c.im);
	return (sum);
}