#include "fractol.h"


int			set_julia_c(int x, int y, t_fractol *fractol)
{
	x = x - (WIDTH - fractol->a.img_size) / 2;
	y = y - (HEIGHT - fractol->a.img_size) / 2;
//	Делишь на img_size, умножаешь на size, добавляешь min
	fractol->a.c.re = x * fractol->a.size / fractol->a.img_size;
	fractol->a.c.im = y * fractol->a.size / fractol->a.img_size;
}

void		thread_draw(void *data)
{
	t_fractol	*fractol;
	pthread_t	thread[THREADS];
	t_thread	info[THREADS];
	int			i;

	i = 0;
	fractol = data;
//	if (fractol->a.type == 1)
//		mlx_hook(fractol->mlx.win_ptr, 6, 1L << 6, set_julia_c, fractol);
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
