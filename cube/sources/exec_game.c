/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:02:03 by gbazin            #+#    #+#             */
/*   Updated: 2025/12/05 16:51:56 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_image(t_game *game)
{
	game->img.img_ptr = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img.img_ptr)
		close_game(game);
	game->img.addr = mlx_get_data_addr(game->img.img_ptr,
			&game->img.bits_per_pixel,
			&game->img.line_length,
			&game->img.endian);
}

void	render_frame(t_game *game)
{
	draw_floor_ceiling(game);
	perform_raycasting(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
}

int	exec_game(t_game *game, t_config *config)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_config(config);
		exit(EXIT_FAILURE);
	}
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free_config(config);
		exit(EXIT_FAILURE);
	}
	init_player_direction(&game->param.player);
	load_textures(game);
	init_image(game);
	render_frame(game);
	setup_hooks(game);
	mlx_loop(game->mlx);
	return (0);
}
