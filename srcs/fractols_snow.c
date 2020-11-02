/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols_snow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:17:22 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:17:24 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			fract_snow(t_fractol *fractol, t_complex *kn, int *m)
{
	while (m[0] < fractol->g.power)
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

void				snow(t_fractol *fractol)
{
	t_complex	coord[3];
	t_point		point[2];
	t_complex	kn[4096];
	int			m[3];

	ft_bzero(m, sizeof(int) * 3);
	coord[0] = complex_init((double)0 + 380, -(double)HEIGHT / 2 - 240);
	coord[1] = complex_init((double)WIDTH - 380, -(double)HEIGHT / 2 - 240);
	coord[2].re = (coord[1].re + coord[0].re) / 2 +\
	(coord[0].im - coord[1].im) * sqrt(3.0) / 2;
	coord[2].im = (coord[1].im + coord[0].im) / 2 +\
	(coord[1].re - coord[0].re) * sqrt(3.0) / 2;
	traf(coord[1], coord[0], &fractol->g, 0);
	traf(coord[0], coord[2], &fractol->g, 4);
	traf(coord[2], coord[1], &fractol->g, 8);
	fract_snow(fractol, kn, m);
	m[1] = 0;
	while (m[1] < 4 * m[2] || (!fractol->g.power && m[1] < 12))
	{
		set_coords(&point[0], &point[1], m[1], &fractol->g);
		draw_line(point[0], point[1], fractol);
		m[1]++;
	}
	put_img_to_window_g(&fractol->mlx, 0, 0);
	fractol->help ? help_g(&fractol->mlx) : 0;
}
