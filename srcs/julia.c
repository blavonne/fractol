#include "fractol.h"

void	julia(void *info)
{
	t_fractol	*fractol;
	t_point		cur;
	t_complex	z;
	int			iter;
	double		tmp;

	fractol = info;
	cur = point_init(0, 0);
	z = complex_init(-1, -1);
	ft_bzero(fractol->mlx.image.img, fractol->a.img_size * fractol->a.img_size *
	sizeof(int));
	while (cur.y < fractol->a.img_size)
	{
		cur.x = 0;
		while (cur.x < fractol->a.img_size)
		{
			iter = 0;
			while (pow(z.re, 2) + pow(z.im, 2) < 4 && iter < fractol->a.max_iter)
			{
				tmp = z.re;
				z.re = pow(z.re, 2) - pow(z.im, 2) + fractol->a.c.re;
				z.im = (2 * z.im) * tmp + fractol->a.c.im;
				iter++;
			}
//			iter = iter_count2(fractol, &z, fractol->a.c);
			color_init(cur, iter, fractol);
			cur.x++;
		}
		cur.y++;
	}
	put_img_to_window_a(&fractol->mlx, 0, 0);
	fractol->help ? help_a(&fractol->mlx) : 0;
}

//while (FT_SQUARE(zr) + FT_SQUARE(zi) < 4 \
//			&& fractol->fractal.depth < fractol->fractal.iteration)
//{
//tmp_zr = zr;
//zr = FT_SQUARE(zr) - FT_SQUARE(zi) + cr;
//zi = (2 * zi) * tmp_zr + ci;
//fractol->fractal.depth += 1;
//}
