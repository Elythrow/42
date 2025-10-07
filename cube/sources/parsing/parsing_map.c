/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:53:54 by gbazin            #+#    #+#             */
/*   Updated: 2025/10/07 17:55:47 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_map_dimensions(char **lines, int *width, int *height)
{
	int	i;
	int	len;

	*width = 0;
	*height = 0;
	i = 0;
	while (lines[i])
	{
		len = ft_strlen(lines[i]);
		if (lines[i][len - 1] == '\n')
			len--;
		if (len > *width)
			*width = len;
		(*height) ++;
		i ++;
	}
	return (*height > 0 && *width > 0);
}

static void	normalize_map_line(char *dest, char *src, int width)
{
	int	i;
	int	len;

	len = ft_strlen(src);
	if (src[len - 1] == '\n')
		len --;
	i = 0;
	while (i < len && i < width)
	{
		dest[i] = src[i];
		i ++;
	}
	while (i < width)
	{
		dest[i] = ' ';
		i ++;
	}
	dest[width] = '\0';
}

int	parse_map_grid(t_game *game, char **lines, int start_index)
{
	int	i;

	if (!get_map_dimensions(lines, &game->map.width, &game->map.height))
		return (print_error("Invalid map dimensions"));
	game->map.grid = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.grid)
		return (0);
	i = 0;
	while (i < game->map.height)
	{
		game->map.grid[i] = malloc(sizeof(char) * (game->map.width + 1));
		if (!game->map.grid[i])
		{
			while (--i >= 0)
				free(game->map.grid[i]);
			free(game->map.grid);
			return (0);
		}
		normalize_map_line(game->map.grid[i], lines[i], game->map.width);
		i ++;
	}
	game->map.grid[i] = NULL;
	return (1);
}

int	find_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == NORTH || 
				game->map.grid[y][x] == SOUTH ||
				game->map.grid[y][x] == EAST || 
				game->map.grid[y][x] == WEST)
			{
				if (game->map.player_found)
					return (print_error("Multiple player positions found"));
				game->player.pos_x = x + 0.5;
				game->player.pos_y = y + 0.5;
				game->player.spawn_orientation = game->map.grid[y][x];
				game->map.grid[y][x] = EMPTY_SPACE;
				game->map.player_found = true;
				set_player_direction(&game->player);
			}
			x ++;
		}
		y ++;
	}
	if (!game->map.player_found)
		return (print_error("No player position found"));
	return (1);
}

void	set_player_direction(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	
	if (player->spawn_orientation == NORTH)
	{
		player->dir_y = -1;
		player->plane_x = 0.66;
	}
	else if (player->spawn_orientation == SOUTH)
	{
		player->dir_y = 1;
		player->plane_x = -0.66;
	}
	else if (player->spawn_orientation == EAST)
	{
		player->dir_x = 1;
		player->plane_y = 0.66;
	}
	else if (player->spawn_orientation == WEST)
	{
		player->dir_x = -1;
		player->plane_y = -0.66;
	}
}

static int	is_valid_cell(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height)
		return (0);
	if (game->map.grid[y][x] == SPACE)
		return (0);
	return (1);
}

int	check_map_walls(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == EMPTY_SPACE)
			{
				if (!is_valid_cell(game, x - 1, y) ||
					!is_valid_cell(game, x + 1, y) ||
					!is_valid_cell(game, x, y - 1) ||
					!is_valid_cell(game, x, y + 1))
				{
					return (print_error("Map is not closed by walls"));
				}
			}
			x ++;
		}
		y ++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (!is_valid_map_char(game->map.grid[y][x]))
				return (print_error("Invalid character in map"));
			x ++;
		}
		y ++;
	}
	if (!find_player_position(game))
		return (0);
	if (!check_map_walls(game))
		return (0);
	return (1);
}
