
#include "so_long.h"

void	up_move(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (y > 0 && map->string[y - 1][x] != '1')
	{
		resume_move(map, x, y, UP);
		if (map->string[y - 1][x] == 'E' && (map->a != 0 || map->out == 1))
			return ;
		map->moves++;
		draw_empty_tile(map, x, y);
		map->string[y][x] = '0';
		y--;
		draw_empty_tile(map, x, y);
		draw_player_tile(map, x, y, UP);
		map->string[y][x] = 'P';
		map->player.x = x;
		map->player.y = y;
	}
}

void	right_move(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x < map->x - 1 && map->string[y][x + 1] != '1')
	{
		resume_move(map, x, y, RIGHT);
		if (map->string[y][x + 1] == 'E' && (map->a != 0 || map->out == 1))
			return ;
		map->moves++;
		draw_empty_tile(map, x, y);
		map->string[y][x] = '0';
		x++;
		draw_empty_tile(map, x, y);
		draw_player_tile(map, x, y, RIGHT);
		map->string[y][x] = 'P';
		map->player.x = x;
		map->player.y = y;
	}
}

void	down_move(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (y < map->y - 1 && map->string[y + 1][x] != '1')
	{
		resume_move(map, x, y, DOWN);
		if (map->string[y + 1][x] == 'E' && (map->a != 0 || map->out == 1))
			return ;
		map->moves++;
		draw_empty_tile(map, x, y);
		map->string[y][x] = '0';
		y++;
		draw_empty_tile(map, x, y);
		draw_player_tile(map, x, y, DOWN);
		map->string[y][x] = 'P';
		map->player.x = x;
		map->player.y = y;
	}
}

void	left_move(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x > 0 && map->string[y][x - 1] != '1')
	{
		resume_move(map, x, y, LEFT);
		if (map->string[y][x - 1] == 'E' && (map->a != 0 || map->out == 1))
			return ;
		map->moves++;
		draw_empty_tile(map, x, y);
		map->string[y][x] = '0';
		x--;
		draw_empty_tile(map, x, y);
		draw_player_tile(map, x, y, LEFT);
		map->string[y][x] = 'P';
		map->player.x = x;
		map->player.y = y;
	}
}

void	key_hook(mlx_key_data_t key_data, void *pointer)
{
	t_map *map = (t_map *)pointer;

	scan_player(map);
	if (key_data.key == MLX_KEY_A)
		left_move(map);
	else if (key_data.key == MLX_KEY_S)
		down_move(map);
	else if (key_data.key == MLX_KEY_D)
		right_move(map);
	else if (key_data.key == MLX_KEY_W)
		up_move(map);
}
