
#include "so_long.h"


void	*create_image(t_map *data, char *str)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(str);
	image = mlx_texture_to_image(data->mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}

void	image_struct(t_map *data)
{
	data->image.wall = create_image(data, "images/w_sp.png");
	data->image.empty = create_image(data, "images/f_sp.png");
	data->image.collectible = create_image(data, "images/c_sp.png");
	data->image.player = create_image(data, "images/p_sp.png");
	data->image.exit = create_image(data, "images/e_sp.png");
}
