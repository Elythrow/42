/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:51:33 by linux             #+#    #+#             */
/*   Updated: 2025/12/05 19:00:07 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d.h"

# define EXIT_FAILURE 1
# define BUFFER_SIZE_PARSING_CUBE 1024

typedef struct s_parsing
{
	t_config	*cfg;
	char		**lines;
}	t_parsing;

/* Main parsing */
void	parse_file(const char *file, t_config *config);
char	*file_to_string(const char *path);

/* Parsing components */
int		parse_color(char *line, t_config *cfg, int is_floor,
			t_parsing *ctx);
int		parse_texture(char *line, char **store, t_parsing *ctx,
			char *label);
int		parse_map(char **lines, int start, t_config *cfg,
			t_parsing *ctx);

/* Validation */
void	validate_map(t_config *cfg, t_parsing *ctx);
void	check_walls(t_config *cfg, t_parsing *ctx);
void	check_textures(t_config *cfg, t_parsing *ctx);
void	check_player(t_config *cfg, t_parsing *ctx);
void	check_characters(t_config *cfg, t_parsing *ctx);
int		check_surrounded(t_config *cfg, int x, int y);

/* Utils */
int		is_empty_line(char *line);
int		is_map_line(char *line);
int		is_valid_char(char c);
int		is_player_char(char c);
int		has_cub_extension(const char *path);
void	free_split(char **tab);
void	init_config(t_config *cfg);

/* Error handling */
void	parse_error(const char *msg, t_parsing *ctx);
void	parse_error_detail(const char *msg, const char *detail,
			t_parsing *ctx);

/* Memory management */
void	free_config(t_config *cfg);

#endif