#ifndef FRACTOL_H
# define FRACTOL_H

# define THREADS		16
# define BUF			4
# define SCALE			0.6
# define COLORS			8
# define IRIS			0x7000fa
# define BLUE			0x02107a
# define VIOLET			0x4e02ab
# define ROSE			0x944e71
# define PEACH			0xad5757
# define LINDEN			0xadaa66

# define PURPLE			0x421e01
# define ORCHID			0x6b401d

# define JADE			0xdaede1
# define WHITE			0xffffff
# define BLACK			0x000000

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include "libft.h"
# include "keyboard.h"
# include <pthread.h>
# include <stdio.h>
# include "graphics_base.h"


struct			s_algebraic;
struct			s_geometric;
struct			s_fractol;
struct			s_thread;

typedef struct	s_algebraic
{
	t_complex	z;//julia
	t_complex	c;//julia
	t_complex	min;
	t_complex	max; //не нужной в моей реализации
	double 		size;
	int			(*draw_a[3])(struct s_fractol *fractol, t_complex point);
	int			color_shift;
	int			max_iter;
	int 		img_size;
	int			power;
	char		type;
}				t_algebraic;

typedef struct	s_geometric
{
	t_argb		argb;
	t_complex	*kn;
	t_point		offset;
	double		scale;
	size_t		size;
	int			n;
	char		sign;
	void		(*draw_geometric[2])(struct s_fractol *fractol);
	char		type;
}				t_geometric;

/*
** sign - переключатель нумпада с режима "+" на режим "-"
** offset - сдвиг для move
** n - количество приближений
** kn - координаты
*/

typedef struct	s_fractol
{
	t_algebraic	a;
	t_geometric	g;
	t_mlx		mlx;
	char		type; //какой фрактал выбран
	char		help; //вызвано ли меню
}				t_fractol;

typedef struct	s_thread
{
	t_fractol	*fractol;
	int			start;
	int			finish;
}				t_thread;

void			put_usage(void);
void			fractol_init(t_fractol *fractol);
void			algebaic_init(t_algebraic *fractol, char type);
void			geometric_init(t_geometric *fractol);
void			geometric_resize(t_geometric *fractol);
void			check_argv(int argc, char **str);
int				read_argv(char *type, t_fractol *fractol);
void			draw_a(void *info);
void			thread_draw(void *data);
int				mandelbrot(t_fractol *fractol, t_complex c);
int				julia(t_fractol *fractol, t_complex z);
int				burning(t_fractol *fractol, t_complex c);
void			color_init(t_point cur, int iter, t_fractol *fractol);
int				deal_key(int key, t_fractol *fractol);
t_complex		complex_init(double re, double im);

void			win_destroy(t_mlx *mlx);
void			mlx_destroy(t_mlx *mlx);
void			img_destroy(t_mlx *mlx);
int				clean_exit(void *param);
void			clean_knot(t_fractol *fractol);//ДОБАВИТЬ
void			destroy_fractol(t_fractol *fractol);
void			restore_to_default_a(t_fractol *fractol);
void			restore_to_default_g(t_fractol *fractol);

void			help_g(t_mlx *mlx);
void			help_a(t_mlx *mlx);
void			zoom_g(t_fractol *fractol, int key);
int				zoom_a(int key, int x, int y, t_fractol *fractol);
void			move_a(int key, t_fractol *fractol);
void			move_g(int key, t_fractol *fractol);
void			increase_img_color(int key, t_fractol *fractol);
void			put_img_to_window_g(t_mlx *mlx, int x, int y);
void			put_img_to_window_a(t_mlx *mlx, int x, int y);


void			create_koch(t_fractol *fractol);
void			create_snow(t_fractol *fractol);
void			draw_line(t_point start, t_point end, t_fractol *fractol);

int			set_julia_c(int x, int y, t_fractol *fractol);

#endif
