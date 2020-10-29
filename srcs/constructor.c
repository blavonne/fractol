#include "fractol.h"

void		read_command(void)
{
	char	buf[100];

	ft_putstr("HI! This is constructor-mode.\nList of available functions:\n");
	ft_putstr("cos\nsin\ntan\ndivision\nderivative\n");
	read(1, buf, 100);

}