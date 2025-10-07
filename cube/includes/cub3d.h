/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:15:42 by gbazin            #+#    #+#             */
/*   Updated: 2025/10/04 20:59:23 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define WINDOW_TITLE "cub3D"

# define EMPTY_SPACE '0'
# define WALL '1'
# define NORTH 'N'
# define SOUTH 'S'
# define EAST 'E'
# define WEST 'W'
# define SPACE ' '

/* Texture structure */
typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_texture;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}	t_color;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	char	spawn_orientation;
}	t_player;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	t_color	floor_color;
	t_color	ceiling_color;
	bool	player_found;
}	t_map;

/* MLX structure */
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_game
{
	t_mlx		mlx;
	t_map		map;
	t_player	player;
	t_texture	textures[4];
	bool		keys[256];
}	t_game;

// Parsing

int		parse_file(t_game *game, char *filename);
int		validate_file_extension(char *filename);
int		parse_map_file(t_game *game, int fd);
int		parse_texture_line(t_game *game, char *line);
int		parse_color_line(t_game *game, char *line);
int		parse_map_grid(t_game *game, char **lines, int start_index);
int		validate_map(t_game *game);
int		check_map_walls(t_game *game);
int		find_player_position(t_game *game);
void	set_player_direction(t_player *player);
int		parse_rgb_values(char *str, t_color *color);
int		create_rgb_int(int r, int g, int b);
int		validate_rgb_value(int value);

//Divers
int		is_empty_line(char *line);
int		is_map_line(char *line);
int		is_valid_map_char(char c);
void	free_array(char **array);
int		array_len(char **array);
char	*trim_newline(char *line);
int		count_file_lines(char *filename);
char	**read_file_lines(char *filename);

/* Initialization functions */
int		init_game(t_game *game);
int		init_mlx(t_game *game);
int		init_textures(t_game *game);
void	init_player(t_player *player);
void	init_map(t_map *map);

/* Cleanup functions */
void	cleanup_game(t_game *game);
void	free_map(t_map *map);
void	free_textures(t_game *game);
void	destroy_mlx(t_game *game);

/* Error handling */
void	error_exit(char *message);
void	perror_exit(char *message);
int		print_error(char *message);

#endif