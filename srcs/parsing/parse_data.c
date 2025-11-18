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
