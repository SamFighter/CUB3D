#include "cub3d.h"

void		error(char *type, char *arg)
{
	fd_printf("%s\n", type, 2);
	if (arg)
		fd_printf("%s\n", type, 2);
	exit (1);
}
