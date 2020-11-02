/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_g.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:27:02 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:27:03 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		print_text_g(void *m, void *w)
{
	mlx_string_put(m, w, 10, 15, 0x000099, "Geometric usage:");
	mlx_string_put(m, w, 10, 3 * 15, 0x000044, "* Arrows to move;");
	mlx_string_put(m, w, 10, 5 * 15, 0x000044, "* Main \"-\" and \"+\" to");
	mlx_string_put(m, w, 10, 7 * 15, 0x000044, "change iteration's count;");
	mlx_string_put(m, w, 10, 9 * 15, 0x000044, "* NUM \"-\" and \"+\" to");
	mlx_string_put(m, w, 10, 11 * 15, 0x000044, "switch color-change mode;");
	mlx_string_put(m, w, 10, 13 * 15, 0x880000, "* R to change red-channel;");
	mlx_string_put(m, w, 10, 15 * 15, 0x008800, "* G to change green-channel;");
	mlx_string_put(m, w, 10, 17 * 15, 0x000088, "* B to change blue-channel;");
	mlx_string_put(m, w, 10, 19 * 15, 0x000044, "* T to change transparency;");
	mlx_string_put(m, w, 10, 21 * 15, 0x000044, "* 1 to draw Koch line;");
	mlx_string_put(m, w, 10, 23 * 15, 0x000044, "* 2 to draw Koch snowflake;");
	mlx_string_put(m, w, 10, 25 * 15, 0x000044, "* 3 to draw Tree;");
	mlx_string_put(m, w, 10, 27 * 15, 0x000044, "* 4 to draw Pifagor's tree;");
	mlx_string_put(m, w, 10, 29 * 15, 0xff, "* Space to restore");
	mlx_string_put(m, w, 10, 31 * 15, 0xff, "to default;");
}

void			help_g(t_mlx *mlx)
{
	int		width;

	width = (int)(WIDTH - ft_min(WIDTH, HEIGHT)) / 2;
	if (!mlx->help.ptr)
	{
		mlx->help = create_img(mlx, width, HEIGHT);
		colorize(mlx->help.img, width, HEIGHT, 0x77000000 | GREY);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win,\
	mlx->help.ptr, 0, 0);
	print_text_g(mlx->mlx, mlx->win);
}
