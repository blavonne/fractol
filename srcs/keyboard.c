#include "fractol.h"

int				clean_exit(void *param)
{
	destroy_fractol((t_fractol *)param);
	exit(0);
}

int				deal_key(int key, t_fractol *fractol)
{
	printf("deal_key %d\n", key);//del
	if (key == ESC)
		clean_exit(fractol);
	else if ((key == ARROW_LEFT || key == ARROW_RIGHT || key == ARROW_UP || key\
	== ARROW_DOWN) && !fractol->type)
		move_a(key, fractol);
	else if ((key == ARROW_LEFT || key == ARROW_RIGHT || key == ARROW_UP || key\
	== ARROW_DOWN) && fractol->type)
		move_g(key, fractol);
	else if ((key == BLUE || key == RED || key == GREEN || key == ALPHA) &&\
	fractol->type)
		increase_img_color(key, fractol);
	else if (fractol->type && key == NUM_PLUS)
		fractol->g.sign = 1;
	else if (fractol->type && key == NUM_MINUS)
		fractol->g.sign = 0;
	else if (fractol->type && (key == MAIN_MINUS || key == MAIN_PLUS))
		zoom_g(fractol, key);
	else if (fractol->type && (key == ONE || key == TWO))
	{
		if ((key == ONE && !fractol->g.type) ||(key == TWO && fractol->g.type))
			return (0);
		mlx_destroy_image(fractol->mlx.mlx_ptr, fractol->mlx.image.ptr);
		fractol->g.offset.x = 0;
		fractol->g.offset.y = 0;
		if (!(fractol->mlx.image.ptr = mlx_new_image(fractol->mlx.mlx_ptr,\
		WIDTH, HEIGHT)))
			exit(1);
		if (!(fractol->mlx.image.img = (unsigned char *)mlx_get_data_addr(\
		fractol->mlx.image.ptr, &fractol->mlx.image.bps,\
		&fractol->mlx.image.size_line, &fractol->mlx.image.endian)))
			exit(1);
		ft_memset(fractol->mlx.image.img, 255, WIDTH * HEIGHT * sizeof(int));
		fractol->g.type = (key == ONE) ? 0 : 1;
	}
	else if (key == HELP && fractol->help)
	{
		fractol->help = 0;
		mlx_destroy_image(fractol->mlx.mlx_ptr, fractol->mlx.help.ptr);
		fractol->mlx.help.ptr = NULL;
	}
	else if (key == SPACE)
	{
		fractol->type ? restore_to_default_g(fractol) :\
		restore_to_default_a(fractol);
	}
	else if (key == HELP && !fractol->help)
	{
		fractol->help = 1;
		fractol->type ? help_g(&fractol->mlx) : help_a(&fractol->mlx);
	}
	fractol->type ? fractol->g.draw_geometric[fractol->g.type](fractol) :\
	thread_draw(fractol);
	return (0);
}
