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

void			free_data_texture(t_colors *colors, t_texture *textures)
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
		if (colors->c_ceiling)
			free(colors->c_ceiling);
	}
}

static int		set_data_map(t_game *game, int i, int j)
{
	char	*sub;

	sub = str_substr(game->map[j], i, ctn_strlchr(&game->map[j][i], ' '));
	if (game->textures.north == NULL && str_ncmp(sub, "NO", 3) == 0)
		game->textures.north = set_data(&game->map[j][i + 2]);
	else if (game->textures.south == NULL && str_ncmp(sub, "SO", 3) == 0)
		game->textures.south = set_data(&game->map[j][i + 2]);
	else if (game->textures.west == NULL && str_ncmp(sub, "WE", 3) == 0)
		game->textures.west = set_data(&game->map[j][i + 2]);
	else if (game->textures.east == NULL && str_ncmp(sub, "EA", 3) == 0)
		game->textures.east = set_data(&game->map[j][i + 2]);
	else if (game->colors.c_floor == NULL && str_ncmp(sub, "F", 2) == 0)
		game->colors.c_floor = set_data(&game->map[j][i + 1]);
	else if (game->colors.c_ceiling == NULL && str_ncmp(sub, "C", 2) == 0)
		game->colors.c_ceiling = set_data(&game->map[j][i + 1]);
	else if (str_len(game->map[j]) > 0 && game->map[j][i] != '\0')
	{
		free(sub);
		free_data_texture(&game->colors, &game->textures);
		error(MAP, NULL);
		return (1);
	}
	free(sub);
	return (0);
}

static int		verify_data(t_game *game, int j)
{
	game->data_map = get_data_map(game->map, j);
	if (game->data_map == NULL)
	{
		free_data_texture(&game->colors, &game->textures);
		error(MAP, NULL);
	}
	else if (parse_colors(&game->colors) == 1)
	{
		utl_super_free((void **)game->data_map);
		free_data_texture(&game->colors, &game->textures);
		error(COLORS, NULL);
	}
	else
		return (0);
	return (1);
}

int				define_data_map(t_game *game)
{
	int		i;
	int		j;

	j = 0;
	while ((game->map[j] && check_textures(&game->textures) == 0) \
		|| check_colors(&game->colors) == 0)
	{
		i = 0;
		while (ctn_iswhitespace(game->map[j][i]))
			i++;
		if (set_data_map(game, i, j) == 1)
			return (1);
		j++;
	}
	if (verify_data(game, j) == 1)
		return (1);
	return (0);
}
