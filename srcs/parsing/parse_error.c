#include "cub3d.h"

void		error(char *type, char *arg)
{
	fd_printf(2, "%s\n", type);
	if (arg)
		fd_printf(2, "%s\n", type);
	exit (1);
}
