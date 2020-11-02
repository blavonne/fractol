/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_g.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:48:25 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 15:48:27 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	rgb_color_plus(int key, t_argb *argb)
{
	if (key == MAIN_R)
	{
		if (argb->channel[1] + 10 < 255)
			argb->channel[1] += 10;
		else
			(argb->channel[1] = 0);
	}
	if (key == MAIN_B)
	{
		if (argb->channel[3] + 10 < 255)
			argb->channel[3] += 10;
		else
			(argb->channel[3] = 0);
	}
	if (key == MAIN_G)
	{
		if (argb->channel[2] + 10 < 255)
			argb->channel[2] += 10;
		else
			(argb->channel[2] = 0);
	}
}

static void	rgb_color_minus(int key, t_argb *argb)
{
	if (key == MAIN_R)
	{
		if (argb->channel[1] - 10 > 0)
			argb->channel[1] -= 10;
		else
			(argb->channel[1] = 255);
	}
	if (key == MAIN_B)
	{
		if (argb->channel[3] - 10 > 0)
			argb->channel[3] -= 10;
		else
			(argb->channel[3] = 255);
	}
	if (key == MAIN_G)
	{
		if (argb->channel[2] - 10 > 0)
			argb->channel[2] -= 10;
		else
			(argb->channel[2] = 255);
	}
}

static void	alpha_color(int key, t_argb *argb, char flag)
{
	if (key == MAIN_T && flag)
	{
		if (argb->channel[0] - 10 > 0)
			argb->channel[0] -= 10;
		else
			(argb->channel[0] = 0);
	}
	else if (key == MAIN_T)
	{
		if (argb->channel[0] + 10 < 255)
			argb->channel[0] += 10;
		else
			(argb->channel[0] = 255 - 1);
	}
}

void		increase_img_color(int key, t_fractol *fractol)
{
	if (fractol->g.sign)
		rgb_color_plus(key, &fractol->g.argb);
	else
		rgb_color_minus(key, &fractol->g.argb);
	alpha_color(key, &fractol->g.argb, fractol->g.sign);
	ft_memset(fractol->mlx.image.img, 255, WIDTH * HEIGHT * sizeof(int));
}
