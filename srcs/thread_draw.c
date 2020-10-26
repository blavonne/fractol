#include "fractol.h"

void		draw_a(void *data)
{
	t_thread	*thread;
	t_point		screen;
	t_complex	complex;
	t_complex	step;
	int			iter;

	thread = data;
	screen = point_init(0, thread->start);
	step.re = thread->fractol->a.size / thread->fractol->a.img_size;
	step.im = thread->fractol->a.size / thread->fractol->a.img_size;
	complex.im = thread->fractol->a.min.im + thread->start * step.im;
	while (screen.y < thread->finish)
	{
		screen.x = 0;
		complex.re = thread->fractol->a.min.re;
		while (screen.x < thread->fractol->a.img_size)
		{
			iter = thread->fractol->a.draw_a[(int)thread->fractol->a.type]\
			(thread->fractol, complex);
			color_init(screen, iter, thread->fractol);
			screen.x++;
			complex.re += step.re;
		}
		screen.y++;
		complex.im += step.im;
	}
}

int			motion(int x, int y, t_fractol *fractol)
{
	t_complex	min;

	if (fractol->a.motion_on && fractol->a.type == 1)
	{
		min = fractol->a.min;
		x = x - (WIDTH - fractol->a.img_size) / 2;
		y = y - (HEIGHT - fractol->a.img_size) / 2;
		if (x >= 0 && y >= 0 && x < fractol->a.img_size && y\
		< fractol->a.img_size)
		{
			fractol->a.c.re = x * fractol->a.size / fractol->a.img_size\
			+ min.re;
			fractol->a.c.im = y * fractol->a.size / fractol->a.img_size\
			+ min.im;
		}
		rendering(fractol);
	}
	return (0);
}

int			rendering(void *data)
{
	t_fractol	*fractol;
	pthread_t	thread[THREADS];
	t_thread	info[THREADS];
	int			i;

	i = 0;
	fractol = data;
	if (fractol->a.type > 2)
		return (buddah(fractol));
	while (i < THREADS)
	{
		info[i].fractol = fractol;
		info[i].start = i * (fractol->a.img_size / THREADS);
		info[i].finish = (i + 1) * (fractol->a.img_size / THREADS);
		if (pthread_create(thread + i, NULL, (void *)draw_a, info + i))
			exit(1);
		i++;
	}
	while (i-- > 0)
		if (pthread_join(thread[i], NULL))
			clean_exit(fractol);
	put_img_to_window_a(&fractol->mlx, 0, 0);
	fractol->help ? help_a(&fractol->mlx) : 0;
	return (0);
}
