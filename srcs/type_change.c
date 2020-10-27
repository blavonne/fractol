#include "fractol.h"

void			type_handler_g(int key, t_fractol *fractol)
{
	if (fractol->type && (key == ONE || key == TWO))
	{
		if ((key == ONE && !fractol->g.type) ||\
			(key == TWO && fractol->g.type))
			return ;
		mlx_destroy_image(fractol->mlx.mlx, fractol->mlx.image.ptr);
		fractol->g.offset.x = 0;
		fractol->g.offset.y = 0;
		if (!(fractol->mlx.image.ptr = mlx_new_image(fractol->mlx.mlx,\
				WIDTH, HEIGHT)))
			exit(1);
		if (!(fractol->mlx.image.img = (unsigned char *)mlx_get_data_addr(\
				fractol->mlx.image.ptr, &fractol->mlx.image.bps,\
				&fractol->mlx.image.size_line, &fractol->mlx.image.endian)))
			exit(1);
		ft_memset(fractol->mlx.image.img, 255, WIDTH * HEIGHT * sizeof(int));
		fractol->g.type = (key == ONE) ? 0 : 1;
	}
}

void			type_handler_a(int key, t_fractol *fractol)
{
	if (!fractol->type && (key >= ONE && key <= FOUR))
	{
		fractol->a.type != 1 ? fractol->a.motion_on = 0 : 0;
		if (key == ONE && fractol->a.type)
			fractol->a.type = 0;
		else if (key == TWO && fractol->a.type != 1)
			fractol->a.type = 1;
		else if (key == THREE && fractol->type != 2)
			fractol->a.type = 2;
		else if (key == FOUR && fractol->type != 3)
			fractol->a.type = 3;
		key_pressed(SPACE, fractol);
	}
	else if (!fractol->type && (key >= FIVE && key <= SIX))
	{
		key == FIVE ? fractol->a.type = 4 : 0;
		key == SIX ? fractol->a.type = 5 : 0;
		fractol->a.motion_on = 0;
	}
}