/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_usage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:30:07 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 16:30:11 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_usage(void)
{
	ft_putstr("Fractol by Barrett Lavonne :)\n");
	ft_putstr("Usage: ./fractol -flag\nFlags:\n-Mandelbrot\n-Julia\n-Ship\n");
	ft_putstr("-Buddha\n-Abuddha\n-Antoshka\n-Koch\n-Snow\n-Tree\n-Pifagor\n");
	ft_putstr("-Trident\n-Turtle\n-Ring\n-Cactus\n-Leaf\n-Peacock\n-Newton\n");
	ft_putstr("-Web\n-Butterfly\n-Circle\n-Graffiti\n-Batman\n");
	exit(0);
}
