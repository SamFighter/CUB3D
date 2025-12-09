#include "cub3d.h"

int	check_name_file(char *filename)
{
	if (str_len(filename) == 4)
	{
		ft_printf("File need a name before extension\n");
		exit (1);
	}
	else if (!str_llstr(filename, ".cub", 4, (str_len(filename) - 4)))
	{
		ft_printf("The file doesnt have the extension .cub\n");
		exit (1);
	}
	return (0);
}

int	get_fd(char *filename)
{
	int	fd;

	fd = open(filename, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		error(DIRECTORY, filename);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		error(BAD_FILE, filename);
		return (-1);
	}
	return (fd);
}

static int	verify_paths(char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		error(DIRECTORY, path);
		return (-1);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		error(BAD_FILE, path);
		return (-1);
	}
	return (fd);
}

int	check_textures_paths(t_texture *textures)
{
	if (verify_paths(textures->north) == -1)
		return (1);
	else if (verify_paths(textures->south) == -1)
		return (1);
	else if (verify_paths(textures->west) == -1)
		return (1);
	else if (verify_paths(textures->east) == -1)
		return (1);
	else
		return (0);
}
