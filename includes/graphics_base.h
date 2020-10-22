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
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			help;
	t_image			image;
	t_image			background;
	t_image			button;
}					t_mlx;

void				mlx_create(t_mlx *mlx, int width, int height);
void				create_image(t_mlx *mlx, int width, int height);
void				create_background(t_mlx *mlx, int width, int height, int\
					color);
void				create_window(t_mlx *mlx, int width, int height, char *name);
void				colorize(unsigned char *img, int width, int height,\
					unsigned int color);
t_point				point_init(int x, int y);
t_complex			complex_init(double re, double im);
t_complex			complex_square(t_complex z);
t_complex			complex_sum(t_complex z, t_complex c);
t_complex			abs_square_sum(t_complex z, t_complex c);

#endif
