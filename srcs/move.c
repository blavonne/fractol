#include "fractol.h"

void		move_a(int key, t_fractol *fractol)
{
	if (key == ARROW_RIGHT)
		fractol->a.min.re -= 0.015 * fractol->a.size;
	else if (key == ARROW_LEFT)
		fractol->a.min.re += 0.015 * fractol->a.size;
	else if (key == ARROW_DOWN)
		fractol->a.min.im -= 0.015 * fractol->a.size;
	else if (key == ARROW_UP)
		fractol->a.min.im += 0.015 * fractol->a.size;
}

void		move_g(int key, t_fractol *fractol)
{
	ft_memset(fractol->mlx.image.img, 255, WIDTH * HEIGHT * sizeof(int));
	if (key == ARROW_RIGHT)
		fractol->g.offset.x += 5;
	else if (key == ARROW_LEFT)
		fractol->g.offset.x -= 5;
	else if (key == ARROW_DOWN)
		fractol->g.offset.y -= 5;
	else if (key == ARROW_UP)
		fractol->g.offset.y += 5;
}
