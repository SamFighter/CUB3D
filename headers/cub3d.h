#ifndef CUB3D_H
#define CUB3D_H

#include "libft.h"
#include <stdio.h>
#include <math.h>
#include <fcntl.h>

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
	int			i_celling[3];
	char		*c_floor;
	char		*c_celling;
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
//	mlx			*south+t;
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

#endif
