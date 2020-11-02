/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:49:02 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 15:49:04 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fractol_init(t_fractol *fractol)
{
	fractol->type = 0;
	fractol->help = 0;
	fractol->mlx.mlx = NULL;
	fractol->mlx.win = NULL;
	fractol->mlx.image.img = NULL;
	fractol->mlx.image.ptr = NULL;
	fractol->mlx.background.img = NULL;
	fractol->mlx.background.ptr = NULL;
	fractol->mlx.help.ptr = NULL;
	fractol->mlx.help.img = NULL;
	fractol->g.draw_g[0] = NULL;
	fractol->g.draw_g[1] = NULL;
}
