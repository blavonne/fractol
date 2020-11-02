/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:43:38 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:43:46 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				zoom_g(t_fractol *fractol, int key)
{
	if (fractol->g.power < 11 && fractol->g.power > -1)
	{
		ft_memset(fractol->mlx.image.img, 255, WIDTH * HEIGHT * sizeof(int));
		if (key == MAIN_PLUS)
		{
			if (fractol->g.power < 5 && fractol->g.type < 2)
				fractol->g.power++;
			else if (fractol->g.power < 8 && fractol->g.type == 2)
				fractol->g.power++;
			else if (fractol->g.power < 10 && fractol->g.type == 3)
				fractol->g.power++;
		}
		else if (key == MAIN_MINUS && fractol->g.power > 0)
			fractol->g.power--;
	}
}

static t_complex	view_shift(int x, int y, t_fractol *fractol)
{
	t_complex	cursor;

	x = x - (WIDTH - fractol->a.img_size) / 2;
	y = y - (HEIGHT - fractol->a.img_size) / 2;
	cursor.re = fractol->a.min.re + x * fractol->a.size / fractol->a.img_size;
	cursor.im = fractol->a.min.im + y * fractol->a.size / fractol->a.img_size;
	return (cursor);
}

/*
** cur means cursor
*/

int					zoom_a(int key, int x, int y, t_fractol *fractol)
{
	t_complex	cur;

	if (!fractol->type && fractol->a.type < 16)
	{
		if (x < (WIDTH - fractol->a.img_size) / 2 || x > (WIDTH +\
			fractol->a.img_size) / 2)
			return (0);
		cur = view_shift(x, y, fractol);
		if (key == MOUSE_SCROLL_DOWN)
		{
			fractol->a.min.re = cur.re + (fractol->a.min.re - cur.re) * SCALE;
			fractol->a.min.im = cur.im + (fractol->a.min.im - cur.im) * SCALE;
			fractol->a.size *= SCALE;
			fractol->a.max_iter + 10 > 0 ? fractol->a.max_iter += 10 : 0;
		}
		if (key == MOUSE_SCROLL_UP)
		{
			fractol->a.min.re = cur.re + (fractol->a.min.re - cur.re) / SCALE;
			fractol->a.min.im = cur.im + (fractol->a.min.im - cur.im) / SCALE;
			fractol->a.size /= SCALE;
			fractol->a.max_iter - 10 > 0 ? fractol->a.max_iter -= 10 : 0;
		}
		rendering(fractol);
	}
	return (0);
}
