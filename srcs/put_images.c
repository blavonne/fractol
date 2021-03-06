/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:29:44 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:29:46 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			put_img_to_window_g(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->background.ptr,\
	x, y);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image.ptr,\
	x, y);
}

void			put_img_to_window_a(t_mlx *mlx, int x, int y)
{
	t_point	img;

	if (WIDTH > HEIGHT)
		img = point_init(WIDTH / 2 - HEIGHT / 2, 0);
	else
		img = point_init(0, HEIGHT / 2 - WIDTH / 2);
	mlx_put_image_to_window(mlx->mlx, mlx->win,\
	mlx->background.ptr, x, y);
	mlx_put_image_to_window(mlx->mlx, mlx->win,\
	mlx->image.ptr, img.x, img.y);
}
