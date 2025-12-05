#ifndef CUB3D_H
#define CUB3D_H

#include "libft.h"
#include <stdio.h>
#include <math.h>
#include <fcntl.h>

#define EXTENSION "Error : INVALID FILE EXTENSION\nUSAGE : exemple_map[.cub]"
#define BAD_FILE "Error : ISSUE REGARDING FILE :"
#define DIRECTORY "Error : FORMAT IS A DIRECTORY :"
#define MAP "Error : INVALID DATA MAP"
#define ARGS "Error : INVALID ARGUMENT\nUSAGE : ./cub3d [map.cub]"
#define MLX "Error : ISSUE REGARDING MLX"
#define COLORS "ERROR : INVALID COLOR(S)"

typedef struct	s_images
{
	//jsp
}				t_images;

typedef struct	s_screen
{
	float		width;
}				t_screen;

typedef struct	s_colors
{
	int			i_floor[3];
	int			i_ceiling[3];
	char		*c_floor;
	char		*c_ceiling;
}				t_colors;

typedef struct	s_texture
{
	char		*north;
	char		*west;
	char		*east;
	char		*south;
//	mlx			*north_t;
//	mlx			*west_t;
//	mlx			*east_t;
//	mlx			*south_t;
}				t_texture;

typedef struct	s_player
{
	float		px;
	float		py;
	float		dir_x;
	float		dir_y;
}				t_player;

typedef struct	s_game
{
	char		**map;
	char		**data_map;
	char		*filename;
	int			fd;
	t_player	player;
	t_colors	colors;
	t_images	images;
	t_screen	screen;
	t_texture	textures;
	void		*mlx;
}				t_game;

/************************************************************/
/*                         Functions                        */
/************************************************************/

void			init_colors(t_game *game);
int				init_data(t_game *game);
void			init_textures(t_game *game);
int				parse_colors(t_colors *colors);
void			error(char *type, char *arg);
int				check_name_file(char *filename);
int				get_fd(char *filename);
char			**get_map(int fd);
char			**get_data_map(char**map, int start);
void			free_data_texture(t_colors *colors, t_texture *textures);
int				define_data_map(t_game *game);
int				check_textures(t_texture *textures);
int				check_colors(t_colors *colors);
int				ischarset(char *set, char c);
void			skip_blank(char **map, int *start);
int				count_lines(char **tab);

#endif
