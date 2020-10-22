#include "fractol.h"

void		geometric_init(t_geometric *fractol)
{
	t_complex	*kn;

	fractol->size = 0;
	if (!(kn = (t_complex *)malloc(sizeof(t_complex) * (fractol->size + BUF))))
		exit(1);
	ft_memset(kn, 0, sizeof(t_complex) * (fractol->size + BUF));
	fractol->size = BUF;
	fractol->argb.channel[0] = 0; //a
	fractol->argb.channel[1] = 120; //r
	fractol->argb.channel[2] = 167; //g
	fractol->argb.channel[3] = 242; //b
	fractol->kn = kn;
	fractol->n = 0;
	fractol->offset.x = 0;
	fractol->offset.y = 0;
	fractol->sign = 1;
	fractol->scale = 1;
	fractol->type = 0;
	fractol->draw_geometric[0] = &create_koch;
	fractol->draw_geometric[1] = &create_snow;
}

void		geometric_resize(t_geometric *fractol)
{
	t_complex	*kn;
	size_t		i;

	i = 0;
	if (!(kn = (t_complex *)malloc(sizeof(t_complex) * (fractol->size + BUF))))
		exit(1);
	ft_memset(kn, 0, sizeof(t_complex) * (fractol->size + BUF));
	while (i <= fractol->size)
	{
		kn[i].im = fractol->kn[i].im;
		kn[i].re = fractol->kn[i].re;
		i++;
	}
	free(fractol->kn);
	fractol->kn = kn;
	fractol->size = fractol->size + BUF;
}
