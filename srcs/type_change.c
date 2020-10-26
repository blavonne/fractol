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
	if (!fractol->type && (key >= ONE && key <= THREE))
	{
		fractol->a.type != 1 ? fractol->a.motion_on = 0 : 0;
		if (key == ONE && fractol->a.type)
			fractol->a.type = 0;
		if (key == TWO && fractol->a.type != 1)
			fractol->a.type = 1;
		if (key == THREE && fractol->type != 2)
			fractol->a.type = 2;
		key_pressed(SPACE, fractol);
	}
	else if (!fractol->type && (key >= FOUR && key <= FIVE))
	{
		key == FOUR ? fractol->a.type = 3 : 0;
		key == FIVE ? fractol->a.type = 4 : 0;
		fractol->a.motion_on = 0;
	}
}