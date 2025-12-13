/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zomar <zomar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 02:06:52 by zomar             #+#    #+#             */
/*   Updated: 2025/12/04 02:06:54 by zomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_position(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_y < 0 || map_y >= game->param.map.height)
		return (0);
	if (map_x < 0 || map_x >= game->param.map.width)
		return (0);
	if (game->param.map.grid[map_y][map_x] == '1')
		return (0);
	return (1);
}

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->param.player.pos.x
		+ game->param.player.dir.x * MOVE_SPEED;
	new_y = game->param.player.pos.y
		+ game->param.player.dir.y * MOVE_SPEED;
	if (is_valid_position(game, new_x, game->param.player.pos.y))
		game->param.player.pos.x = new_x;
	if (is_valid_position(game, game->param.player.pos.x, new_y))
		game->param.player.pos.y = new_y;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->param.player.pos.x
		- game->param.player.dir.x * MOVE_SPEED;
	new_y = game->param.player.pos.y
		- game->param.player.dir.y * MOVE_SPEED;
	if (is_valid_position(game, new_x, game->param.player.pos.y))
		game->param.player.pos.x = new_x;
	if (is_valid_position(game, game->param.player.pos.x, new_y))
		game->param.player.pos.y = new_y;
}

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->param.player.pos.x
		- game->param.player.plane.x * MOVE_SPEED;
	new_y = game->param.player.pos.y
		- game->param.player.plane.y * MOVE_SPEED;
	if (is_valid_position(game, new_x, game->param.player.pos.y))
		game->param.player.pos.x = new_x;
	if (is_valid_position(game, game->param.player.pos.x, new_y))
		game->param.player.pos.y = new_y;
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->param.player.pos.x
		+ game->param.player.plane.x * MOVE_SPEED;
	new_y = game->param.player.pos.y
		+ game->param.player.plane.y * MOVE_SPEED;
	if (is_valid_position(game, new_x, game->param.player.pos.y))
		game->param.player.pos.x = new_x;
	if (is_valid_position(game, game->param.player.pos.x, new_y))
		game->param.player.pos.y = new_y;
}
