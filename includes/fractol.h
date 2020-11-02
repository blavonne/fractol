/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:43:49 by blavonne          #+#    #+#             */
/*   Updated: 2020/10/31 15:43:53 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define THREADS		16
# define BUF			4
# define SCALE			0.6

# include "mlx.h"
# include "graphics_base.h"
# include "colors.h"
# include "keyboard.h"
# include "libft.h"
# include <math.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_algebraic	t_algebraic;
typedef struct s_geometric	t_geometric;
typedef struct s_fractol	t_fractol;
typedef struct s_thread		t_thread;
typedef struct s_map		t_map;

/*
** need for Buddha
*/
struct			s_map
{
	t_complex	z[2000];
	int			size;
};

/*
** c is for Julia
** min, max is for diagram
** size should be complex, but I draw my image in square, so size.re and
** size.im are the same
** power is z^(power)
** type is a-type
** motion_on is about Julia
*/
struct			s_algebraic
{
	t_complex	c;
	t_complex	min;
	t_complex	max;
	double		size;
	int			(*draw_a[16])(struct s_fractol *fractol, t_complex point);
	int			max_iter;
	int			img_size;
	int			power;
	char		type;
	char		motion_on;
	char		color_schema;
};

/*
** sign - increase/decrease mode
** offset is for move
** power is count of peaces by step
** kn - vertexes (knots)
** scale = percent zoom (I do not use zoom in geometric cause left side of image
** appears on the right and right side appears on the left)
** buf_size is allocated size of *kn
** min, max, size are about complex plane for imagine diagram
** top is used by tree to set start diagram's point
** bough_angle, bough_count are used by tree -- it's good to bind this
** values to the button and change them ;)
** type is g-type
*/
struct			s_geometric
{
	t_argb		argb;
	t_complex	*kn;
	t_point		offset;
	double		scale;
	size_t		buf_size;
	void		(*draw_g[4])(struct s_fractol *fractol);
	int			power;
	t_complex	min;
	t_complex	max;
	t_complex	size;
	t_complex	top;
	double		bough_angle;
	char		bough_count;
	char		type;
	char		sign;
};

/*
** type is algebraic(0) or geometric(1)
** help means help is on/off
*/
struct			s_fractol
{
	t_algebraic	a;
	t_geometric	g;
	t_mlx		mlx;
	char		type;
	char		help;
};

/*
** s_thread includes t_fractol and draws image from start to finish thread by
** thread
*/
struct			s_thread
{
	t_fractol	*fractol;
	int			start;
	int			finish;
};

/*
** Main part -- read arg & initialize fractol
*/
int				read_argv(int type, t_fractol *fractol);
int				check_argv(int argc, char **str);
void			put_usage(void);
void			fractol_init(t_fractol *fractol);

/*
** Algebraic initialize and algebraic algorithms
*/
void			algebaic_init(t_algebraic *fractol, char type);
int				antoshka(t_fractol *fractol, t_complex c);
int				burning(t_fractol *fractol, t_complex c);
int				cactus(t_fractol *fractol, t_complex c);
int				leaf(t_fractol *fractol, t_complex c);
int				julia(t_fractol *fractol, t_complex z);
int				mandelbrot(t_fractol *fractol, t_complex c);
int				newton(t_fractol *fractol, t_complex c);
int				peacock(t_fractol *fractol, t_complex c);
int				ring_ring(t_fractol *fractol, t_complex c);
int				trident(t_fractol *fractol, t_complex c);
int				turtle(t_fractol *fractol, t_complex c);
int				web(t_fractol *fractol, t_complex c);
int				graffiti(t_fractol *fractol, t_complex c);
int				circle(t_fractol *fractol, t_complex c);
int				butterfly(t_fractol *fractol, t_complex c);
int				batman(t_fractol *fractol, t_complex c);
int				buddha(t_fractol *fractol);

/*
** Render part - set color and thread-draw image
*/
int				julia_motion(int x, int y, t_fractol *fractol);
void			draw_a(void *info);
void			color_init(t_point cur, int iter, t_fractol *fractol);
int				gradient(int start, int finish, double k);
int				set_color(char type, int iter, int maxiter);
int				rendering(void *data);

/*
** Additional stuff: move, zoom, increase power, call help, clean exit
*/
void			put_img_to_window_g(t_mlx *mlx, int x, int y);
void			put_img_to_window_a(t_mlx *mlx, int x, int y);
int				key_pressed(int key, t_fractol *fractol);
void			help_g(t_mlx *mlx);
void			help_a(t_mlx *mlx);
void			zoom_g(t_fractol *fractol, int key);
int				zoom_a(int key, int x, int y, t_fractol *fractol);
void			move_a(int key, t_fractol *fractol);
void			move_g(int key, t_fractol *fractol);
void			increase_img_color(int key, t_fractol *fractol);
void			help_handler(int key, t_fractol *fractol);
void			type_handler_a(int *key, t_fractol *fractol);
void			type_handler_g(int key, t_fractol *fractol);
int				clean_exit(void *param);

/*
** Geometric initialize and geometric algorithms
*/
void			geometric_init(t_geometric *fractol, char type);
void			set_color_schema_g(t_geometric *fractol, char type);
void			geometric_resize(t_geometric *fractol);
void			koch(t_fractol *fractol);
void			set_coords(t_point *begin, t_point *end, int i, t_geometric *g);
void			traf(t_complex start, t_complex end, t_geometric *g, size_t r);
void			snow(t_fractol *fractol);
void			tree(t_fractol *fractol);
void			pifagor(t_fractol *fractol);
void			draw_line(t_point start, t_point end, t_fractol *fractol);

#endif
