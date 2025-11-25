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
