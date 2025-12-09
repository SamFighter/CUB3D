#include "cub3d.h"

void	error(char *type, char *arg)
{
	fd_printf(2, "%s ", type);
	if (arg)
		fd_printf(2, "\"%s\"\n", arg);
	exit (1);
}
