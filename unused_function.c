#include "cub3d.h"

/* Doing a restricted data parser who's taking only the 7 first line of .cub file 
 * Info taken in data_map : "NO, SO, EA, WE, F, C"
 */
void	get_data_map(t_game game)
{
	int		y;
	char	*line;

	y = 0;
	game->fd = open(game->filename, O_RDONLY);
	if (game->fd <= 0)
		return ;
	while (y != 7)
	{
		line = get_next_line(game->fd);
		if (line[0] != '\n' || line != NULL)
			game->data_map[y] = line;
		y++;
	}
	check_data_map(game, game->data_map);
}

/* Verify strictly the 4 first cardinal data AND the floor and ceiling color */
int		check_data_map(t_game game, char **data)
{
	int				y;
	char			*path;
	const char		*sub_d[] = {"NO ", "SO ", "WE ", "EA ", NULL};

	y = 0;
	while (y != 4)
	{
		if (str_ncmp(data[y], sub_d[y], 3))
		{
			path = sub_str(data[y], 4, (str_len(data[y]) - 3));
			if (check_perm_file(path) == 1)
				return (1);
			y++;
		}
		else
		{
			ft_printf("Cardinal axis in *.cub file wrong");
			return (1);
		}
	}
	if (check_data_color(game, data) == 1)
		return (1);
	return (0);
}

void		check_data_color(t_game game, char **data_map)
{
	int		y;
	const char		*sub_d[] = {"F ", "C ", NULL};
	char			**c_colors;

	y = 5;
	if (str_ncmp(data_map[5], sub_d[0], 2))
	{
		game.colors->c_floor = str_substr(data_map[5], 3, str_len(data_map[5]));
		c_colors = str_split(game.colors->c_floor, ',');
		add_data_color(game.colors->i_floor, c_colors);
		free(c_colors);
	}
	else
		ft_error(FLOOR, 1);
	if (str_ncmp(data_map[6], sub_d[1], 2))
	{
		game.colors->c_ceilling = str_substr(data_map[6], 3, str_len(data_map[6]))
		c_colors = str_split(game.colors->c_ceilling, ',');
		add_data_color(game.colors->i_ceilling, c_colors);
		free(c_colors);
	}
	else
		ft_error(CEILLING, 1);
}

void	add_data_color(int i_data[3], char **colors)
{
	int j;

	j = 0;
	while (j != 3)
	{
		if (ctn_aredigit(colors[j])
			  i_data[j] = colors[j];
		else
			ft_error(DATA_COLOR, 1);
		j++;
	}
}
