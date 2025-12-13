/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:36:32 by gbazin            #+#    #+#             */
/*   Updated: 2025/12/05 15:40:01 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Calcule la direction de déplacement et la distance initiale
 * jusqu'aux bords de la grille
 * 
 * Cette fonction initialise les valeurs nécessaires pour l'algorithme
 * DDA (Digital Differential Analyzer). Elle détermine dans quelle
 * direction le rayon se déplace (step_x, step_y) et calcule la distance
 * initiale que le rayon doit parcourir pour atteindre le premier bord
 * de la grille dans chaque direction.
 * 
 * @param ray Pointeur vers la structure t_ray contenant les infos
 * @param player Pointeur vers la structure t_player contenant la pos
 * 
 * @details
 * - step_x/step_y : direction (-1 gauche/bas, +1 droite/haut)
 * - side_dist : distance jusqu'au prochain bord de la grille
 * - delta_dist : distance pour passer d'un bord à l'autre
 */
void	calc_step_and_side_dist(t_ray *ray, t_player *player)
{
	if (ray->dir_ray.x < 0)
	{
		ray->step_x = -1;
		ray->side_dist.x = (player->pos.x - ray->map_x) * ray->delta_dist.x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist.x = (ray->map_x + 1.0 - player->pos.x)
			* ray->delta_dist.x;
	}
	if (ray->dir_ray.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist.y = (player->pos.y - ray->map_y) * ray->delta_dist.y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist.y = (ray->map_y + 1.0 - player->pos.y)
			* ray->delta_dist.y;
	}
}
