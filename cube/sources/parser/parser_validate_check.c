/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validate_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:48:13 by gbazin            #+#    #+#             */
/*   Updated: 2025/11/27 11:45:00 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	init_player(t_config *cfg, int x, int y)
{
	cfg->player.pos.x = x + 0.5;
	cfg->player.pos.y = y + 0.5;
	cfg->player.start_dir = cfg->map.grid[y][x];
}

void	check_walls(t_config *cfg, t_parsing *ctx)
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

void	check_textures(t_config *cfg, t_parsing *ctx)
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

void	check_characters(t_config *cfg, t_parsing *ctx)
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

void	check_player(t_config *cfg, t_parsing *ctx)
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
				init_player(cfg, x, y);
				found = 1;
			}
			x ++;
		}
		y ++;
	}
	if (!found)
		parse_error("No player found", ctx);
}
