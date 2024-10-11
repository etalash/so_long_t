
#include "so_long.h"

void	ft_win(t_map *map)
{
	int	center_x;
	int	center_y;

	map->out = 1;
	map->moves++;
	center_x = (map->x / 2) * IMG_PXL;
	center_y = (map->y / 2) * IMG_PXL;
	write(1, "\n", 1);
	write(1, "\x1b[32;01m", 9);
	write(1, "🏆🏆YOU WON!!🏆🏆\n", 27);
	write(1, "\x1b[0m", 5);
}

static void	map_type(t_map *map, int x, int y)
{
	int	type;

	type = map->string[y / IMG_PXL][x / IMG_PXL];
	if (type == 'C' || type == 'P' || type == 'E' || type == '0')
		mlx_image_to_window(map->mlx, map->image.empty, x, y);
	if (type == 'C')
		mlx_image_to_window(map->mlx, map->image.collectible, x, y);
	else if (type == 'P')
		mlx_image_to_window(map->mlx, map->image.player, x + 8, y);
	else if (type == 'E')
		mlx_image_to_window(map->mlx, map->image.exit, x, y);
	else if (type == '1')
		mlx_image_to_window(map->mlx, map->image.wall, x, y);
}

void	build_window(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			map_type(map, x * IMG_PXL, y * IMG_PXL);
			x++;
		}
		y++;
	}
}
