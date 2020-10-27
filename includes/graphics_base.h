#ifndef GRAPHICS_BASE_H
# define GRAPHICS_BASE_H

# define WIDTH			1024
# define HEIGHT			512

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
void				set_color_pixel(unsigned char *img, int i, int argb);
t_point				point_init(int x, int y);
t_complex			complex_init(double re, double im);
t_complex			complex_sum(t_complex z, t_complex c);
t_complex			complex_sum_abs(t_complex z, t_complex c);
t_complex			complex_multiply(t_complex a, t_complex b);
t_complex			complex_power(t_complex z, int power);
t_complex			not_random();

t_complex			complex_tg(t_complex z);
t_complex			complex_cos(t_complex z);
t_complex			complex_sin(t_complex z);
t_complex			complex_div(t_complex z1, t_complex z2);

#endif
