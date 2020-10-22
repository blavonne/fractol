#include "fractol.h"

int			mandelbrot_iter(t_fractol *fractol, t_complex c)
{
	int			iter;
	t_complex	z;
	double		r;

	iter = 0;
	z = complex_init(0, 0);
	while (iter < fractol->a.max_iter)
	{
		iter++;
		z = complex_square(z);
		z = complex_sum(z, c);
		r = z.re * z.re + z.im * z.im;
		if (r > 4)
			break ;
	}
	return (iter);
}

int			julia_iter(t_fractol *fractol, t_complex z)
{
	t_complex	c;
	double		r;
	int			iter;

	iter = 0;
	c = complex_init(-0.55, -0.55);
	while (iter < fractol->a.max_iter)
	{
		z = complex_square(z);
		z = complex_sum(z, c);
		r = z.re * z.re + z.im * z.im;
		if (r > 4)
			break ;
		iter++;
	}
	return (iter);
}

//var
//		a,b,x,y,x2,y2,xy: real;
//r:real;
//speed,k: integer;
//begin
//		r:=1;
//a:=-0.55; b:=-0.55;
//x:=x0; y:=y0; //это z
//k:=100;
//while (k>0)and(r<4) do
//begin
//x2:=x*x;
//y2:=y*y;
//xy:=x*y;
//x:=x2-y2+a;
//y:=2*xy+b;
//r:=x2+y2;
//dec(k)

//void		mandel_my(t_fractol *fractol)
//{
//	t_point		cur;
//	t_complex	c;
//	t_complex	z;
//	double		step;
//
//	cur = point_init(0, 0);
//	c = complex_init(0+fractol->a.min.re, 0+fractol->a.min.im);
//	step = fractol->a.size / fractol->a.img_size;
//	while (cur.y < fractol->a.img_size)
//	{
//		cur.x = 0;
//		c.re = fractol->a.min.re;
//		while (cur.x < fractol->a.img_size)
//		{
//			z = complex_init(0, 0);
//			color_init(cur, iter_count(fractol, z, c), fractol);
//			cur.x++;
//			c.re += step;
//		}
//		cur.y++;
//		c.im += step;
//	}
//	put_img_to_window_a(&fractol->mlx, 0, 0);
//	fractol->help ? help_a(&fractol->mlx) : 0;
//}
