#include "cub3d.h"

static int		check_comma(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',' && !str[i + 1])
			return (1);
		if (str[i] == ',' && str[i + 1])
		{
			if (str[i + 1] == ',')
				return (1);
		}
		i++
	}
	return (0);
}

static int		check_decimal_colors(int *i_colors, char **color)
{
	int		i;
	int		i_stash;

	i = 0;
	while (color[i])
	{
		i_stash = cnv_atoi(color[i]);
		if (i_stash < 0 || i_stash > 255)
			return (1);
		else if (i > 3)
		  i_colors[i] = i_stash;
		i++;
	}
	if (i != 3)
		return (1);
	return (0);
}
