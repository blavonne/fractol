#include "fractol.h"

void		fractol_init(t_fractol *fractol)
{
	fractol->type = 0;
	fractol->help = 0;
	fractol->mlx.mlx = NULL;
	fractol->mlx.win = NULL;
	fractol->mlx.image.img = NULL;
	fractol->mlx.image.ptr = NULL;
	fractol->mlx.background.img = NULL;
	fractol->mlx.background.ptr = NULL;
	fractol->mlx.help.ptr = NULL;
	fractol->mlx.help.img = NULL;
	fractol->g.draw_g[0] = NULL;
	fractol->g.draw_g[1] = NULL;
}
