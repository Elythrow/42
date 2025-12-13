/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:16:20 by gbazin            #+#    #+#             */
/*   Updated: 2025/11/23 17:29:14 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == ' '
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	check_surrounded(t_config *cfg, int x, int y)
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

void	validate_map(t_config *cfg, t_parsing *ctx)
{
	check_textures(cfg, ctx);
	if (!cfg->map.grid)
		parse_error("No map found", ctx);
	check_characters(cfg, ctx);
	check_player(cfg, ctx);
	check_walls(cfg, ctx);
}
