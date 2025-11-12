#include "cub3d.h"

void	get_data_map(t_game game)
{
	int		y;
	char	*line;

	y = 0;
	game->fd = open(game->filename, O_RDONLY);
	while (y != 7)
	{
		line = get_next_line(game->fd);
		if (line[0] != '\n' || line != NULL)
			game->data_map[y] = line;
		y++;
	}
}

int		check_cardinal_data(char **data)
{
	int				y;
	char			*path;
	const char		*sub_d[] = {"NO ", "SO ", "WE ", "EA ", NULL};

	y = 0;
	while (str_ncmp(data[y], sub_d[y], 3))
	{
		path = sub_str(data[y], 4, (str_len(data[y]) - 3));
		if (check_perm_file(path) == 1)
			return (1);
		y++;
	}
	return (0);
}

int		check_f_c_data(char **data)
{
	int			y;
	int			i_color[3];
}
