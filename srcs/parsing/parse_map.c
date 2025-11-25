#include "cub3d.h"

char	**get_map(int fd)
{
	char	**map;
	char	*line;
	char	*tmp;

	line = get_next_line(fd);
	if (line == NULL)
	{
		error(MAP, NULL);
		return (NULL);
	}
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		line = ft_strjoin(line, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	map = ft_split(line, '\n');
	free(line);
	free(tmp);
	return (map);
}

static int	compare_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != ' ' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != 'W' && str[i] != 'E')
			return (1);
		i++;
	}
	return (0);
}

static int	map_closed(char **map, char *str, int x, int y)
{
	while (str[x])
	{
		if (ischarset("0NSWE", str[x]) == 1)
		{
			if (!map[y + 1] || x > (int)str_len(map[y + 1]) \
				|| ischarset("10NSWE", map[y + 1][x]) == 0)
				return (1);
			if (!map[y - 1] || x > (int)str_len(map[y - 1]) \
				|| ischarset("10NSWE", map[y - 1][x]) == 0)
				return (1);
			if (!map[y][x + 1] || ischarset("10NSWE", map[y][x + 1]) == 0)
				return (1);
			if (!map[y][x - 1] || ischarset("10NSWE", map[y][x - 1]) == 0)
				return (1);
		}
		x++;
	}
	return (0);
}

static int	parse_map_content(char **map, int j)
{
	int		i;
	int		player;

	player = 0;
	while (map[j])
	{
		i = 0;
		if (compare_char(&map[j][i]) || map_closed(map, map[j], i, j))
			return (1);
		else if (map[j][i] != "1" && map[j][i] != ' ')
			return (1);
		while (map[j][i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'S' || map[j][i] == 'W' || map[j][i] == 'E')
				player++;
			i++;
		}
		j++;
	}
	if (player != 1)
		return (1);
	return (0);
}

char		**get_data_map(char **map, int start)
{
	char	**data;
	int		j;

	skip_blank(map, &start);
	if (parse_map_content(map, start))
		return (NULL);
	content = malloc(sizeof(char *) * (count_lines(map) + 1));
	if (content == NULL)
		return (NULL);
	j = 0;
	while (map[start])
	{
		content[j] = str_substr(map[start], 0, str_len(map[start]));
		if (content[j] == NULL)
		{
			utl_super_free(content);
			return (NULL);
		}
		j++;
		start++;
	}
	content[j] = NULL;
	return (content);
}
