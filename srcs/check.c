#include "fractol.h"

void		check_argv(int argc, char **argv)
{
	int		i;

	if (argc != 2)
		put_usage();
	i = 0;
	if (ft_strequ(argv[1], "-J") || ft_strequ(argv[1], "-M") ||\
	ft_strequ(argv[1], "-Koch") || ft_strequ(argv[1], "-Snow"))
		i = 1;
	(!i) ? put_usage() : 0;
}
