#include "cub3d.h"

static char		*set_data(char *line)
{
	int		i;

	i = 0;
	while (ctn_iswhitespace(line[i]))
		i++;
	if ((line[i] == 'C' || line[i] == 'F') && (str_len(line) > 3))
		return (str_substr(line, i + 2, str_len(line)));
	else if (line[i] == '.' && line[i + 1] == '/')
		return (str_substr(line, i + 2, str_len(line)));
	return (NULL);
}

static int		set_data_map(t_game game, int i, int j)
{
	char	*sub;

	sub = str_substr(game->map[j], i, str_lchr(game->map[j][i]));
	if (game->texture.north == NULL && str_ncmp(sub, "NO", 3) == 0)
		game->texture.north = set_data(sub);
	else if (game->texture.south == NULL && str_ncmp(sub, "SO", 3) == 0)
		game->texture.south = set_data(sub);
	else if (game->texture.west == NULL && str_ncmp(sub, "WE", 3) == 0)
		game->texture.west = set_data(sub);
	else if (game->texture.east == NULL && str_ncmp(sub, "EA", 3) == 0)
		game->texture.east = set_data(sub);
	else if (game->colors.c_floor == NULL && str_ncmp(sub, "F", 2) == 0)
		game->colors.c_floor = set_data(sub);
	else if (game->colors.c_ceilling == NULL && str_ncmp(sub, "C", 2) == 0)
		game->colors.c_ceilling = set_data(sub);
}
