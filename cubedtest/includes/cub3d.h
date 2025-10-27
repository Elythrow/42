/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:51:14 by linux             #+#    #+#             */
/*   Updated: 2025/10/27 13:21:21 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
}	t_texture;

typedef struct s_player
{
	t_coord		pos;
	char		dir;
}	t_player;

typedef struct s_config
{
	t_texture	textures;
	int			floor_color;
	int			ceiling_color;
	int			floor_set;
	int			ceiling_set;
	t_map		map;
	t_player	player;
}	t_config;

#endif
