#include "fractol.h"

typedef struct	s_map
{
	t_complex	z[255];
	int			size;
}				t_map;

int			buddah_iter(t_fractol *fractol, t_complex c, t_map *map)
{
	t_complex	z;
	double		r;

	z = c;
	map->z[0] = z;
	map->size = 1;
	while (map->size < fractol->a.max_iter)
	{
		z = complex_power(z, fractol->a.power);
		z = complex_sum(z, c);
		r = z.re * z.re + z.im * z.im;
		map->z[map->size] = z;
		map->size++;
		if (r > 4 || r == 1./0.)
			break ;
	}
	return (0);
}

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

void	buddah_color(unsigned char *img, int size)
{
	int		i;
	int		color;

	i = 0;
	while (i < size * size * (int)sizeof(int))
	{
		color = set_color(0, img[i], 255);
		img[i++] = color;
		img[i++] = color >> 8;
		img[i++] = color >> 16;
		img[i++] = 0;
	}
}


int		buddah(t_fractol *fractol, t_complex c)
{
	int			i;
	t_map		map;

	i = 0;
	map.size = 0;
	colorize(fractol->mlx.image.img, fractol->a.img_size, fractol->a
			.img_size, 0);
	while (i < fractol->a.img_size * fractol->a.img_size * 10)
	{
		buddah_iter(fractol, c, &map);
		update_image(fractol->mlx.image.img, &map, fractol->a.img_size);
		i++;
	}
	buddah_color(fractol->mlx.image.img, fractol->a.img_size);
	mlx_put_image_to_window(fractol->mlx.mlx, fractol->mlx.win, fractol->mlx
			.image.ptr, WIDTH / 4, 0);
	return (0);
}



//int		buddah(t_fractol *fractol, t_complex c)
//{
//	t_complex	c;
//	int			i;
//	t_map		map;
//
//	i = 0;
//	map.size = 0;
//	colorize(fractol->mlx.image.img, fractol->a.img_size, fractol->a
//	.img_size, 0);
//	while (i < fractol->a.img_size * fractol->a.img_size * 10)
//	{
//		c.re = fractol->a.min.re + (double)rand() / rand()  *
//				fractol->a.size;
//		c.im = fractol->a.min.im + (double)rand() / rand()  *
//				fractol->a.size;
//		buddah_iter(fractol, c, &map);
//		update_image(fractol->mlx.image.img, &map, fractol->a
//		.img_size);
//		i++;
//	}
//	buddah_color(fractol->mlx.image.img, fractol->a.img_size);
//	mlx_put_image_to_window(fractol->mlx.mlx, fractol->mlx.win, fractol->mlx
//	.image.ptr, WIDTH / 4, 0);
//	return (0);
//}
