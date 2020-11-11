/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:25:21 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:25:23 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		print_text_a2(void *m, void *w)
{
	mlx_string_put(m, w, 10, 25 * 15, 0, "* NUM 4 to draw Butterfly;");
	mlx_string_put(m, w, 10, 26 * 15, 0, "* NUM 5 to draw Circle;");
	mlx_string_put(m, w, 10, 27 * 15, 0, "* NUM 6 to draw Graffiti;");
	mlx_string_put(m, w, 10, 28 * 15, 0, "* NUM 7 to draw Batman;");
	mlx_string_put(m, w, 10, 29 * 15, 0, "* NUM 8 to draw Buddha;");
	mlx_string_put(m, w, 10, 30 * 15, 0, "* NUM 9 to draw Abuddha;");
}

static void		print_text_a(void *m, void *w)
{
	mlx_string_put(m, w, 10, 15, 0x990000, "Algebraic usage:");
	mlx_string_put(m, w, 10, 3 * 15, 0, "* Arrows to move;");
	mlx_string_put(m, w, 10, 4 * 15, 0, "* Main \"-\" and \"+\" to");
	mlx_string_put(m, w, 10, 5 * 15, 0, "change iteration's count;");
	mlx_string_put(m, w, 10, 6 * 15, 0, "* NUM \"-\" and \"+\" to");
	mlx_string_put(m, w, 10, 7 * 15, 0, "change power;");
	mlx_string_put(m, w, 10, 8 * 15, 0, "* Scroll mouse to zoom;");
	mlx_string_put(m, w, 10, 9 * 15, 0, "* Space to reset;");
	mlx_string_put(m, w, 10, 10 * 15, 0, "* C to change color-schema;");
	mlx_string_put(m, w, 10, 11 * 15, 0, "* I to open/close info;");
	mlx_string_put(m, w, 10, 12 * 15, 0, "* 1 to draw Mandelbrot;");
	mlx_string_put(m, w, 10, 13 * 15, 0, "* 2 to draw Julia;");
	mlx_string_put(m, w, 10, 14 * 15, 0, "* P to start/stop Julia;");
	mlx_string_put(m, w, 10, 15 * 15, 0, "* 3 to draw Burning ship;");
	mlx_string_put(m, w, 10, 16 * 15, 0, "* 4 to draw Antoshka;");
	mlx_string_put(m, w, 10, 17 * 15, 0, "* 5 to draw Trident;");
	mlx_string_put(m, w, 10, 18 * 15, 0, "* 6 to draw Turtle;");
	mlx_string_put(m, w, 10, 19 * 15, 0, "* 7 to draw Ring;");
	mlx_string_put(m, w, 10, 20 * 15, 0, "* 8 to draw Cactus;");
	mlx_string_put(m, w, 10, 21 * 15, 0, "* 9 to draw Leaf;");
	mlx_string_put(m, w, 10, 22 * 15, 0, "* NUM 1 to draw Peacock;");
	mlx_string_put(m, w, 10, 23 * 15, 0, "* NUM 2 to draw Newton;");
	mlx_string_put(m, w, 10, 24 * 15, 0, "* NUM 3 to draw Web;");
	print_text_a2(m, w);
}

void			help_a(t_mlx *mlx)
{
	int		width;

	width = (int)(WIDTH - ft_min(WIDTH, HEIGHT)) / 2;
	if (!mlx->help.ptr)
	{
		mlx->help = create_img(mlx, width, HEIGHT);
		colorize(mlx->help.img, width, HEIGHT, GREY);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win,\
	mlx->help.ptr, 0, 0);
	print_text_a(mlx->mlx, mlx->win);
}

void			help_handler(int key, t_fractol *fractol)
{
	if (key == MAIN_I && fractol->help && fractol->a.type < 16)
	{
		fractol->help = 0;
		mlx_destroy_image(fractol->mlx.mlx, fractol->mlx.help.ptr);
		fractol->mlx.help.ptr = NULL;
	}
	else if (key == MAIN_I && !fractol->help && fractol->a.type < 16)
	{
		fractol->help = 1;
		fractol->type ? help_g(&fractol->mlx) : help_a(&fractol->mlx);
	}
}
