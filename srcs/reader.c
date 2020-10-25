#include "fractol.h"

void		check_argv(int argc, char **argv)
{
	int		i;

	if (argc != 2)
		put_usage();
	i = 0;
	if (ft_strequ(argv[1], "-J") || ft_strequ(argv[1], "-M") ||\
	ft_strequ(argv[1], "-Koch") || ft_strequ(argv[1], "-Snow") ||\
	ft_strequ(argv[1], "-Burn") || ft_strequ(argv[1], "-Bu"))
		i = 1;
	(!i) ? put_usage() : 0;
}

int			read_argv(char *type, t_fractol *fractol)
{
	fractol_init(fractol);
	fractol->mlx.mlx = create_mlx();
	fractol->mlx.win = create_win(&fractol->mlx, WIDTH, HEIGHT, "Risovach");
	create_background(&fractol->mlx, WIDTH, HEIGHT, 0xffffff);
	if (ft_strequ(type, "-J"))
	{
		algebaic_init(&fractol->a, 1);
		fractol->mlx.image = create_img(&fractol->mlx, fractol->a.img_size,\
		fractol->a.img_size);
		mlx_hook(fractol->mlx.win, 6, 1L << 6, motion, fractol);
		rendering(fractol);
	}
	else if (ft_strequ(type, "-M"))
	{
		algebaic_init(&fractol->a, 0);
		fractol->mlx.image = create_img(&fractol->mlx, fractol->a.img_size,\
		fractol->a.img_size);
		rendering(fractol);
	}
	else if (ft_strequ(type, "-Koch"))
	{
		fractol->type = 1;
		geometric_init(&fractol->g);
		fractol->mlx.image = create_img(&fractol->mlx, WIDTH, HEIGHT);
		fractol->g.draw_geometric[(int)fractol->g.type](fractol);
	}
	else if (ft_strequ(type, "-Burn"))
	{
		algebaic_init(&fractol->a, 2);
		fractol->mlx.image = create_img(&fractol->mlx, fractol->a.img_size,\
		fractol->a.img_size);
		rendering(fractol);
	}
	else if (ft_strequ(type, "-Bu"))
	{
		algebaic_init(&fractol->a, 3);
		fractol->mlx.image = create_img(&fractol->mlx, fractol->a.img_size,\
			fractol->a.img_size);
		buddah(fractol);
//		rendering(fractol);
	}
//	if (!fractol->type)
//	{
//		fractol->mlx.image = create_img(&fractol->mlx, fractol->a.img_size,\
//		fractol->a.img_size);
//		rendering(fractol);
//	}
	return (1);
}
