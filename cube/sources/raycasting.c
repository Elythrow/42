/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:32:54 by gbazin            #+#    #+#             */
/*   Updated: 2025/12/05 17:17:32 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Implémente l'algorithme DDA pour trouver l'intersection
 * avec un mur
 * 
 * L'algorithme DDA (Digital Differential Analyzer) est utilisé pour
 * déterminer rapidement quel mur est touché par le rayon. Au lieu de
 * calculer chaque point le long du rayon, on saute directement d'une
 * case de la grille à l'autre en suivant la direction du rayon.
 * 
 * @param ray Pointeur vers la structure t_ray contenant les infos
 * @param game Pointeur vers la structure t_game contenant la carte
 * 
 * @details Algorithme DDA :
 * 1. Compare les distances jusqu'aux prochains bords horizontaux
 * 2. Avance dans la direction la plus proche
 * 3. Met à jour la position sur la grille (map_x, map_y)
 * 4. Vérifie si la nouvelle case contient un mur ('1')
 * 5. Répète jusqu'à trouver un mur ou sortir de la carte
 * 
 * @note side = 0 = mur vertical, side = 1 = mur horizontal
 */
void	perform_dda(t_ray *ray, t_game *game)
{
	while (ray->wall == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y >= 0 && ray->map_y < game->param.map.height
			&& ray->map_x >= 0 && ray->map_x < game->param.map.width)
		{
			if (game->param.map.grid[ray->map_y][ray->map_x] == '1')
				ray->wall = 1;
		}
		else
			ray->wall = 1;
	}
}

/**
 * @brief Calcule la hauteur du mur à afficher et la distance
 * perpendiculaire
 * 
 * Cette fonction calcule la distance perpendiculaire du joueur au mur
 * (perp_dist), ce qui évite l'effet "fish-eye" en utilisant la distance
 * perpendiculaire plutôt que la distance euclidienne. Cette distance est
 * ensuite utilisée pour calculer la hauteur de la ligne de mur à dessiner.
 * 
 * @param ray Pointeur vers la structure t_ray contenant les infos
 * 
 * @details
 * - perp_dist : distance perpendiculaire au mur (évite le fish-eye)
 *   Calculée comme (side_dist - delta_dist) pour le côté touché
 * - line_height : hauteur de la ligne de mur en pixels
 *   Calculée comme HEIGHT / perp_dist
 * - draw_start/draw_end : positions verticales pour dessiner le mur
 *   Centrées sur l'écran avec des limites pour éviter de dépasser
 */
void	calc_wall_height(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perp_dist = ray->side_dist.y - ray->delta_dist.y;
	if (ray->perp_dist < 0.0001)
		ray->perp_dist = 0.0001;
	ray->line_height = (int)(HEIGHT / ray->perp_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}

/**
 * @brief Calcule la coordonnée X de la texture à utiliser pour le mur
 * 
 * Cette fonction détermine quelle partie de la texture doit être
 * affichée pour ce mur. Elle calcule la position exacte sur le mur où
 * le rayon l'a touché (wall_x), puis convertit cette position en
 * coordonnée de texture (tex_x).
 * 
 * @param ray Pointeur vers la structure t_ray contenant les infos
 * @param player Pointeur vers la structure t_player contenant la pos
 * @param game Pointeur vers la structure t_game contenant les textures
 * 
 * @details
 * - wall_x : position exacte sur le mur (valeur entre 0 et 1)
 *   Calculée avec pos joueur + perp_dist * direction du rayon
 * - tex_x : coordonnée X dans la texture (en pixels)
 *   Calculée comme wall_x * largeur_texture
 * - Les textures sont inversées pour les murs Est et Sud
 */
void	calc_texture_x(t_ray *ray, t_player *player, t_game *game)
{
	int		tex_index;
	int		tex_width;

	if (ray->side == 0)
		ray->wall_x = player->pos.y + ray->perp_dist * ray->dir_ray.y;
	else
		ray->wall_x = player->pos.x + ray->perp_dist * ray->dir_ray.x;
	ray->wall_x = ray->wall_x - floor(ray->wall_x);
	tex_index = select_texture_index(ray);
	tex_width = game->tex[tex_index].width;
	ray->tex_x = (int)(ray->wall_x * (double)tex_width);
	if (ray->side == 0 && ray->dir_ray.x < 0)
		ray->tex_x = tex_width - ray->tex_x - 1;
	if (ray->side == 1 && ray->dir_ray.y > 0)
		ray->tex_x = tex_width - ray->tex_x - 1;
	if (ray->tex_x < 0)
		ray->tex_x = 0;
	if (ray->tex_x >= tex_width)
		ray->tex_x = tex_width - 1;
}

/**
 * @brief Dessine une colonne verticale de mur sur l'écran
 * 
 * Cette fonction dessine une seule colonne verticale (slice) du mur
 * à la position x sur l'écran. Elle parcourt toutes les lignes
 * verticales de draw_start à draw_end et applique la couleur de
 * texture correspondante.
 * 
 * @param game Pointeur vers la structure t_game contenant l'image
 * @param ray Pointeur vers la structure t_ray contenant les infos
 * @param x Position X sur l'écran où dessiner cette colonne
 */

static void	draw_wall_slice(t_game *game, t_ray *ray, int x)
{
	int				y;
	int				tex_y;
	int				d;
	t_texture_data	*tex;
	unsigned int	color;

	tex = &game->tex[select_texture_index(ray)];
	if (!tex->addr || !tex->img)
		return ;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		d = y - HEIGHT / 2 + ray->line_height / 2;
		tex_y = d * tex->height / ray->line_height;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		color = *(unsigned int *)(tex->addr + tex_y * tex->line_len
				+ ray->tex_x * (tex->bpp / 8));
		put_pixel(&game->img, x, y, color);
		y ++;
	}
}

/**
 * @brief Fonction principale du raycasting - génère une frame complète
 * 
 * Cette fonction implémente l'algorithme de raycasting pour cub3d.
 * Pour chaque colonne de pixels de l'écran (de gauche à droite), elle :
 * 1. Initialise un rayon dans la direction correspondante
 * 2. Utilise l'algorithme DDA pour trouver l'intersection avec un mur
 * 3. Calcule la hauteur du mur à afficher
 * 4. Calcule les coordonnées de texture appropriées
 * 5. Dessine la colonne de mur sur l'écran
 * 
 * @param game Pointeur vers la structure t_game contenant les infos
 * 
 * @details Algorithme de raycasting :
 * Le raycasting est une technique de rendu 3D qui simule une vue en
 * perspective en lançant des rayons depuis la position du joueur vers
 * chaque colonne de l'écran. Chaque rayon représente une ligne de vue
 * et détermine ce qui doit être affiché à cette position sur l'écran.
 * 
 * @note Cette fonction est appelée à chaque frame pour mettre à jour
 * l'affichage
 */
void	perform_raycasting(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(&ray, &game->param.player, x);
		calc_step_and_side_dist(&ray, &game->param.player);
		perform_dda(&ray, game);
		calc_wall_height(&ray);
		calc_texture_x(&ray, &game->param.player, game);
		draw_wall_slice(game, &ray, x);
		x ++;
	}
}
