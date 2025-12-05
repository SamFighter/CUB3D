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
	printf("reussi\n");
}
