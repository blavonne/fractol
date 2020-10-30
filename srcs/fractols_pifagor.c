#include "fractol.h"

void		calc_vertex(t_complex *vertex, double q)
{
	vertex[2] = complex_init(vertex[0].re + vertex[0].im - vertex[1].im,\
	vertex[0].im + vertex[1].re - vertex[0].re);//C

	vertex[3] = complex_init(vertex[1].re + vertex[0].im - vertex[1].im,\
	vertex[1].im + vertex[1].re - vertex[0].re);//D

	vertex[4] = complex_init((vertex[2].re + vertex[3].re * pow(q, 2) +\
	(vertex[2].im - vertex[3].im) * q) / (1 + pow(q, 2)), (vertex[2].im +\
	vertex[3].im * pow(q, 2) + ((vertex[3].re - vertex[2].re) * q)) / (1 +\
	pow(q, 2)));//E
}

void		connect_vertex(t_complex *vertex, t_fractol *fractol)
{
	t_point		start;
	t_point		end;

	start = complex_to_screen(vertex[0], fractol->g.size, fractol->g.min,\
	point_init(HEIGHT / 4, 0));//A
	end = complex_to_screen(vertex[1], fractol->g.size, fractol->g.min,\
	point_init(HEIGHT / 4, 0));//B
	draw_line(start, end, fractol);//AB
	end = complex_to_screen(vertex[2], fractol->g.size, fractol->g.min,\
	point_init(HEIGHT / 4, 0));//C
	draw_line(start, end, fractol);//AC
	start = end;//C
	end = complex_to_screen(vertex[3], fractol->g.size, fractol->g.min,\
	point_init(HEIGHT / 4, 0));//D
	draw_line(start, end, fractol);//CD
	end = complex_to_screen(vertex[4], fractol->g.size, fractol->g.min,\
	point_init(HEIGHT / 4, 0));//E
	draw_line(start, end, fractol);//CE
	start = end;//E
	end = complex_to_screen(vertex[3], fractol->g.size, fractol->g.min,\
	point_init(HEIGHT / 4, 0));//D
	draw_line(start, end, fractol);//ED
	start = end;//D
	end = complex_to_screen(vertex[1], fractol->g.size, fractol->g.min,\
	point_init(HEIGHT / 4, 0));//B
	draw_line(start, end, fractol);//DB
}

void		draw_pif(t_complex *base, t_fractol *fractol, t_complex *vertex,\
		int n)
{
	t_complex	tmp[5];

	vertex[0] = base[0];
	vertex[1] = base[1];
	calc_vertex(vertex, fractol->g.bough_angle);
	ft_memcpy(tmp, vertex, sizeof(t_complex) * 5);
	connect_vertex(tmp, fractol);
	if (n > 0)
	{
		base[0] = vertex[2];
		base[1] = vertex[4];
		draw_pif(base, fractol, tmp, n - 1);
		base[0] = vertex[4];
		base[1] = vertex[3];
		draw_pif(base, fractol, tmp, n - 1);
	}
}

void		pifagor(t_fractol *fractol)
{
	t_complex	vertex[5];
	t_complex	base[2];
	int			n;

	n = fractol->g.power;
	fractol->g.bough_angle = 1;
	fractol->g.size = complex_init(fractol->g.max.re - fractol->g.min.re,\
	fractol->g.max.im - fractol->g.min.im);
	base[0] = complex_init(-0.15, -0.5);//A
	base[1] = complex_init(0.15, -0.5);//B
	draw_pif(base, fractol, vertex, n);
	put_img_to_window_g(&fractol->mlx, 0, 0);
	fractol->help ? help_g(&fractol->mlx) : 0;
}