/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:35:39 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:35:51 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_a(void *data)
{
	t_thread	*thread;
	t_point		screen;
	t_complex	complex;
	t_complex	step;

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
			color_init(screen, thread->fractol->a.draw_a\
			[(int)thread->fractol->a.type](thread->fractol, complex),\
			thread->fractol);
			screen.x++;
			complex.re += step.re;
		}
		screen.y++;
		complex.im += step.im;
	}
}

int			rendering(void *data)
{
	t_fractol	*fractol;
	pthread_t	thread[THREADS];
	t_thread	info[THREADS];
	int			i;

	i = -1;
	fractol = data;
	if (fractol->a.type == 16 || fractol->a.type == 17)
		return (buddha(fractol));
	if (fractol->type)
		return (0);
	while (++i < THREADS)
	{
		info[i].fractol = fractol;
		info[i].start = i * (fractol->a.img_size / THREADS);
		info[i].finish = (i + 1) * (fractol->a.img_size / THREADS);
		if (pthread_create(thread + i, NULL, (void *)draw_a, info + i))
			exit(1);
	}
	while (i-- > 0)
		if (pthread_join(thread[i], NULL))
			clean_exit(fractol);
	put_img_to_window_a(&fractol->mlx, 0, 0);
	fractol->help ? help_a(&fractol->mlx) : 0;
	return (0);
}
