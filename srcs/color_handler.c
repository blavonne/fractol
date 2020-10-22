#include "fractol.h"

static int	gradient(int start, int finish, double k)
{
	int		r;
	int		g;
	int		b;

	r = ((start >> 16) & 0xFF) * (1 - k) + ((finish >> 16) & 0xFF) * k + 0.5;
	g = ((start >> 8) & 0xFF) * (1 - k) + ((finish >> 8) & 0xFF) * k + 0.5;
	b = (start & 0xFF) * (1 - k) + (finish & 0xFF) * k + 0.5;
	return ((r << 16) | (g << 8) | b);
}

static int	set_color(int color_shift, int iter, int maxiter)
{
	double				k;
	static const int	pal[COLORS] = {IRIS, LILAC, AZURE, ROSE, GRASS, SKY,\
	LINDEN, ORCHID, WHITE};

	k = (double)maxiter / 5;
	if (iter < k)
		return (gradient(WHITE, pal[color_shift % COLORS], iter / k));
	else if (iter < 2 * k)
		return (gradient(pal[color_shift % COLORS + 1],\
				pal[color_shift % COLORS + 2], (iter - k) / k));
	else if (iter < 3 * k)
		return (gradient(pal[color_shift % COLORS + 3],\
				pal[color_shift % COLORS + 4], (iter - 2 * k) / k));
	else if (iter < 4 * k)
		return (gradient(pal[color_shift % COLORS + 5],\
				pal[color_shift % COLORS + 6], (iter - 3 * k) / k));
	else
		return (gradient(pal[color_shift % COLORS + 7],\
				JADE, (iter - 4 * k) / k));
}

void		color_init(t_point cur, int iter, t_fractol *fractol)
{
	int		i;
	int		color;

	i = (cur.y * fractol->a.img_size + cur.x) * (int)sizeof(int);
	color = set_color(fractol->a.color_shift, iter, fractol->a.max_iter);
	if (i < fractol->a.img_size * fractol->a.img_size * sizeof(int))
	{
		fractol->mlx.image.img[i++] = color;
		fractol->mlx.image.img[i++] = color >> 8u;
		fractol->mlx.image.img[i++] = color >> 16u;
		fractol->mlx.image.img[i] = 0;
	}
}