#include "fractol.h"

void		draw_a(void *data)
{
	t_thread	*thread;
	t_point		cur;
	t_complex	point;
	t_complex	step;

	thread = data;
	cur = point_init(0, thread->start);
	step.re = thread->fractol->a.size / thread->fractol->a.img_size;
	step.im = thread->fractol->a.size / thread->fractol->a.img_size;
	point.im = thread->fractol->a.min.im + thread->start * step.im;
	while (cur.y < thread->finish)
	{
		cur.x = 0;
		point.re = thread->fractol->a.min.re;
		while (cur.x < thread->fractol->a.img_size)
		{
			color_init(cur,\
			thread->fractol->a.draw_a[(int)thread->fractol->a.type]\
			(thread->fractol, point), thread->fractol);
			cur.x++;
			point.re += step.re;
		}
		cur.y++;
		point.im += step.im;
	}
}

int			set_julia_c(int x, int y, t_fractol *fractol)
{
	t_complex  min;

	min = fractol->a.min;
	x = x - (WIDTH - fractol->a.img_size) / 2;
	y = y - (HEIGHT - fractol->a.img_size) / 2;
//  Делишь на img_size, умножаешь на size, добавляешь min
	if (x >= 0 && y >= 0 && x < fractol->a.img_size && y < fractol->a.img_size)
	{
		fractol->a.c.re = x * fractol->a.size / fractol->a.img_size + min.re;
		fractol->a.c.im = y * fractol->a.size / fractol->a.img_size + min.im;
	}
	printf("c re %f, c im %f\n", fractol->a.c.re, fractol->a.c.im);
	thread_draw(fractol);
	return (0);
}

void		thread_draw(void *data)
{
	t_fractol	*fractol;
	pthread_t	thread[THREADS];
	t_thread	info[THREADS];
	int			i;

	i = 0;
	fractol = data;
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
}
