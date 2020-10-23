#include "fractol.h"

void		zoom_g(t_fractol *fractol, int key)
{
	if (fractol->g.n < 6 && fractol->g.n > -1)
	{
		ft_memset(fractol->mlx.image.img, 255, WIDTH * HEIGHT * sizeof(int));
		if (key == MAIN_PLUS && fractol->g.n < 5)
			fractol->g.n++;
		else if (key == MAIN_MINUS && fractol->g.n > 0)
			fractol->g.n--;
		printf("zoom: %d\n", fractol->g.n);
	}
}

int				zoom_a(int key, int x, int y, t_fractol *fractol)
{
	double		wx;
	double		wy;

	if (x < (WIDTH - fractol->a.img_size) / 2 || x > (WIDTH + fractol->a
	.img_size) / 2)
		return (0);
	if (fractol->type)
		return (0);
	x = x - (WIDTH - fractol->a.img_size) / 2;
	y = y - (HEIGHT - fractol->a.img_size) / 2;
	wx = fractol->a.min.re + x * fractol->a.size / fractol->a.img_size;
	wy = fractol->a.min.im + y * fractol->a.size / fractol->a.img_size;
	if (key == MOUSE_SCROLL_DOWN)
	{
		fractol->a.min.re = wx + (fractol->a.min.re - wx) * SCALE;
		fractol->a.min.im = wy + (fractol->a.min.im - wy) * SCALE;
		fractol->a.size *= SCALE;
//		fractol->a.max_iter + 10 > 0 ? fractol->a.max_iter += 10 : 0;
	}
	if (key == MOUSE_SCROLL_UP)
	{
		fractol->a.min.re = wx + (fractol->a.min.re - wx) / SCALE;
		fractol->a.min.im = wy + (fractol->a.min.im - wy) / SCALE;
		fractol->a.size /= SCALE;
//		fractol->a.max_iter - 10 > 0 ? fractol->a.max_iter -= 10 : 0;
	}
	thread_draw(fractol);
	return (0);
}
