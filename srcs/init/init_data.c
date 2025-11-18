#include "cub3d.h"

int		*init_data(t_game game)
{
	game->map = get_map(game->fd);
	if (game->map == NULL)
		return (1);
}
