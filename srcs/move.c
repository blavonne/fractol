#include "fractol.h"

//void		move_a(int key, t_fractol *fractol)
//{
//	t_complex	delta;
//
//	delta = complex_init(fabs(fractol->a.max.re - fractol->a.min.re),
//	fabs(fractol->a.max.im - fractol->a.min.im));
//	if (key == ARROW_RIGHT)
//	{
//		fractol->a.min.re -= delta.re * 0.05;
//		fractol->a.max.re -= delta.re * 0.05;
//	}
//	else if (key == ARROW_LEFT)
//	{
//		fractol->a.min.re += delta.re * 0.05;
//		fractol->a.max.re += delta.re * 0.05;
//	}
//	else if (key == ARROW_DOWN)
//	{
//		fractol->a.min.im += delta.im * 0.05;
//		fractol->a.max.im += delta.im * 0.05;
//	}
//	else if (key == ARROW_UP)
//	{
//		fractol->a.min.im -= delta.im * 0.05;
//		fractol->a.max.im -= delta.im * 0.05;
//	}
//	create_mandelbrot(fractol);
//}

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
//	fractol->g.draw_geometric[fractol->g.type](fractol);
}
