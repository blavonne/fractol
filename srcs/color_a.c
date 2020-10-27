#include "fractol.h"

int	gradient(int start, int finish, double k)
{
	int		r;
	int		g;
	int		b;

	r = ((start >> 16) & 0xFF) * (1 - k) + ((finish >> 16) & 0xFF) * k + 0.5;
	g = ((start >> 8) & 0xFF) * (1 - k) + ((finish >> 8) & 0xFF) * k + 0.5;
	b = (start & 0xFF) * (1 - k) + (finish & 0xFF) * k + 0.5;
	return ((r << 16) | (g << 8) | b);
}

static void	set_palette(int *palette, char type)
{
	const int	iris_gold[COLORS] = {IRIS, DEEP_BLUE, VIOLET, ROSE, PEACH,\
	LINDEN, WHITE, JADE};
	const int	burning_sea[COLORS] = {DUSK, DARK_GOLD, BROWN, ORANGE, GOLD,\
	YELLOW, WHITE, CIAN};
	const int	red_gold[COLORS] = {VINE, BROWN, LIGHT_BROWN, ORANGE, GOLD,\
	YELLOW, WHITE, BLOOD};

	if (type == 0)
		ft_memcpy(palette, red_gold, sizeof(int) * 8);
	else if (type == 1)
		ft_memcpy(palette, iris_gold, sizeof(int) * 8);
	else if (type == 2)
		ft_memcpy(palette, burning_sea, sizeof(int) * 8);
	else if (type == 3)
		ft_memcpy(palette, red_gold, sizeof(int) * 8);
}

/*
** если цвета в этом коде расположить 01 12 23 34, то будет плавный переход
*/

int	set_color(char type, int iter, int maxiter)
{
	double	k;
	int		palette[COLORS];

	set_palette(palette, type);
	k = (double)maxiter / 7;
	if (iter < k)
		return (gradient(palette[6], palette[0], iter / k));
	else if (iter < 2 * k)
		return (gradient(palette[0], palette[1], (iter - k) / k));
	else if (iter < 3 * k)
		return (gradient(palette[1], palette[2], (iter - 2 * k) / k));
	else if (iter < 4 * k)
		return (gradient(palette[2], palette[3], (iter - 3 * k) / k));
	else if (iter < 5 * k)
		return (gradient(palette[3], palette[4], (iter - 4 * k) / k));
	else if (iter < 6 * k)
		return (gradient(palette[4], palette[5], (iter - 5 * k) / k));
	else
		return (gradient(palette[5], palette[7], (iter - 6 * k) / k));
}

void		color_init(t_point cur, int iter, t_fractol *fractol)
{
	int		i;
	int		color;

	if (fractol->type != 3)
	{
		i = (cur.y * fractol->a.img_size + cur.x) * (int)sizeof(int);
		color = set_color(fractol->a.type, iter, fractol->a.max_iter);
		if (i < fractol->a.img_size * fractol->a.img_size * (int)sizeof(int))
		{
			fractol->mlx.image.img[i++] = color;
			fractol->mlx.image.img[i++] = (unsigned)color >> 8u;
			fractol->mlx.image.img[i++] = (unsigned)color >> 16u;
			fractol->mlx.image.img[i] = 0;
		}
	}
}

void		set_color_pixel(unsigned char *img, int i, int argb)
{
	img[i] = (char)argb;
	img[i + 1] = (char)((unsigned)argb >> 8u);
	img[i + 2] = (char)((unsigned)argb >> 16u);
	img[i + 3] = (char)((unsigned)argb >> 24u);
}
