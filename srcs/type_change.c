#include "fractol.h"

void			type_handler_g(int key, t_fractol *fractol)
{
	if (fractol->type && (key >= ONE && key <= FOUR))
	{
		if ((key == ONE && !fractol->g.type) ||\
			(key == TWO && fractol->g.type == 1) || (key == THREE &&\
			fractol->g.type == 2) || key == FOUR && fractol->g.type == 3)
			return ;
		mlx_destroy_image(fractol->mlx.mlx, fractol->mlx.image.ptr);
		fractol->g.offset = point_init(0 ,0);
		fractol->mlx.image = create_img(&fractol->mlx, WIDTH, HEIGHT);
		fractol->g.power = 0;
		fractol->g.bough_angle = 0.6;
		if (key == ONE)
			fractol->g.type = 0;
		else if (key == TWO)
			fractol->g.type = 1;
		else if (key == THREE)
			fractol->g.type = 2;
		else
			fractol->g.type = 3;
		set_color_schema_g(&fractol->g, fractol->g.type);
	}
}

static int		set_type(int key, t_fractol *fractol)
{
	if (key == ONE && fractol->a.type)
		fractol->a.type = 0;
	else if (key == TWO && fractol->a.type != 1)
		fractol->a.type = 1;
	else if (key == THREE && fractol->type != 2)
		fractol->a.type = 2;
	else if (key == FOUR && fractol->type != 3)
		fractol->a.type = 3;
	else if (key == FIVE && fractol->type != 4)
		fractol->a.type = 4;
	else if (key == SIX && fractol->type != 5)
		fractol->a.type = 5;
	else if (key == SEVEN && fractol->type != 6)
		fractol->a.type = 6;
	else if (key == EIGHT && fractol->type != 7)
		fractol->a.type = 7;
	else if (key == NINE && fractol->type != 8)
		fractol->a.type = 8;
	else if (key == NUM_ONE && fractol->type != 9)
		fractol->a.type = 9;
	else if (key == NUM_EIGHT && fractol->type != 10)
		fractol->a.type = 10;
	else if (key == NUM_NINE && fractol->type != 11)
		fractol->a.type = 11;
	return (-1);
}

void			type_handler_a(int *key, t_fractol *fractol)
{
	int		old_type;

	fractol->a.motion_on = 0;
	old_type = (int)fractol->a.type;
	if (!fractol->type)
	{
		if (*key >= ONE && *key <= NINE || *key == NUM_ONE || *key ==\
		NUM_NINE || *key == NUM_EIGHT)
		{
			set_type(*key, fractol);
			if (fractol->a.type != old_type && fractol->a.type < 10)
				*key = SPACE;
		}
	}
}