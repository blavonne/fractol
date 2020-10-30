#include "fractol.h"

/*
** channel[0] = transparency;
** channel[1] = red;
** channel[2] = green;
** channel[3] = blue;
*/

static void	create_knot(t_geometric *fractol)
{
	t_complex	*kn;

	if (!(kn = (t_complex *)malloc(sizeof(t_complex) * (fractol->buf_size + BUF))))
		exit(1);
	ft_memset(kn, 0, sizeof(t_complex) * (fractol->buf_size + BUF));
	fractol->buf_size = BUF;
	fractol->kn = kn;
}

static void	set_color_schema(t_geometric *fractol, char type)
{
	if (!type || type == 1)
		fractol->argb = int_to_argb(0x00A8D8E6);
	else if (type == 2)
		fractol->argb = int_to_argb(GRASS);
}

void		geometric_init(t_geometric *fractol, char type)
{

	fractol->buf_size = 0;
	fractol->type = type;
	fractol->kn = NULL;
	fractol->buf_size = 0;
	if (!type)
		create_knot(fractol);
	set_color_schema(fractol, type);
	fractol->power = 0;
	fractol->offset.x = 0;
	fractol->offset.y = 0;
	fractol->sign = 1;
	fractol->scale = 1;
	fractol->draw_g[0] = &create_koch;
	fractol->draw_g[1] = &create_snow;
	fractol->draw_g[2] = &tree;
}

void		geometric_resize(t_geometric *fractol)
{
	t_complex	*kn;
	size_t		i;

	i = 0;
	if (!(kn = (t_complex *)malloc(sizeof(t_complex) * (fractol->buf_size + BUF))))
		exit(1);
	ft_memset(kn, 0, sizeof(t_complex) * (fractol->buf_size + BUF));
	while (i <= fractol->buf_size)
	{
		kn[i].im = fractol->kn[i].im;
		kn[i].re = fractol->kn[i].re;
		i++;
	}
	free(fractol->kn);
	fractol->kn = kn;
	fractol->buf_size = fractol->buf_size + BUF;
}
