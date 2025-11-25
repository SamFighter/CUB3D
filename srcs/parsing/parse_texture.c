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

void			free_data_texture(t_colors colors, t_textures textures)
{
	if (textures)
	{
		if (textures->north)
			free(textures->north);
		if (textures->south)
			free(textures->south);
		if (textures->west)
			free(textures->west);
		if (textures->east)
			free(textures->east);
	}
	if (colors)
	{
		if (colors->c_floor)
			free(colors->c_floor);
		if (colors->c_ceilling)
			free(colors->c_ceilling);
	}
}

static int		set_data_map(t_game game, int i, int j)
{
	char	*sub;

	sub = str_substr(game->map[j], i, str_lchr(&game->map[j][i]));
	if (game->texture.north == NULL && str_ncmp(sub, "NO", 3) == 0)
		game->texture.north = set_data(&game->map[j][i + 2]);
	else if (game->texture.south == NULL && str_ncmp(sub, "SO", 3) == 0)
		game->texture.south = set_data(&game->map[j][i + 2]);
	else if (game->texture.west == NULL && str_ncmp(sub, "WE", 3) == 0)
		game->texture.west = set_data(&game->map[j][i + 2]);
	else if (game->texture.east == NULL && str_ncmp(sub, "EA", 3) == 0)
		game->texture.east = set_data(&game->map[j][i + 2]);
	else if (game->colors.c_floor == NULL && str_ncmp(sub, "F", 2) == 0)
		game->colors.c_floor = set_data(&game->map[j][i + 1]);
	else if (game->colors.c_ceilling == NULL && str_ncmp(sub, "C", 2) == 0)
		game->colors.c_ceilling = set_data(&game->map[j][i + 1]);
	else if (str_len(game->map[j]) > 0 && game->map[j][i] != '\0')
	{
		free(sub);
		free_data_texture(game->colors, game->textures);
		error(MAP, NULL); //need to do an error function
		return (1);
	}
	free(sub);
	return (0);
}

int				get_data_map(t_game game)
{
	int		i;
	int		j;

	j = 0;
	while (game->map[j] && check_textures(&game->textures) == 0 \
		|| check_colors(&game->colors) == 0)
	{
		i = 0;
		while (ctn_iswhitespace(game->map[j][i]))
			i++;
		if (set_data_map(game, i, j) == 1)
			return (1);
		j++;
	}
}
