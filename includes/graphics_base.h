#ifndef GRAPHICS_BASE_H
# define GRAPHICS_BASE_H

# define WIDTH			1600
# define HEIGHT			1024

# include <stdlib.h>
# include "mlx.h"
# include "libft.h"
# include <math.h>

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_image
{
	void			*ptr;
	unsigned char	*img;
	int				endian;
	int				size_line; //number of bytes used to store one line of image
	int				bps;
}					t_image;

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct		s_argb
{
	unsigned char	channel[4];
}					t_argb;


typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_image			help;
	t_image			image;
	t_image			background;
}					t_mlx;

void				*create_mlx(void);
t_image				create_img(t_mlx *mlx, int width, int height);
void				create_background(t_mlx *mlx, int width, int height, int\
					color);
void				*create_win(t_mlx *mlx, int width, int height, char *name);
void				colorize(unsigned char *img, int width, int height,\
					unsigned int color);
t_argb				int_to_argb(unsigned int value);
void				set_color_pixel(unsigned char *img, int i, int argb);
t_point				point_init(int x, int y);
t_point				complex_to_screen(t_complex complex, t_complex size,\
					t_complex min, t_point start);
t_complex			complex_init(double re, double im);
t_complex			screen_to_complex(t_point point, t_complex size,\
					t_point min, t_complex start);
t_complex			not_random();
t_complex			complex_sum(t_complex z, t_complex c);
t_complex			complex_sum_abs(t_complex z, t_complex c);
t_complex			complex_multiply(t_complex a, t_complex b);
t_complex			complex_power(t_complex z, int power);
t_complex			complex_div(t_complex z1, t_complex z2);
t_complex			complex_tg(t_complex z);
t_complex			complex_cos(t_complex z);
t_complex			complex_sin(t_complex z);
t_complex			complex_derivative(t_complex z, int k);
t_complex			complex_ln(t_complex z);

#endif
