/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:44:13 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:44:15 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** mlx_expose_hook draws picture every time. it works on macos and doesn't
** work on linux.
*/

int			main(int argc, char **argv)
{
	t_fractol	fractol;
	int			type;

	if ((type = check_argv(argc, argv)) < 0)
	{
		put_usage();
		return (0);
	}
	read_argv(type, &fractol);
	mlx_key_hook(fractol.mlx.win, key_pressed, &fractol);
	mlx_hook(fractol.mlx.win, 4, 1L << 2, zoom_a, &fractol);
	mlx_hook(fractol.mlx.win, 17, 1L << 17, clean_exit, &fractol);
	mlx_loop(fractol.mlx.mlx);
	return (0);
}
