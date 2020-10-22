#include "fractol.h"

int			iter_count(t_fractol *fractol, t_complex z, t_complex c)
{
	int		iter;

	iter = 0;
	while (iter < fractol->a.max_iter)
	{
		iter++;
		z = complex_square(z);
		z = complex_sum(z, c);
		if (z.re * z.re + z.im * z.im > 4)
			break ;
	}
	return (iter);
}

//void		mandel_my(t_fractol *fractol)
//{
//	t_point		cur;
//	t_complex	c;
//	t_complex	z;
//	double		step;
//
//	cur = point_init(0, 0);
//	c = complex_init(0+fractol->a.min.re, 0+fractol->a.min.im);
//	step = fractol->a.size / fractol->a.img_size;
//	while (cur.y < fractol->a.img_size)
//	{
//		cur.x = 0;
//		c.re = fractol->a.min.re;
//		while (cur.x < fractol->a.img_size)
//		{
//			z = complex_init(0, 0);
//			color_init(cur, iter_count(fractol, z, c), fractol);
//			cur.x++;
//			c.re += step;
//		}
//		cur.y++;
//		c.im += step;
//	}
//	put_img_to_window_a(&fractol->mlx, 0, 0);
//	fractol->help ? help_a(&fractol->mlx) : 0;
//}

void		mandelbrot(void *data)
{
	t_thread	*info;
	t_point		cur;
	t_complex	c;
	t_complex	z;
	double		step;

	info = data;
	cur = point_init(0, info->start);
	step = info->fractol->a.size / info->fractol->a.img_size;
	c = complex_init(info->fractol->a.min.re, info->fractol->a.min.im +\
	info->start * step);
	while (cur.y < info->finish)
	{
		cur.x = 0;
		c.re = info->fractol->a.min.re;
		while (cur.x < info->fractol->a.img_size)
		{
			z = complex_init(0, 0);
			color_init(cur, iter_count(info->fractol, z, c), info->fractol);
			cur.x++;
			c.re += step;
		}
		cur.y++;
		c.im += step;
	}
}
