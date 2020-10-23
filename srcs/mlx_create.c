#include "graphics_base.h"

void			create_background(t_mlx *mlx, int width, int height, int color)
{
	if (!(mlx->background.ptr = mlx_new_image(mlx->mlx, width, height)))
		exit(1);
	if (!(mlx->background.img = (unsigned char *)mlx_get_data_addr(\
	mlx->background.ptr, &mlx->background.bps, &mlx->background.size_line,\
	&mlx->background.endian)))
		exit(1);
	colorize(mlx->background.img, width, height, color);
}

void			colorize(unsigned char *img, int width, int heigh,\
		unsigned int color)
{
	t_argb	argb;
	int		i;
	
	i = 0;
	argb.channel[0] = color >> 24u;
	argb.channel[1] = color >> 16u;
	argb.channel[2] = color >> 8u;
	argb.channel[3] = color;
	while (i < width * heigh * (int)sizeof(int))
	{
		img[i++] = argb.channel[3];
		img[i++] = argb.channel[2];
		img[i++] = argb.channel[1];
		img[i++] = argb.channel[0];
	}
}

void			*create_mlx(void)
{
	void		*mlx;

	if (!(mlx = mlx_init()))
		exit(1);
	return (mlx);
}

void			*create_win(t_mlx *mlx, int width, int height, char *name)
{
	void	*window;

	if (!(window = mlx_new_window(mlx->mlx, width, height, name)))
		exit(1);
	return (window);
}

t_image			create_img(t_mlx *mlx, int width, int height)
{
	t_image		img;

	if (!(img.ptr = mlx_new_image(mlx->mlx, width, height)))
		exit(1);
	if (!(img.img = (unsigned char *)mlx_get_data_addr(img.ptr, &img.bps,\
	&img.size_line, &img.endian)))
		exit(1);
	ft_memset(img.img, 255, width * height * sizeof(int));
	return (img);
}
