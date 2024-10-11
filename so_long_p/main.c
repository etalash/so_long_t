/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:00:55 by stalash           #+#    #+#             */
/*   Updated: 2024/10/04 19:22:06 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_len(char *map)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd <= 0 || read(fd, 0, 0) < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close (fd);
	return (i);
}

void	store_map(t_map *data, char *map)
{
	char	*line;
	int		i;
	int		len;
	int		fd;

	i = 0;
	len = map_len(map);
	if (!len)
		return ;
	data->string = malloc(sizeof(char *) * (len + 1));
	if (!data->string)
		return ;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		data->string[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	data->string[i] = NULL;
	close (fd);
}

void	map_initialization(t_map *map, char **argv)
{
	map->file_name = argv[1];
	map->a = 0;
	map->b = 0;
	map->y = 0;
	map->p = 0;
	map->moves = 0;
	map->player.x = 0;
	map->player.y = 0;
	map->out = 0;
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		write(2, "\033[1;31m❌ERROR:", 16);
		write(2, " Please provide a valid map file!\n\033[0m", 53);
		return (EXIT_FAILURE);
	}
	map_initialization(&map, argv);
	store_map(&map, argv[1]);
	map.mlx = mlx_init(500, 500, "so_long 42", 1);
	image_struct(&map);
	build_window(&map);
	// mlx_key_hook(map.mlx, key_hook, &map);
	mlx_loop(map.mlx);
	return (0);
}
