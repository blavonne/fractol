#include "fractol.h"

void		check_argv(int argc, char **argv)
{
	int		i;

	if (argc != 2)
		put_usage();
	i = 0;
	if (ft_strequ(argv[1], "-Julia") || ft_strequ(argv[1], "-Mandelbrot") ||\
	ft_strequ(argv[1], "-Koch") || ft_strequ(argv[1], "-Abuddha") ||\
	ft_strequ(argv[1], "-Ship") || ft_strequ(argv[1], "-Buddha") ||\
	ft_strequ(argv[1], "-Test"))
		i = 1;
	(!i) ? put_usage() : 0;
}

int			read_argv(char *type, t_fractol *fractol)
{
	fractol_init(fractol);
	fractol->mlx.mlx = create_mlx();
	fractol->mlx.win = create_win(&fractol->mlx, WIDTH, HEIGHT, "Risovach");
	create_background(&fractol->mlx, WIDTH, HEIGHT, 0xffffff);
	ft_strequ(type, "-Julia") ? algebaic_init(&fractol->a, 1) : 0;
	ft_strequ(type, "-Mandelbrot") ? algebaic_init(&fractol->a, 0) : 0;
	ft_strequ(type, "-Koch") ? fractol->type = 1 : 0;
	ft_strequ(type, "-Ship") ? algebaic_init(&fractol->a, 2) : 0;
	ft_strequ(type, "-Buddha") ? algebaic_init(&fractol->a, 4) : 0;
	ft_strequ(type, "-Abuddha") ? algebaic_init(&fractol->a, 5) : 0;
	ft_strequ(type, "-Test") ? algebaic_init(&fractol->a, 3) : 0;
	if (!fractol->type)
	{
		fractol->mlx.image = create_img(&fractol->mlx, fractol->a.img_size,\
		fractol->a.img_size);
		fractol->a.type == 1 ? mlx_hook(fractol->mlx.win, 6, 1L << 6, motion,\
		fractol) : 0;
		rendering(fractol);
	}
	else
	{
		geometric_init(&fractol->g);
		fractol->mlx.image = create_img(&fractol->mlx, WIDTH, HEIGHT);
		fractol->g.draw_geometric[(int)fractol->g.type](fractol);
	}
	return (1);
}
