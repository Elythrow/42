/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:16:20 by gbazin            #+#    #+#             */
/*   Updated: 2025/10/27 17:31:34 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	check_player(t_config *cfg, t_parsing *ctx)
{
	int	y;
	int	x;
	int	found;

	y = 0;
	found = 0;
	while (y < cfg->map.height)
	{
		x = 0;
		while (x < cfg->map.width)
		{
			if (is_player_char(cfg->map.grid[y][x]))
			{
				if (found)
					parse_error("Multiple players found", ctx);
				cfg->player.pos.x = x;
				cfg->player.pos.y = y;
				cfg->player.dir = cfg->map.grid[y][x];
				found = 1;
			}
			x ++;
		}
		y ++;
	}
	if (!found)
		parse_error("No player found", ctx);
}

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == ' '
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	check_characters(t_config *cfg, t_parsing *ctx)
{
	int	y;
	int	x;

	y = 0;
	while (y < cfg->map.height)
	{
		x = 0;
		while (x < cfg->map.width)
		{
			if (!is_valid_char(cfg->map.grid[y][x]))
				parse_error("Invalid character in map", ctx);
			x ++;
		}
		y ++;
	}
}

static int	check_surrounded(t_config *cfg, int x, int y)
{
	if (y == 0 || y == cfg->map.height - 1)
		return (0);
	if (x == 0 || x == cfg->map.width - 1)
		return (0);
	if (cfg->map.grid[y - 1][x] == ' ')
		return (0);
	if (cfg->map.grid[y + 1][x] == ' ')
		return (0);
	if (cfg->map.grid[y][x - 1] == ' ')
		return (0);
	if (cfg->map.grid[y][x + 1] == ' ')
		return (0);
	return (1);
}

static void	check_walls(t_config *cfg, t_parsing *ctx)
{
	int	y;
	int	x;

	y = 0;
	while (y < cfg->map.height)
	{
		x = 0;
		while (x < cfg->map.width)
		{
			if (cfg->map.grid[y][x] == '0'
				|| is_player_char(cfg->map.grid[y][x]))
			{
				if (!check_surrounded(cfg, x, y))
					parse_error("Map not closed by walls", ctx);
			}
			x ++;
		}
		y ++;
	}
}

static void	check_textures(t_config *cfg, t_parsing *ctx)
{
	if (!cfg->textures.north)
		parse_error("Missing NO texture", ctx);
	if (!cfg->textures.south)
		parse_error("Missing SO texture", ctx);
	if (!cfg->textures.east)
		parse_error("Missing EA texture", ctx);
	if (!cfg->textures.west)
		parse_error("Missing WE texture", ctx);
	if (!cfg->floor_set)
		parse_error("Missing F color", ctx);
	if (!cfg->ceiling_set)
		parse_error("Missing C color", ctx);
}

void	validate_map(t_config *cfg, t_parsing *ctx)
{
	check_textures(cfg, ctx);
	if (!cfg->map.grid)
		parse_error("No map found", ctx);
	check_characters(cfg, ctx);
	check_player(cfg, ctx);
	check_walls(cfg, ctx);
}

