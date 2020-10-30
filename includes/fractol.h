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
# include <stdio.h>

typedef struct	s_algebraic	t_algebraic;
typedef struct	s_geometric	t_geometric;
typedef struct	s_fractol	t_fractol;
typedef struct	s_thread	t_thread;
typedef struct	s_map		t_map;
typedef enum	e_types		t_types;

struct			s_map
{
	t_complex	z[2000];
	int			size;
};

enum			e_types
{
	Mandelbrot,
	Julia,
	Ship,
	Antoshka,
	Trident,
	Turtle,
	Cactus,
	Ring,
	Leaf,
	Peacock,
	Buddha,
	Abuddha,
	Koch,
	Snowflake,
};

struct			s_algebraic
{
	t_complex	z;//julia
	t_complex	c;//julia
	t_complex	min;
	t_complex	max;
	double 		size;
	char		*name;
	int			(*draw_a[10])(struct s_fractol *fractol, t_complex point);
	int			max_iter;
	int 		img_size;
	int			power;
	char		type;
	char		motion_on;
	char		color_schema;//пока не используется
};

struct			s_geometric
{
	t_argb		argb;
	t_complex	*kn;
	t_point		offset;
	double		scale;
	size_t		buf_size;
	void		(*draw_g[3])(struct s_fractol *fractol);
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
** sign - переключатель нумпада с режима "+" на режим "-"
** offset - сдвиг для move
** n - количество приближений
** kn - координаты
*/

struct			s_fractol
{
	t_algebraic	a;
	t_geometric	g;
	t_mlx		mlx;
	char		type; //какой фрактал выбран
	char		help; //вызвано ли меню
};

struct			s_thread
{
	t_fractol	*fractol;
	int			start;
	int			finish;
};

void			put_usage(void);
void			fractol_init(t_fractol *fractol);
void			algebaic_init(t_algebraic *fractol, char type);
void			geometric_init(t_geometric *fractol, char type);
void			set_color_schema_g(t_geometric *fractol, char type);
void			geometric_resize(t_geometric *fractol);
int				check_argv(int argc, char **str);
int				read_argv(int type, t_fractol *fractol);
void			draw_a(void *info);
int				rendering(void *data);
int				mandelbrot(t_fractol *fractol, t_complex c);
int				julia(t_fractol *fractol, t_complex z);
int				julia_motion(int x, int y, t_fractol *fractol);
int				burning(t_fractol *fractol, t_complex c);
int				antoshka(t_fractol *fractol, t_complex c);
int				trident(t_fractol *fractol, t_complex c);
int				turtle(t_fractol *fractol, t_complex c);
int				cactus(t_fractol *fractol, t_complex c);
int				ring_ring(t_fractol *fractol, t_complex c);
int				leaf(t_fractol *fractol, t_complex c);
int				peacock(t_fractol *fractol, t_complex c);

void			color_init(t_point cur, int iter, t_fractol *fractol);
int				key_pressed(int key, t_fractol *fractol);

int				clean_exit(void *param);

void			help_g(t_mlx *mlx);
void			help_a(t_mlx *mlx);
void			zoom_g(t_fractol *fractol, int key);
int				zoom_a(int key, int x, int y, t_fractol *fractol);
void			move_a(int key, t_fractol *fractol);
void			move_g(int key, t_fractol *fractol);
void			increase_img_color(int key, t_fractol *fractol);
void			put_img_to_window_g(t_mlx *mlx, int x, int y);
void			put_img_to_window_a(t_mlx *mlx, int x, int y);

void			koch(t_fractol *fractol);
void			snow(t_fractol *fractol);
void			tree(t_fractol *fractol);
void			draw_line(t_point start, t_point end, t_fractol *fractol);

void			help_handler(int key, t_fractol *fractol);
void			type_handler_a(int *key, t_fractol *fractol);
void			type_handler_g(int key, t_fractol *fractol);

int				buddha(t_fractol *fractol);
int				gradient(int start, int finish, double k);
int				set_color(char type, int iter, int maxiter);


#endif
