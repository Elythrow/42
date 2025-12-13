/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:32:00 by gbazin            #+#    #+#             */
/*   Updated: 2025/12/05 15:35:27 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player_direction(t_player *player)
{
	player->dir.x = 0;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = 0;
	if (player->start_dir == 'N')
	{
		player->dir.y = -1;
		player->plane.x = 0.66;
	}
	else if (player->start_dir == 'S')
	{
		player->dir.y = 1;
		player->plane.x = -0.66;
	}
	else if (player->start_dir == 'E')
	{
		player->dir.x = 1;
		player->plane.y = 0.66;
	}
	else if (player->start_dir == 'W')
	{
		player->dir.x = -1;
		player->plane.y = -0.66;
	}
}

void	init_ray(t_ray *ray, t_player *player, int x)
{
	ray->camera_x = 2.0 * x / (double)WIDTH - 1.0;
	ray->dir_ray.x = player->dir.x + player->plane.x * ray->camera_x;
	ray->dir_ray.y = player->dir.y + player->plane.y * ray->camera_x;
	ray->map_x = (int)player->pos.x;
	ray->map_y = (int)player->pos.y;
	ray->wall = 0;
	ray->side = 0;
	if (ray->dir_ray.x == 0)
		ray->delta_dist.x = 1e30;
	else
		ray->delta_dist.x = fabs(1.0 / ray->dir_ray.x);
	if (ray->dir_ray.y == 0)
		ray->delta_dist.y = 1e30;
	else
		ray->delta_dist.y = fabs(1.0 / ray->dir_ray.y);
}
