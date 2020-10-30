#include "fractol.h"

void				zoom_g(t_fractol *fractol, int key)
{
	if (fractol->g.power < 9 && fractol->g.power > -1)
	{
		ft_memset(fractol->mlx.image.img, 255, WIDTH * HEIGHT * sizeof(int));
		if (key == MAIN_PLUS && fractol->g.power < 5 && fractol->g.type < 2)
			fractol->g.power++;
		else if (key == MAIN_PLUS && fractol->g.power < 8 && fractol->g.type\
		> 1)
			fractol->g.power++;
		else if (key == MAIN_MINUS && fractol->g.power > 0)
			fractol->g.power--;
		printf("zoom: %d\n", fractol->g.power);
	}
}

static t_complex	view_shift(int x, int y, t_fractol *fractol)
{
	t_complex	cursor;

	x = x - (WIDTH - fractol->a.img_size) / 2;
	y = y - (HEIGHT - fractol->a.img_size) / 2;
	cursor.re = fractol->a.min.re + x * fractol->a.size / fractol->a.img_size;
	cursor.im = fractol->a.min.im + y * fractol->a.size / fractol->a.img_size;
	return (cursor);
}

int					zoom_a(int key, int x, int y, t_fractol *fractol)
{
	t_complex	cursor;

	if (!fractol->type && fractol->a.type < 10)
	{
		if (x < (WIDTH - fractol->a.img_size) / 2 || x > (WIDTH +\
			fractol->a.img_size) / 2)
			return (0);
		cursor = view_shift(x, y, fractol);
		if (key == MOUSE_SCROLL_DOWN)
		{
			fractol->a.min.re = cursor.re + (fractol->a.min.re - cursor.re) * SCALE;
			fractol->a.min.im = cursor.im + (fractol->a.min.im - cursor.im) * SCALE;
			fractol->a.size *= SCALE;
			fractol->a.max_iter + 10 > 0 ? fractol->a.max_iter += 10 : 0;
		}
		if (key == MOUSE_SCROLL_UP)
		{
			fractol->a.min.re = cursor.re + (fractol->a.min.re - cursor.re) / SCALE;
			fractol->a.min.im = cursor.im + (fractol->a.min.im - cursor.im) / SCALE;
			fractol->a.size /= SCALE;
			fractol->a.max_iter - 10 > 0 ? fractol->a.max_iter -= 10 : 0;
		}
		rendering(fractol);
	}
	return (0);
}
