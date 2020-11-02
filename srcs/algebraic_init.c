/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebraic_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:47:52 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 15:52:00 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static char	set_schema(char type)
{
	if (type >= 0 && type <= 2)
		return (type);
	else if ((type >= 3 && type <= 6) || type == 10)
		return (2);
	else if (type == 7)
		return (3);
	else if (type == 8)
		return (4);
	else if (type == 9)
		return (5);
	else if (type == 11 || type == 15)
		return (6);
	else if (type == 12)
		return (7);
	else if (type == 13 || type == 14)
		return (8);
	return (0);
}

static void	set_func(t_algebraic *fractol)
{
	fractol->draw_a[0] = &mandelbrot;
	fractol->draw_a[1] = &julia;
	fractol->draw_a[2] = &burning;
	fractol->draw_a[3] = &antoshka;
	fractol->draw_a[4] = &trident;
	fractol->draw_a[5] = &turtle;
	fractol->draw_a[6] = &ring_ring;
	fractol->draw_a[7] = &cactus;
	fractol->draw_a[8] = &leaf;
	fractol->draw_a[9] = &peacock;
	fractol->draw_a[10] = &newton;
	fractol->draw_a[11] = &web;
	fractol->draw_a[12] = &butterfly;
	fractol->draw_a[13] = &graffiti;
	fractol->draw_a[14] = &circle;
	fractol->draw_a[15] = &batman;
}

void		algebaic_init(t_algebraic *fractol, char type)
{
	fractol->max_iter = 255;
	fractol->type = type;
	fractol->color_schema = set_schema(type);
	set_func(fractol);
	fractol->img_size = ft_min(WIDTH, HEIGHT);
	fractol->min.re = -2.0;
	fractol->min.im = -2.0;
	fractol->max.re = 2.0;
	fractol->max.im = 2.0;
	fractol->power = 2;
	fractol->size = fractol->max.re - fractol->min.re;
	fractol->c = complex_init(-0.55, -0.55);
	fractol->motion_on = 0;
}
