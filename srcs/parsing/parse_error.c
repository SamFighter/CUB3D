#include "cub3d.h"

void		error(int type, char *arg)
{
	if (type == MAP)
		utl_putstr_fd("Error : Invalid map\n", 2);
	else if (type == BAD_FILE)
	{
		utl_putstr_fd("Error :\n");
		perror(arg);
	}

}
