#include "fractol.h"

int			mandelbrot_iter(t_fractol *fractol, t_complex c)
{
	int			iter;
	t_complex	z;
	double		r;

	iter = 0;
	z = complex_init(0, 0);
	while (iter < fractol->a.max_iter)
	{
		iter++;
		z = complex_square(z);
		z = complex_sum(z, c);
		r = z.re * z.re + z.im * z.im;
		if (r > 4)
			break ;
	}
	return (iter);
}

int			julia_iter(t_fractol *fractol, t_complex z)
{
	const t_complex	c = complex_init(-0.55, -0.55);
	double			r;
	int				iter;

	iter = 0;
	while (iter < fractol->a.max_iter)
	{
		z = complex_square(z);
		z = complex_sum(z, c);
		r = z.re * z.re + z.im * z.im;
		if (r > 4)
			break ;
		iter++;
	}
	return (iter);
}
