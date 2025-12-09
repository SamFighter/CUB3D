#include "cub3d.h"

int	init_data(t_game *game)
{
	game->map = get_map(game->fd);
	if (game->map == NULL)
		return (1);
	if (define_data_map(game) == 1)
	{
		utl_super_free((void **)game->map);
		return (1);
	}
	if (check_textures_paths(&game->textures) == 1)
	{
		utl_super_free((void **)game->map);
		free_data_texture(&game->colors, &game->textures);
		return (1);
	}
	return (0);
}
