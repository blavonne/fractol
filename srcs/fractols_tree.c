#include "fractol.h"

/*
** http://rosant.ru/index.php/fractal/14-science/80-fractal?showall=&start=3
*/

void	Matr(t_complex start, t_complex params, t_fractol *fractol, int power)
{
	int			i;
	t_point		start_s;
	t_point		end_s;
	t_complex	tmp;

	i = 0;
	start_s = complex_to_screen(start, fractol->g.size, fractol->g.min,\
	point_init(HEIGHT / 4, 0));
	while (i <= 2 * fractol->g.bough_count)
	{
		fractol->g.top = complex_init(start.re + cos(params.re + i *\
		fractol->g.bough_angle) * params.im, start.im + sin(params.re + i *\
		fractol->g.bough_angle) * params.im);
		end_s = complex_to_screen(fractol->g.top, fractol->g.size,\
		fractol->g.min, point_init(HEIGHT / 4, 0));
		draw_line(start_s, end_s, fractol);
		if (power > 0)
		{
			tmp = complex_init(params.re + (i - 1) * fractol->g.bough_angle,\
			params.im / 2);
			Matr(fractol->g.top, tmp, fractol, power - 1);
		}
		i += fractol->g.bough_count;
	}
}

void	tree(t_fractol *fractol)
{
	t_complex	params;

	params = complex_init(0.6, 0.5);
	draw_line(complex_to_screen((t_complex){.re = 0, .im = -1},\
	fractol->g.size, fractol->g.min, point_init(HEIGHT / 4, 0)),\
	complex_to_screen((t_complex){.re = 0, .im = -0.1}, fractol->g.size,\
	fractol->g.min, point_init(HEIGHT / 4, 0)), fractol);
	Matr((t_complex){.re = 0,.im = -0.1}, params, fractol, fractol->g.power);
	put_img_to_window_g(&fractol->mlx, 0, 0);
	fractol->help ? help_g(&fractol->mlx) : 0;
}
