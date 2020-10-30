#include "fractol.h"

int			check_argv(int argc, char **argv)
{
	int		i;

	i = -1;
	if (argc != 2)
		return (i);
	ft_strequ(argv[1], "-Mandelbrot") ? i = 0 : 0;
	ft_strequ(argv[1], "-Julia") ? i = 1 : 0;
	ft_strequ(argv[1], "-Ship") ? i = 2 : 0;
	ft_strequ(argv[1], "-Antoshka") ? i = 3 : 0;
	ft_strequ(argv[1], "-Trident") ? i = 4 : 0;
	ft_strequ(argv[1], "-Turtle") ? i = 5 : 0;
	ft_strequ(argv[1], "-Ring") ? i = 6 : 0;
	ft_strequ(argv[1], "-Cactus") ? i = 7 : 0;
	ft_strequ(argv[1], "-Leaf") ? i = 8 : 0;
	ft_strequ(argv[1], "-Peacock") ? i = 9 : 0;
	ft_strequ(argv[1], "-Newton") ? i = 10 : 0;
	ft_strequ(argv[1], "-Buddha") ? i = 16 : 0;
	ft_strequ(argv[1], "-Abuddha") ? i = 17 : 0;
	ft_strequ(argv[1], "-Koch") ? i = 18 : 0;
	ft_strequ(argv[1], "-Snow") ? i = 19 : 0;
	ft_strequ(argv[1], "-Tree") ? i = 20 : 0;
	ft_strequ(argv[1], "-Pifagor") ? i = 21 : 0;
	return (i);
}

int			read_argv(int type, t_fractol *fractol)
{
	fractol_init(fractol);
	fractol->mlx.mlx = create_mlx();
	fractol->mlx.win = create_win(&fractol->mlx, WIDTH, HEIGHT, "Fractol");
	create_background(&fractol->mlx, WIDTH, HEIGHT, 0xffffff);
	if (type >= 0 && type <= 17)
		algebaic_init(&fractol->a, (char)type);
	else
		fractol->type = 1;
	if (!fractol->type)
	{
		fractol->mlx.image = create_img(&fractol->mlx, fractol->a.img_size,\
		fractol->a.img_size);
		fractol->a.type == 1 ? mlx_hook(fractol->mlx.win, 6, 1L << 6,\
		julia_motion, fractol) : 0;
		rendering(fractol);
	}
	else if (fractol->type)
	{
		geometric_init(&fractol->g, (char)(type % 18));
		fractol->mlx.image = create_img(&fractol->mlx, WIDTH, HEIGHT);
		fractol->g.draw_g[(int)fractol->g.type](fractol);
	}
	return (1);
}
