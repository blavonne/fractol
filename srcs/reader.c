/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:35:15 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:35:24 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_argv2(char **argv)
{
	int		i;

	i = -1;
	ft_strequ(argv[1], "-Web") ? i = 11 : 0;
	ft_strequ(argv[1], "-Butterfly") ? i = 12 : 0;
	ft_strequ(argv[1], "-Circle") ? i = 13 : 0;
	ft_strequ(argv[1], "-Graffiti") ? i = 14 : 0;
	ft_strequ(argv[1], "-Batman") ? i = 15 : 0;
	ft_strequ(argv[1], "-Buddha") ? i = 16 : 0;
	ft_strequ(argv[1], "-Abuddha") ? i = 17 : 0;
	ft_strequ(argv[1], "-Koch") ? i = 18 : 0;
	ft_strequ(argv[1], "-Snow") ? i = 19 : 0;
	ft_strequ(argv[1], "-Tree") ? i = 20 : 0;
	ft_strequ(argv[1], "-Pifagor") ? i = 21 : 0;
	return (i);
}

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
	if (i < 0)
		return (check_argv2(argv));
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
