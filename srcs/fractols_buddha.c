/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols_buddha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:58:31 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:01:57 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		update_image(unsigned char *img, t_map *map, int size,\
		char channel)
{
	int		x;
	int		y;
	int		i;
	int		cur;

	i = 0;
	while (i < map->size)
	{
		x = (int)(round((2.0 + map->z[i].re) * size / 4));
		y = (int)(round((2.0 + map->z[i].im) * size / 4));
		cur = x;
		x = abs(-y);
		y = abs(cur);
		cur = (y * size + x) * (int)sizeof(int);
		if (x >= 0 && y >= 0 && x < size && y < size)
			img[cur + channel] += 1;
		i++;
	}
}

/*
** type 3 is buddha (outside of Mandelbrot), type 4 is abuddah (inside)
*/

static void		buddha_iter(t_fractol *fractol, char channel, int count)
{
	t_map		map;
	t_complex	z[2];
	double		r;

	while (count-- > 0)
	{
		z[0] = complex_init(0, 0);
		map.size = 0;
		z[1] = not_random();
		while (map.size < fractol->a.max_iter)
		{
			map.z[map.size++] = z[0];
			z[0] = complex_power(z[0], fractol->a.power);
			z[0] = complex_sum(z[0], z[1]);
			r = z[0].re * z[0].re + z[0].im * z[0].im;
			if (r > 4 || r == 1. / 0.)
			{
				fractol->a.type == 16 ? update_image(fractol->mlx.image.img,\
					&map, fractol->a.img_size, channel) : 0;
				break ;
			}
		}
		fractol->a.type == 17 ? update_image(fractol->mlx.image.img,\
			&map, fractol->a.img_size, channel) : 0;
	}
}

static void		buddha_circle(unsigned char *img, int width, int height,\
		int color)
{
	int		x;
	int		y;
	int		cur;
	int		r;

	y = 0;
	r = width / 2;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			cur = (y * width + x) * (int)sizeof(int);
			if (pow(r - 1, 2) < pow((r - x), 2) + pow((r - y), 2))
			{
				img[cur] = color;
				img[cur + 1] = (unsigned)color >> 8u;
				img[cur + 2] = (unsigned)color >> 16u;
			}
			x++;
		}
		y++;
	}
}

/*
** this method is called false color; we should iterate image three times
** to get red, blue and green points orbit with different iterations count
** (20, 200, 2000 for ex) https://en.wikipedia.org/wiki/Buddhabrot
** count_points is random value (recommended im_w x im_h x 10)
*/

int				buddha(t_fractol *fractol)
{
	int		count_points;

	count_points = fractol->a.img_size * fractol->a.img_size * 10;
	colorize(fractol->mlx.image.img, pow(fractol->a.img_size, 2), 1, 0);
	fractol->a.max_iter = 2000;
	buddha_iter(fractol, 0, count_points);
	fractol->a.max_iter = 200;
	buddha_iter(fractol, 1, count_points);
	fractol->a.max_iter = 20;
	buddha_iter(fractol, 2, count_points);
	fractol->a.max_iter = 255;
	buddha_circle(fractol->mlx.image.img, fractol->a.img_size,\
	fractol->a.img_size, 0xFFFFFF);
	put_img_to_window_a(&fractol->mlx, 0, 0);
	return (0);
}
