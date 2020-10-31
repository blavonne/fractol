#include "fractol.h"

int			gradient(int start, int finish, double k)
{
	int		r;
	int		g;
	int		b;

	r = ((start >> 16) & 0xFF) * (1 - k) + ((finish >> 16) & 0xFF) * k + 0.5;
	g = ((start >> 8) & 0xFF) * (1 - k) + ((finish >> 8) & 0xFF) * k + 0.5;
	b = (start & 0xFF) * (1 - k) + (finish & 0xFF) * k + 0.5;
	return ((r << 16) | (g << 8) | b);
}


static void	set_palette2(int *palette, char schema)
{
	const int	peacock[COLORS] = {WHITE, DARK_GREEN, GREEN_BLUE, DARK_GOLD,\
	DARK_GOLD, IRELAND, AZURE, DARK_BLUE};
	const int	web[COLORS] = {BLACK, WHITE, DARK_GREY, DARK_GREY,\
	BLACK, WHITE, DARK_GREY, DARK_GREY};
	const int	garden[COLORS] = {ROSE, BLOOD, GRASS, YELLOW,\
	AZURE, GOLD, BLACK, WHITE};
	const int	graffiti[COLORS] = {WHITE, YELLOW, GRASS, LEMON,\
	DARK_GOLD, GOLD, ORANGE, CIAN};

	if (schema == 5)
		ft_memcpy(palette, peacock, sizeof(int) * 8);
	else if (schema == 6)
		ft_memcpy(palette, web, sizeof(int) * 8);
	else if (schema == 7)
		ft_memcpy(palette, garden, sizeof(int) * 8);
	else if (schema == 8)
		ft_memcpy(palette, graffiti, sizeof(int) * 8);
}


static void	set_palette(int *palette, char schema)
{
	const int	iris_gold[COLORS] = {WHITE,IRIS, DEEP_BLUE, VIOLET, ROSE,\
	PEACH, LINDEN,  JADE};
	const int	burning_sea[COLORS] = {WHITE, DUSK, DARK_GOLD, BROWN, ORANGE,\
	GOLD, YELLOW, CIAN};
	const int	red_gold[COLORS] = {WHITE, VINE, BROWN, LIGHT_BROWN, ORANGE,\
	GOLD, YELLOW, BLOOD};
	const int	leaf[COLORS] = {LIGHT_JADE, DARK_GREEN, GREEN_BLUE, DARK_GOLD,\
	DARK_GOLD, IRELAND, AZURE, WHITE};
	const int	cactus[COLORS] = {YELLOW, DEEP_PEACH, DARK_GOLD, GOLD, ORANGE,\
	LIGHT_BROWN, BROWN, WARM_GREEN};

	if (!schema)
		ft_memcpy(palette, red_gold, sizeof(int) * 8);
	else if (schema == 1)
		ft_memcpy(palette, iris_gold, sizeof(int) * 8);
	else if (schema == 2)
		ft_memcpy(palette, burning_sea, sizeof(int) * 8);
	else if (schema == 3)
		ft_memcpy(palette, cactus, sizeof(int) * 8);
	else if (schema == 4)
		ft_memcpy(palette, leaf, sizeof(int) * 8);
	else
		set_palette2(palette, schema);
}

/*
** если цвета в этом коде расположить 01 12 23 34, то будет плавный переход
** 7 - количество секций, можно поставить другое
*/

int			set_color(char schema, int iter, int maxiter)
{
	double	k;
	int		palette[COLORS];

	set_palette(palette, schema);
	k = (double)maxiter / 7;
	if (iter < k)
		return (gradient(palette[0], palette[1], iter / k));
	else if (iter < 2 * k)
		return (gradient(palette[1], palette[2], (iter - k) / k));
	else if (iter < 3 * k)
		return (gradient(palette[2], palette[3], (iter - 2 * k) / k));
	else if (iter < 4 * k)
		return (gradient(palette[3], palette[4], (iter - 3 * k) / k));
	else if (iter < 5 * k)
		return (gradient(palette[4], palette[5], (iter - 4 * k) / k));
	else if (iter < 6 * k)
		return (gradient(palette[5], palette[6], (iter - 5 * k) / k));
	else
		return (gradient(palette[6], palette[7], (iter - 6 * k) / k));
}

void		color_init(t_point cur, int iter, t_fractol *fractol)
{
	int		i;
	int		color;

	if (fractol->type != 3)
	{
		i = (cur.y * fractol->a.img_size + cur.x) * (int)sizeof(int);
		color = set_color(fractol->a.color_schema, iter, fractol->a.max_iter);
		if (i < fractol->a.img_size * fractol->a.img_size * (int)sizeof(int))
		{
			fractol->mlx.image.img[i++] = color;
			fractol->mlx.image.img[i++] = (unsigned)color >> 8u;
			fractol->mlx.image.img[i++] = (unsigned)color >> 16u;
			fractol->mlx.image.img[i] = 0;
		}
	}
}
