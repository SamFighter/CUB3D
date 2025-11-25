#include "cub3d.h"

int		check_textures(t_textures textures)
{
	if (textures->north)
		return (0);
	if (textures->south)
		return (0);
	if (textures->west)
		return (0);
	if (textures->east)
		return (0);
	return (1);
}

int		check_colors(t_colors colors)
{
	if (colors->c_floors)
		return (0);
	if (colors->c_ceilling)
		return (0);
	return (1);
}

int		ischarset(char *set, char c)
{
    int i;

	i = 0;
    while (set[i])
    {
        if (set[i] == c)
            return (1);
        i++;
    }
    return (0);
}

void	skip_blank(char **map, int *start)
{
	int	i;

	i = 0;
	while (map[*start])
	{
		i = 0;
		while (map[*start][i] == ' ' || map[*start][i] == '\t')
			i++;
		if (str_len(map[*start]) > 0 && map[*start][i] != '\0')
			break ;
		*start += 1;
	}
}

int		count_lines(char **tab)
{
	int j;

	j = 0;
	while (tab[j])
		j++;
	return (j);
}
