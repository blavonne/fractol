#include "fractol.h"

t_complex some;
double b = 0.35;
int r = 3;

void	Matr(t_complex start, double angle, double len, int n, t_complex size,\
		t_complex min, t_point dst, t_fractol *fractol)
{
	int		i;
	t_point	start_s;
	t_point	end_s;

	i = 0;
	start_s = complex_to_screen(start, size, min, dst);
	while (i <= 2 * r)
	{
		some.re = start.re + cos(angle + i * b) * len;
		some.im = start.im + sin(angle + i * b) * len;
		end_s = complex_to_screen(some, size, min, dst);
		printf("start(%d, %d), end(%d, %d)\n", start_s.x, start_s.y, end_s.x,\
		end_s.y);
		draw_line(start_s, end_s, fractol);
		if (n > 0)
			Matr(some, angle + (i - 1) * b, len / 2, n - 1, size, min, dst,\
			fractol);
		i += r;
	}
}

void	tree(t_fractol *fractol)
{
	t_point		start;
	t_point		end;
	t_complex	min;
	t_complex	max;
	t_complex	size;
	int			n;

	min = complex_init(-1, -1);
	max = complex_init(1, 1);
	size = complex_init(max.re - min.re, max.im - min.im);
	n = 6;

	fractol_init(fractol);
	fractol->type = 1;
	fractol->mlx.mlx = create_mlx();
	fractol->mlx.win = create_win(&fractol->mlx, WIDTH, HEIGHT, "Fractol");
	create_background(&fractol->mlx, WIDTH, HEIGHT, 0);
	fractol->mlx.image = create_img(&fractol->mlx, WIDTH, HEIGHT);
	colorize(fractol->mlx.image.img, WIDTH, HEIGHT, 0xFF000000);
	geometric_init(&fractol->g, 2);
	draw_line(complex_to_screen((t_complex){.re = 0, .im = -1}, size, min,\
	(t_point){.x = 0, .y = 0}), complex_to_screen((t_complex){.re = 0,\
	.im = -0.1}, size, min, (t_point){.x = 0, .y = 0}), fractol);
	Matr((t_complex){.re = 0,.im = -0.1}, 0.6, 0.5, n, size, min,\
	(t_point){.x = 0, .y = 0}, fractol);

//	start = point_init(800, -563);
//	end = point_init(1129, -419);
//	draw_line(start, end, fractol);
//	colorize(fractol->mlx.image.img, WIDTH, HEIGHT, DARK_GREEN);
	put_img_to_window_g(&fractol->mlx, 0, 0);
}