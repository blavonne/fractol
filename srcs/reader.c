#include "fractol.h"

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
//		mlx_hook(fractol->mlx.win_ptr, 6, 1L << 6, set_julia_c, fractol);
		thread_draw(fractol);
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
