#include "cub3d.h"

static int	init_all(t_game *game)
{
	init_colors(game);
	init_textures(game);
	init_data(game);
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

	init_all(game);
	if (game == NULL)
		return (1);
	printf("reussi\n");
}
