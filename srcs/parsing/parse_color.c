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
		i++;
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

int		parse_colors(t_colors *colors)
{
	char	**floor;
	char	**ceil;

	if (check_comma(colors->c_floor) == 1 || check_comma(colors->c_ceiling) == 1)
		return (1);
	floor = str_split(colors->c_floor, ',');
	if (floor == NULL || floor[0] == NULL)
		return (1);
	ceil = str_split(colors->c_ceiling, ',');
	if (ceil == NULL || ceil[0] == NULL)
		return (1);
	if (check_decimal_colors(colors->i_floor, floor) == 1 || check_decimal_colors(colors->i_ceiling, ceil) == 1)
	{
		utl_super_free((void **)floor);
		utl_super_free((void **)ceil);
		return (1);
	}
	utl_super_free((void **)floor);
	utl_super_free((void **)ceil);
	return (0);
}
