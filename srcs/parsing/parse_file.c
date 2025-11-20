#include "cub3d.h"

int		check_name_file(char *filename)
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

int		check_perm_file(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		error(BAD_FILE, filename);
		exit (1);
	}
	close (fd);
	return (0);
}

int		get_fd(char *filename)
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
