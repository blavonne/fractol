#include "fractol.h"

void	update_image(unsigned char *img, t_map *map, int size)
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
		{
			img[cur++] += 1;
			img[cur++] += 1;
			img[cur++] += 1;
			img[cur] = 0;
		}
		i++;
	}
}

int			buddah_iter(t_fractol *fractol, t_complex c)
{
	t_complex	z;
	double		r;
	t_map		map;

	z = complex_init(0, 0);
//	z = c;
	map.size = 0;
	while (map.size < fractol->a.max_iter)
	{
		map.z[map.size] = z;
		z = complex_power(z, fractol->a.power);
		z = complex_sum(z, c);
		r = z.re * z.re + z.im * z.im;
		map.size++;
		if (r > 4 || r == 1./0.)
			break ;
	}
	update_image(fractol->mlx.image.img, &map, fractol->a.img_size);
	return (0);
}

void		buddah_color(unsigned char *img, int size, int maxiter)
{
	int		i;
	int		color;

	i = 0;
	while (i < size * size * (int)sizeof(int))
	{
		color = set_color(0, img[i], maxiter);
		img[i++] = color;
		img[i++] = color >> 8;
		img[i++] = color >> 16;
		img[i++] = 0;
	}
}

t_complex	not_random()
{
	t_complex	c;

	c.re = (double)rand() / (double)RAND_MAX * 4 - 2;
	c.im = (double)rand() / (double)RAND_MAX * 4 - 2;
	return (c);
}

int		buddah(t_fractol *fractol, t_complex c)
{
	int			i;

	i = 0;
	colorize(fractol->mlx.image.img, fractol->a.img_size, fractol->a
			.img_size, 0);
	while (i++ < fractol->a.img_size * fractol->a.img_size)
	{
		c = not_random();
		buddah_iter(fractol, c);
	}
	buddah_color(fractol->mlx.image.img, fractol->a.img_size,\
	fractol->a.max_iter);
	put_img_to_window_a(&fractol->mlx, 0, 0);
	return (0);
}
