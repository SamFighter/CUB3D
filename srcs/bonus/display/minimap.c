#include "cub3d_bonus.h"

void	init_mlx_var(t_minimap *map)
{
	map->mlx = mlx_init();
	map->info.render_target = (mlx_image){0};
	map->info.is_fullscreen = 0;
	map->info.is_resizable = 0;
	map->info.title = "MINIMAP";
	map->win = mlx_new_window(map->mlx, &map->info);
}

static void put_minimap(t_game *game, t_minimap *m_map)
{
    t_vec2i coord;

    coord.y = 0;
    while (coord.y < m_map->height)
    {
        coord.x = 0;
        while (coord.x < m_map->width)
        {
            char tile = m_map->map[coord.y][coord.x];

            if (tile == '1')
                mlx_put_image_to_window(m_map->mlx, m_map->win, m_map->wall,
                                        coord.x * TILE_SIZE, coord.y * TILE_SIZE);
            else if (m_map->grid[coord.y][coord.x] == 'D')
                mlx_put_image_to_window(m_map->mlx, m_map->win, m_map->door,
                                        coord.x * TILE_SIZE, coord.y * TILE_SIZE);
            else
                mlx_put_image_to_window(m_map->mlx, m_map->win, m_map->floor,
                                        coord.x * TILE_SIZE, coord.y * TILE_SIZE);
            coord.x++;
        }
        coord.y++;
    }
}

static void	put_player(t_minimap *m_map, int x, int y)
{
	mlx_put_image_to_window(m_map->mlx, m_map->win, m_map->player.player, \
												x << 5, y << 5);
}

void	render_loop(void *param)
{
	t_map	*map;

	map = (t_map *)param;
	mlx_clear_window(map->mlx, map->win, (mlx_color){.rgba = 0x00000000});
	put_grid(map);
	put_player(map, map->player.coords.x, map->player.coords.y);
}
