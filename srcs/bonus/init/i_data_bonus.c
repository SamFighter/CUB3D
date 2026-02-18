#include "bonus.h"

int	init_data_bonus(t_game *game)
{
	game->map.map = get_map_bonus(game->fd, &(game->map.width), game);
	close(game->fd);
	if (game->map.map == NULL)
		return (1);
	if (define_data_map(game) == 1)
	{
		utl_super_free((void **)game->map.map);
		return (1);
	}
	if (check_textures_paths(&game->texture, game) == 1)
	{
		utl_super_free((void **)game->map.map);
		free_data_texture(&game->colors, &game->texture);
		return (1);
	}
	return (0);
}
