#include "fractol.h"

void		check_argv(int argc, char **argv)
{
	int		i;

	if (argc != 2)
		put_usage();
	i = 0;
	if (ft_strequ(argv[1], "-J") || ft_strequ(argv[1], "-M") ||\
	ft_strequ(argv[1], "-Koch") || ft_strequ(argv[1], "-Snow") ||\
	ft_strequ(argv[1], "-Burn"))
		i = 1;
	(!i) ? put_usage() : 0;
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
		algebaic_init(&fractol->a, 1);
		create_image(&fractol->mlx, fractol->a.img_size, fractol->a.img_size);
		mlx_hook(fractol->mlx.win_ptr, 6, 1L << 6, set_julia_c, fractol);
//		thread_draw(fractol);
	}
	else if (ft_strequ(type, "-M"))
	{
		algebaic_init(&fractol->a, 0);
		create_image(&fractol->mlx, fractol->a.img_size, fractol->a.img_size);
		thread_draw(fractol);
	}
	else if (ft_strequ(type, "-Koch"))
	{
		fractol->type = 1;
		geometric_init(&fractol->g);
		create_image(&fractol->mlx, WIDTH, HEIGHT);
		fractol->g.draw_geometric[(int)fractol->g.type](fractol);
	}
	else if (ft_strequ(type, "-Burn"))
	{
		algebaic_init(&fractol->a, 2);
		create_image(&fractol->mlx, fractol->a.img_size, fractol->a.img_size);
		thread_draw(fractol);
	}
	return (1);
}
