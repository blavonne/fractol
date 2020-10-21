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
	mlx_string_put(m, w, 10, 25 * 15, 0xff, "* Space to restore to default;");
}

void			help_g(t_mlx *mlx)
{
	t_argb	color;
	int		i;

	i = 0;
	color.channel[0] = 200;
	color.channel[1] = 0x02;
	color.channel[2] = 0xC4;
	color.channel[3] = 0xFA;
	if (!(mlx->help.ptr = mlx_new_image(mlx->mlx_ptr, WIDTH * 0.2, HEIGHT)))
		exit(1);
	if (!(mlx->help.img = (unsigned char *)mlx_get_data_addr(\
	mlx->help.ptr, &mlx->help.bps, &mlx->help.size_line,\
	&mlx->help.endian)))
		exit(1);
	ft_memset(mlx->help.img, 0, WIDTH * 0.2 * HEIGHT * sizeof(int));
	while (i < WIDTH * HEIGHT * 0.2 * sizeof(int))
	{
		mlx->help.img[i] = color.channel[3];
		mlx->help.img[i + 1] = color.channel[2];
		mlx->help.img[i + 2] = color.channel[1];
		mlx->help.img[i + 3] = color.channel[0];
		i += 4;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,\
	mlx->help.ptr, 0, 0);
	print_text_g(mlx->mlx_ptr, mlx->win_ptr);
}

static void		print_text_a(void *m, void *w)
{
	mlx_string_put(m, w, 10, 15, 0, "Algebraic usage:");
	mlx_string_put(m, w, 10, 3 * 15, 0, "* Arrows to move;");
	mlx_string_put(m, w, 10, 5 * 15, 0, "* Main \"-\" and \"+\" to");
	mlx_string_put(m, w, 10, 7 * 15, 0, "change iteration's count;");
	mlx_string_put(m, w, 10, 9 * 15, 0, "* NUM \"-\" and \"+\" to");
	mlx_string_put(m, w, 10, 11 * 15, 0, "change color;");
	mlx_string_put(m, w, 10, 13 * 15, 0, "* Scroll mouse to zoom;");
	mlx_string_put(m, w, 10, 15 * 15, 0, "* Space to reset;");
}


void			help_a(t_mlx *mlx)
{
	t_argb	color;
	int		i;
	int		width;

	i = 0;
	width = (int)(WIDTH - ft_min(WIDTH, HEIGHT)) / 2;
	color.channel[0] = 150;
	color.channel[1] = 0xd5;
	color.channel[2] = 0xfa;
	color.channel[3] = 0x02;
	if (!mlx->help.ptr)
	{
		if (!(mlx->help.ptr = mlx_new_image(mlx->mlx_ptr, width, HEIGHT)))
			exit(1);
		if (!(mlx->help.img = (unsigned char *)mlx_get_data_addr(\
	mlx->help.ptr, &mlx->help.bps, &mlx->help.size_line,\
	&mlx->help.endian)))
			exit(1);
		ft_memset(mlx->help.img, 0, width * HEIGHT * sizeof(int));
		while (i < WIDTH * HEIGHT * 0.2 * sizeof(int))
		{
			mlx->help.img[i] = (char)ORCHID;
			mlx->help.img[i + 1] = (char)((unsigned)ORCHID >> 8u);
			mlx->help.img[i + 2] = (char)((unsigned)ORCHID >> 16u);
			mlx->help.img[i + 3] = 150;
			i += 4;
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,\
	mlx->help.ptr, 0, 0);
	print_text_a(mlx->mlx_ptr, mlx->win_ptr);
}
