#include "fractol.h"

static void		prepare_coords(t_point *start, t_point *end, int *steep)
{
	end->y = -end->y;
	start->y = -start->y;
	//OY up+ down-
	*steep = (abs(end->y - start->y) > abs(end->x - start->x)) ? 1 : 0;
	//OY is longer than OX
	if (*steep) //if OY is longer than reverse coords
	{
		ft_swap(&start->x, &start->y);
		ft_swap(&end->x, &end->y);
	}
	if (start->x > end->x) //if directory is negative than reverse directory
	{
		ft_swap(&start->x, &end->x);
		ft_swap(&start->y, &end->y);
	}
}

static void		sketch(t_fractol *fractol, t_point cur, int steep)
{
	int		i;

	if (steep)
		ft_swap(&cur.x, &cur.y);
	i = (cur.x * fractol->mlx.image.bps / 8) + (cur.y *\
	fractol->mlx.image.size_line);
	if (i >= 0 && i < WIDTH * HEIGHT * (int)sizeof(int))
	{
		fractol->mlx.image.img[i++] = fractol->g.argb.channel[3];
		fractol->mlx.image.img[i++] = fractol->g.argb.channel[2];
		fractol->mlx.image.img[i++] = fractol->g.argb.channel[1];
		fractol->mlx.image.img[i] = fractol->g.argb.channel[0];
	}
}

void			draw_line(t_point start, t_point end, t_fractol *fractol)
{
	int		steep;
	t_point	delta;
	int		error;
	int		offset_y;
	t_point	cur;

	prepare_coords(&start, &end, &steep);
	delta.x = end.x - start.x;
	delta.y = abs(end.y - start.y);
	error = delta.x / 2;
	offset_y = start.y < end.y ? 1 : -1;
	cur = start;
	if (!fractol->mlx.image.ptr)
		fractol->mlx.image = create_img(&fractol->mlx, WIDTH, HEIGHT);
	while (cur.x <= end.x)
	{
		sketch(fractol, cur, steep);
		error -= delta.y;
		if (error < 0)
		{
			cur.y += offset_y;
			error += delta.x;
		}
		cur.x++;
	}
}
