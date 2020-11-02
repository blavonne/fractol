/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols_gr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:04:42 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:06:08 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			graffiti(t_fractol *fractol, t_complex c)
{
	int			iter;
	t_complex	z;
	t_complex	tmp;
	double		r;

	iter = 0;
	z = c;
	while (iter < fractol->a.max_iter)
	{
		iter++;
		z = complex_power(z, fractol->a.power + 3);
		c = complex_sin(z);
		c.re -= 1;
		tmp = complex_sin(z);
		tmp.re = -tmp.re;
		tmp.im = -tmp.im;
		tmp = complex_sum(complex_multiply(z, complex_cos(z)), tmp);
		tmp.re += 1;
		z = complex_div(tmp, complex_cos(z));
		z = complex_cos(z);
		r = z.re * z.re + z.im * z.im;
		if (r > 40)
			break ;
	}
	return (iter);
}

int			leaf(t_fractol *fractol, t_complex c)
{
	int			iter;
	t_complex	z;
	double		r;

	iter = 0;
	z = fractol->a.c;
	while (iter < fractol->a.max_iter)
	{
		iter++;
		z = complex_power(z, fractol->a.power - 1);
		z = complex_cos(z);
		z = complex_div(z, c);
		r = z.re * z.re + z.im * z.im;
		if (r > 1000)
			break ;
	}
	return (iter);
}

/*
** Classic newton should have
** power.re = -power.re;
** power.im = -power.im;
** instead of
** power = complex_multiply(power, (t_complex){.re = -1, .im = -1});
*/

int			newton(t_fractol *fractol, t_complex c)
{
	int			iter;
	t_complex	z;
	t_complex	der;
	t_complex	power;
	double		r;

	iter = 0;
	z = c;
	while (iter < fractol->a.max_iter)
	{
		iter++;
		power = complex_power(z, fractol->a.power + 1);
		power.re -= 1;
		der = complex_derivative(z, fractol->a.power + 1);
		power = complex_div(power, der);
		power = complex_multiply(power, (t_complex){.re = -1, .im = -1});
		z = complex_sum(z, power);
		r = z.re * z.re + z.im * z.im;
		if (r > 200)
			break ;
	}
	return (iter);
}

int			peacock(t_fractol *fractol, t_complex c)
{
	int			iter;
	t_complex	z;
	double		r;

	iter = 0;
	z = complex_init(0, 0);
	while (iter < fractol->a.max_iter)
	{
		iter++;
		z = complex_power(z, fractol->a.power);
		z = complex_sin(complex_div(z, c));
		z = complex_sum(z, c);
		r = z.re * z.re + z.im * z.im;
		if (r > 4)
			break ;
	}
	return (iter);
}

int			ring_ring(t_fractol *fractol, t_complex c)
{
	int			iter;
	t_complex	z;
	double		r;

	iter = 0;
	z = complex_init(0, 0);
	while (iter < fractol->a.max_iter)
	{
		iter++;
		z = complex_sum(z, c);
		z = complex_power(z, fractol->a.power);
		z = complex_derivative(z, fractol->a.power + 1);
		z = complex_tg(z);
		r = z.re * z.re + z.im * z.im;
		if (r > 4)
			break ;
	}
	return (iter);
}
