#include "cub3d.h"

static int		init_all(t_game *game)
{
	init_colors(game);
	init_textures(game);
	if (init_data(game) == 1)
		return (1);
	return (0);
}
static int		check_args(int ac, char **av)
{
	if (ac != 2)
		error(ARGS, NULL);
	else if (check_name_file(av[1]) == 1)
		error(EXTENSION, av[1]);
	else
		return (0);
	return (1);
}
int main(int ac, char **av)
{
	t_game	game;

	if (check_args(ac, av) == 1)
		return (1);
	game.fd = get_fd(av[1]);
	if (game.fd == -1)
		return (1);
	if (init_all(&game) == 1)
		return (1);
	ft_printf("MAP :\n\n%S\n\nDATA_MAP :\n%S\n\n", game.map, game.data_map);
	printf("fd map : %d\n\n", game.fd);
	printf("textures :\nNorth : %s\nSouth : %s\nWest : %s\nEast : %s\n", game.textures.north, game.textures.south, game.textures.west, game.textures.east);
	printf("\ncolors en char : \nFloor : %s\nCeiling : %s\n", game.colors.c_floor, game.colors.c_ceiling);
	printf("\ncolors en int : \nFloor : %d , %d , %d\nCeiling : %d , %d , %d\n", game.colors.i_floor[0], game.colors.i_floor[1], game.colors.i_floor[2], game.colors.i_ceiling[0], game.colors.i_ceiling[1], game.colors.i_ceiling[2]);
}
