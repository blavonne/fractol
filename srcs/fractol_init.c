#include "fractol.h"

void		fractol_init(t_fractol *fractol)
{
	fractol->type = 0;
	fractol->help = 0;
	fractol->mlx.mlx_ptr = NULL;
	fractol->mlx.win_ptr = NULL;
	fractol->mlx.image.img = NULL;
	fractol->mlx.image.ptr = NULL;
	fractol->mlx.background.img = NULL;
	fractol->mlx.background.ptr = NULL;
	fractol->mlx.help.ptr = NULL;
	fractol->mlx.help.img = NULL;
	fractol->g.draw_geometric[0] = NULL;
	fractol->g.draw_geometric[1] = NULL;
}
