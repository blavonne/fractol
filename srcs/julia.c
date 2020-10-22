#include "fractol.h"

void	julia(void *info)
{
	t_fractol	*fractol;
	t_point		cur;
	t_complex	z;

	fractol = info;
	cur = point_init(0, 0);
	ft_bzero(fractol->mlx.image.img, fractol->a.img_size * fractol->a.img_size *
	sizeof(int));
	while (cur.y < fractol->a.img_size)
	{
		cur.x = 0;
		while (cur.x < fractol->a.img_size)
		{
			z = fractol->a.c;
			color_init(cur, iter_count(fractol, z, fractol->a.c), fractol);
			cur.x++;
		}
		cur.y++;
	}
	put_img_to_window_a(&fractol->mlx, 0, 0);
	fractol->help ? help_a(&fractol->mlx) : 0;
}
