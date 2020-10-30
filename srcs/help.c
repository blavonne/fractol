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
	int		i;
	int		width;

	i = 0;
	width = (int)(WIDTH - ft_min(WIDTH, HEIGHT)) / 2;
	mlx->help = create_img(mlx, width, HEIGHT);
	while (i < width * HEIGHT * sizeof(int))
	{
		set_color_pixel(mlx->help.img, i, GREY);
		i += 4;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win,\
	mlx->help.ptr, 0, 0);
	print_text_g(mlx->mlx, mlx->win);
}

static void		print_text_a(void *m, void *w)
{
	mlx_string_put(m, w, 10, 15, 0, "Algebraic usage:");
	mlx_string_put(m, w, 10, 3 * 15, 0, "* Arrows to move;");
	mlx_string_put(m, w, 10, 5 * 15, 0, "* Main \"-\" and \"+\" to");
	mlx_string_put(m, w, 10, 7 * 15, 0, "change iteration's count;");
	mlx_string_put(m, w, 10, 9 * 15, 0, "* NUM \"-\" and \"+\" to");
	mlx_string_put(m, w, 10, 11 * 15, 0, "change power;");
	mlx_string_put(m, w, 10, 13 * 15, 0, "* Scroll mouse to zoom;");
	mlx_string_put(m, w, 10, 15 * 15, 0, "* Space to reset;");
	mlx_string_put(m, w, 10, 17 * 15, 0, "* C to change color-schema;");
	mlx_string_put(m, w, 10, 19 * 15, 0, "* I to open/close info;");
	mlx_string_put(m, w, 10, 21 * 15, 0, "* 1 to draw Mandelbrot;");
	mlx_string_put(m, w, 10, 23 * 15, 0, "* 2 to draw Julia;");
	mlx_string_put(m, w, 10, 25 * 15, 0, "* P to start/stop Julia;");
	mlx_string_put(m, w, 10, 27 * 15, 0, "* 3 to draw Burning ship;");
	mlx_string_put(m, w, 10, 29 * 15, 0, "* 4 to draw Antoshka;");
	mlx_string_put(m, w, 10, 31 * 15, 0, "* 4 to draw Trident;");
	mlx_string_put(m, w, 10, 33 * 15, 0, "* 5 to draw Turtle;");
	mlx_string_put(m, w, 10, 35 * 15, 0, "* 6 to draw Ring;");
	mlx_string_put(m, w, 10, 37 * 15, 0, "* 7 to draw Cactus;");
	mlx_string_put(m, w, 10, 39 * 15, 0, "* 9 to draw Leaf;");
	mlx_string_put(m, w, 10, 41 * 15, 0, "* NUM 1 to draw Peacock;");
	mlx_string_put(m, w, 10, 43 * 15, 0, "* NUM 8 to draw Buddha;");
	mlx_string_put(m, w, 10, 45 * 15, 0, "* NUM 9 to draw Abuddha;");
}

void			help_a(t_mlx *mlx)
{
	int		i;
	int		width;

	i = 0;
	width = (int)(WIDTH - ft_min(WIDTH, HEIGHT)) / 2;
	if (!mlx->help.ptr)
	{
		mlx->help = create_img(mlx, width, HEIGHT);
		while (i < width * HEIGHT * sizeof(int))
		{
			set_color_pixel(mlx->help.img, i, GREY);
			i += 4;
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win,\
	mlx->help.ptr, 0, 0);
	print_text_a(mlx->mlx, mlx->win);
}

void			help_handler(int key, t_fractol *fractol)
{
	if (key == MAIN_I && fractol->help)
	{
		fractol->help = 0;
		mlx_destroy_image(fractol->mlx.mlx, fractol->mlx.help.ptr);
		fractol->mlx.help.ptr = NULL;
	}
	else if (key == MAIN_I && !fractol->help)
	{
		fractol->help = 1;
		fractol->type ? help_g(&fractol->mlx) : help_a(&fractol->mlx);
	}
}