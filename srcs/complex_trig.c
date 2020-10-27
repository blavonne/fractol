#include "graphics_base.h"

t_complex	complex_sin(t_complex z)
{
	t_complex	res;

	res.re = sin(z.re) * cosh(z.im);
	res.im = -cos(z.re) * sinh(z.im);
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

t_complex	complex_derivative(t_complex z, int k)
{
	int		power;

	power = k - 1;
	z = complex_power(z, power);
	z.re = k * (z.re);
	z.im = k * (z.im);
	return (z);
}
