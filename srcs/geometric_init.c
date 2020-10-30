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

	if (!(kn = (t_complex *)malloc(sizeof(t_complex) *\
	(fractol->buf_size + BUF))))
		exit(1);
	ft_memset(kn, 0, sizeof(t_complex) * (fractol->buf_size + BUF));
	fractol->buf_size = BUF;
	fractol->kn = kn;
}

void		set_color_schema_g(t_geometric *fractol, char type)
{
	if (!type || type == 1)
		fractol->argb = int_to_argb(AZURE);
	else if (type == 2 || type == 3)
		fractol->argb = int_to_argb(GRASS);
}

void		geometric_init(t_geometric *fractol, char type)
{
	fractol->type = type;
	fractol->kn = NULL;
	fractol->buf_size = 0;
	create_knot(fractol);
	set_color_schema_g(fractol, type);
	fractol->min = complex_init(-1, -1);
	fractol->max = complex_init(2, 1);
	fractol->size = complex_init(fractol->max.re - fractol->min.re,\
	fractol->max.im - fractol->min.im);
	fractol->power = 0;
	fractol->offset = point_init(0, 0);
	fractol->sign = 1;
	fractol->scale = 1;
	fractol->bough_count = 2;
	fractol->bough_angle = 0.5;
	fractol->draw_g[0] = &koch;
	fractol->draw_g[1] = &snow;
	fractol->draw_g[2] = &tree;
	fractol->draw_g[3] = &pifagor;
}

void		geometric_resize(t_geometric *fractol)
{
	t_complex	*kn;
	size_t		i;

	i = 0;
	if (!(kn = (t_complex *)malloc(sizeof(t_complex) *\
	(fractol->buf_size + BUF))))
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
