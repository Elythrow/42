/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zomar <zomar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 01:19:26 by zomar             #+#    #+#             */
/*   Updated: 2025/12/04 01:19:30 by zomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->param.player.dir.x;
	game->param.player.dir.x = game->param.player.dir.x
		* cos(-ROT_SPEED) - game->param.player.dir.y * sin(-ROT_SPEED);
	game->param.player.dir.y = old_dir_x
		* sin(-ROT_SPEED) + game->param.player.dir.y * cos(-ROT_SPEED);
	old_plane_x = game->param.player.plane.x;
	game->param.player.plane.x = game->param.player.plane.x
		* cos(-ROT_SPEED) - game->param.player.plane.y * sin(-ROT_SPEED);
	game->param.player.plane.y = old_plane_x
		* sin(-ROT_SPEED) + game->param.player.plane.y * cos(-ROT_SPEED);
}

void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->param.player.dir.x;
	game->param.player.dir.x = game->param.player.dir.x
		* cos(ROT_SPEED) - game->param.player.dir.y * sin(ROT_SPEED);
	game->param.player.dir.y = old_dir_x
		* sin(ROT_SPEED) + game->param.player.dir.y * cos(ROT_SPEED);
	old_plane_x = game->param.player.plane.x;
	game->param.player.plane.x = game->param.player.plane.x
		* cos(ROT_SPEED) - game->param.player.plane.y * sin(ROT_SPEED);
	game->param.player.plane.y = old_plane_x
		* sin(ROT_SPEED) + game->param.player.plane.y * cos(ROT_SPEED);
}
