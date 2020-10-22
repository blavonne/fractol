#include "fractol.h"

static void			traf(t_complex start, t_complex end, t_geometric *g, int r)
{
	if (r > g->size - 1)
		geometric_resize(g);
	g->kn[r].re = start.re;
	g->kn[r].im = start.im;
	if (r + 1 > g->size - 1)
		geometric_resize(g);
	g->kn[r + 1].re = (2 * start.re + end.re) / 3;
	g->kn[r + 1].im = (2 * start.im + end.im) / 3;
	if (r + 2 > g->size - 1)
		geometric_resize(g);
	g->kn[r + 2].re = (start.re + end.re) / 2 + (start.im - end.im) / (2 *\
	sqrt(3.0));
	g->kn[r + 2].im = (end.im + start.im) / 2 + (end.re - start.re) / (2 *\
	sqrt(3.0));
	if (r + 3 > g->size - 1)
		geometric_resize(g);
	g->kn[r + 3].re =  (start.re + 2 * end.re) / 3;
	g->kn[r + 3].im = (start.im + 2 * end.im) / 3;
	if (r + 4 > g->size - 1)
		geometric_resize(g);
	g->kn[r + 4].re = end.re;
	g->kn[r + 4].im = end.im;
}

static void		set_coords(t_point *begin, t_point *end, int i, t_geometric *g)
{
	begin->x = (int)round(g->kn[i].re * g->scale) + g->offset.x;
	begin->y = (int)round(g->kn[i].im * g->scale) + g->offset.y;
	end->x = (int)round(g->kn[i + 1].re * g->scale) + g->offset.x;
	end->y = (int)round(g->kn[i + 1].im * g->scale) + g->offset.y;
}

static void		fract_koch(t_fractol *fractol, t_complex *coord, t_complex *kn,\
		int *m)
{
	while (m[0] < fractol->g.n)
	{
		m[2] = pow(4.0, m[0] + 1);
		m[1] = 0;
		while (m[1] <= m[2])
		{
			kn[m[1]] = fractol->g.kn[m[1]];
			m[1]++;
		}
		m[1] = 0;
		while (m[1] < m[2])
		{
			coord[0] = kn[m[1]];
			coord[1] = kn[m[1] + 1];
			traf(coord[0], coord[1], &fractol->g, m[1] * 4);
			m[1]++;
		}
		m[0]++;
	}
}

/*
** http://rosant.ru/index.php/fractal/14-science/80-fractal?showall=&start=1
*/

void			create_koch(t_fractol *fractol)
{
	t_complex	coord[2];
	t_point		point[2];
	t_complex	kn[4096];
	int			m[3];

	ft_bzero(m, sizeof(int) * 3);
	coord[0].re = 0.0;
	coord[0].im = -(double)HEIGHT / 2 - 1;
	coord[1].re = (double)WIDTH - 1;
	coord[1].im = -(double)HEIGHT / 2 - 1;
	traf(coord[0], coord[1], &fractol->g, 0);
	fract_koch(fractol, coord, kn, m);
	m[1] = 0;
	while (m[1] < 4 * m[2] || (!fractol->g.n && m[1] < 4))
	{
		set_coords(&point[0], &point[1], m[1], &fractol->g);
		draw_line(point[0], point[1], fractol);
		m[1]++;
	}
	put_img_to_window_g(&fractol->mlx, 0, 0);
	fractol->help ? help_g(&fractol->mlx) : 0;
}

static void		fract_snow(t_fractol *fractol, t_complex *coord, t_complex *kn,\
		int *m)
{
	while (m[0] < fractol->g.n)
	{
		m[2] = 3 * pow(4.0, m[0] + 1);
		m[1] = 0;
		while (m[1] <= m[2])
		{
			kn[m[1]] = fractol->g.kn[m[1]];
			m[1]++;
		}
		m[1] = 0;
		while (m[1] < m[2])
		{
			traf(kn[m[1]], kn[m[1] + 1], &fractol->g, 4 * m[1]);
			m[1]++;
		}
		m[0]++;
	}
}

void			create_snow(t_fractol *fractol)
{
	t_complex	coord[3];
	t_point		point[2];
	t_complex	kn[4096];
	int			m[3];

	ft_bzero(m, sizeof(int) * 3);
	coord[0].re = (double)0 + 380;
	coord[0].im = -(double)HEIGHT / 2 - 240;
	coord[1].re = (double)WIDTH - 380;
	coord[1].im = -(double)HEIGHT / 2 - 240;
	coord[2].re = (coord[1].re + coord[0].re) / 2 +\
			(coord[0].im - coord[1].im) * sqrt(3.0) / 2;
	coord[2].im = (coord[1].im + coord[0].im) / 2 +\
			(coord[1].re - coord[0].re) * sqrt(3.0) / 2;
	traf(coord[1], coord[0], &fractol->g, 0);
	traf(coord[0], coord[2], &fractol->g, 4);
	traf(coord[2], coord[1], &fractol->g, 8);
	fract_snow(fractol, coord, kn, m);
	m[1] = 0;
	while (m[1] < 4 * m[2] || (!fractol->g.n && m[1] < 12))
	{
		set_coords(&point[0], &point[1], m[1], &fractol->g);
		draw_line(point[0], point[1], fractol);
		m[1]++;
	}
	put_img_to_window_g(&fractol->mlx, 0, 0);
	fractol->help ? help_g(&fractol->mlx) : 0;
}