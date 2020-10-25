#include "graphics_base.h"

t_complex	complex_init(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

t_complex	not_random()
{
	t_complex	c;

	c.re = (double)rand() / (double)RAND_MAX * 4 - 2;
	c.im = (double)rand() / (double)RAND_MAX * 4 - 2;
	return (c);
}
