#include "fractol.h"

int			mouse_cords(int x, int y, void *data)
{
	t_fractol	*fractol;

	fractol = data;
	fractol->a.c.re += fractol->a.size / fractol->a.img_size * x;
	fractol->a.c.im += fractol->a.size / fractol->a.img_size * y;
	return (0);
}

int			read_argv(char *type, t_fractol *fractol)
{
	fractol_init(fractol);
	if (!(fractol->mlx.mlx_ptr = mlx_init()))
		exit(1);
	create_window(&fractol->mlx, WIDTH, HEIGHT, "Mama ja hudozhnik");
	create_background(&fractol->mlx, WIDTH, HEIGHT, 0xffffff);
	if (ft_strequ(type, "-J"))
	{
		algebaic_init(&fractol->a);
		create_image(&fractol->mlx, fractol->a.img_size, fractol->a.img_size);
		fractol->a.type = 1;
		mlx_hook(fractol->mlx.win_ptr, 6, 1L << 6, &mouse_cords, fractol);
	}
	else if (ft_strequ(type, "-M"))
	{
		algebaic_init(&fractol->a);
		create_image(&fractol->mlx, fractol->a.img_size, fractol->a.img_size);
		thread_draw(fractol);
	}
	else if (ft_strequ(type, "-Koch"))
	{
		fractol->type = 1;
		geometric_init(&fractol->g);
		create_image(&fractol->mlx, WIDTH, HEIGHT);
		fractol->g.draw_geometric[fractol->g.type](fractol);
	}
	return (1);
}
