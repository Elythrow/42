/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:51:14 by linux             #+#    #+#             */
/*   Updated: 2025/12/05 16:42:39 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

# define WIDTH 1080
# define HEIGHT 720
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.03

/* Keycodes macOS */
# ifdef __APPLE__
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_ESC 53
# else
/* Keycodes Linux */
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_ESC 65307
# endif

typedef struct s_coord
{
	double	x;
	double	y;
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
	t_coord		dir;
	t_coord		plane;
	char		start_dir;
}	t_player;

typedef struct s_ray
{
	double		camera_x;
	t_coord		dir_ray;
	int			map_x;
	int			map_y;
	t_coord		side_dist;
	t_coord		delta_dist;
	double		perp_dist;
	int			step_x;
	int			step_y;
	int			line_height;
	int			side;
	int			wall;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	int			tex_x;
}	t_ray;

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

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_texture_data
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_texture_data;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_config		param;
	t_img			img;
	t_texture_data	tex[4];
}	t_game;

/* Init */
void	init_image(t_game *game);
void	init_player_direction(t_player *player);
void	init_ray(t_ray *ray, t_player *player, int x);

/* Rendering */
void	render_frame(t_game *game);
void	put_pixel(t_img *img, int x, int y, int color);
void	draw_floor_ceiling(t_game *game);

/* Raycasting */
void	perform_raycasting(t_game *game);
void	calc_step_and_side_dist(t_ray *ray, t_player *player);
void	perform_dda(t_ray *ray, t_game *game);
void	calc_wall_height(t_ray *ray);
int		select_texture_index(t_ray *ray);
void	calc_texture_x(t_ray *ray, t_player *player, t_game *game);

/* Textures */
void	load_textures(t_game *game);
void	free_textures(t_game *game);

/* Movement */
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

/* Rotation */
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);

/* Controls */
int		close_game(t_game *game);
void	setup_hooks(t_game *game);
int		key_press(int keycode, t_game *game);

/* Game execution */
int		exec_game(t_game *game, t_config *config);

#endif