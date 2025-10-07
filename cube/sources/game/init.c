/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:58:05 by gbazin            #+#    #+#             */
/*   Updated: 2025/10/07 18:01:19 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_map *map)
{
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->east_texture = NULL;
	map->west_texture = NULL;
	map->floor_color.r = 0;
	map->floor_color.g = 0;
	map->floor_color.b = 0;
	map->floor_color.is_set = false;
	map->ceiling_color.r = 0;
	map->ceiling_color.g = 0;
	map->ceiling_color.b = 0;
	map->ceiling_color.is_set = false;
	map->player_found = false;
}

void	init_player(t_player *player)
{
	player->pos_x = 0;
	player->pos_y = 0;
	player->dir_x = 0;
	player->dir_y = -1;
	player->plane_x = 0.66;
	player->plane_y = 0;
	player->spawn_orientation = 0;
}

int	init_mlx(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if (!game->mlx.mlx_ptr)
		return (print_error("Failed to initialize MLX"));
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr, 
										WINDOW_WIDTH, WINDOW_HEIGHT, 
										WINDOW_TITLE);
	if (!game->mlx.win_ptr)
	{
		free(game->mlx.mlx_ptr);
		return (print_error("Failed to create window"));
	}
	game->mlx.img_ptr = mlx_new_image(game->mlx.mlx_ptr, 
									WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->mlx.img_ptr)
	{
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
		free(game->mlx.mlx_ptr);
		return (print_error("Failed to create image"));
	}
	game->mlx.img_addr = mlx_get_data_addr(game->mlx.img_ptr,
											&game->mlx.bits_per_pixel,
											&game->mlx.line_length,
											&game->mlx.endian);
	int i = 0;
	while (i < 256)
		game->keys[i ++] = false;
	return (1);
}

static int	load_texture(t_game *game, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx.mlx_ptr, path,
										&texture->width, &texture->height);
	if (!texture->img)
		return (0);
	texture->addr = mlx_get_data_addr(texture->img,
									&texture->bits_per_pixel,
									&texture->line_length,
									&texture->endian);
	return (1);
}

int	init_textures(t_game *game)
{
	if (!load_texture(game, &game->textures[0], game->map.north_texture))
		return (print_error("Failed to load north texture"));
	if (!load_texture(game, &game->textures[1], game->map.south_texture))
		return (print_error("Failed to load south texture"));
	if (!load_texture(game, &game->textures[2], game->map.east_texture))
		return (print_error("Failed to load east texture"));
	if (!load_texture(game, &game->textures[3], game->map.west_texture))
		return (print_error("Failed to load west texture"));
	return (1);
}

int	init_game(t_game *game)
{
	ft_bzero(game, sizeof(t_game));	
	if (!init_mlx(game))
		return (0);
	if (!init_textures(game))
	{
		destroy_mlx(game);
		return (0);
	}
	return (1);
}
