/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:13:54 by gbazin            #+#    #+#             */
/*   Updated: 2025/10/27 17:32:52 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	init_config(t_config *cfg)
{
	cfg->textures.north = NULL;
	cfg->textures.south = NULL;
	cfg->textures.east = NULL;
	cfg->textures.west = NULL;
	cfg->floor_color = -1;
	cfg->ceiling_color = -1;
	cfg->floor_set = 0;
	cfg->ceiling_set = 0;
	cfg->map.grid = NULL;
	cfg->map.width = 0;
	cfg->map.height = 0;
	cfg->player.pos.x = -1;
	cfg->player.pos.y = -1;
	cfg->player.dir = 0;
}

static int	process_line(char *line, t_parsing *ctx, int *i)
{
	if (is_empty_line(line))
		return (0);
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (parse_texture(line, &ctx->cfg->textures.north, ctx, "NO"));
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (parse_texture(line, &ctx->cfg->textures.south, ctx, "SO"));
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (parse_texture(line, &ctx->cfg->textures.west, ctx, "WE"));
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (parse_texture(line, &ctx->cfg->textures.east, ctx, "EA"));
	if (ft_strncmp(line, "F ", 2) == 0)
		return (parse_color(line, ctx->cfg, 1, ctx));
	if (ft_strncmp(line, "C ", 2) == 0)
		return (parse_color(line, ctx->cfg, 0, ctx));
	if (is_map_line(line))
		return (parse_map(ctx->lines, *i, ctx->cfg, ctx));
	parse_error("Invalid line in file", ctx);
	return (0);
}

static void	parse_lines(t_parsing *ctx)
{
	int	i;

	i = 0;
	while (ctx->lines[i])
	{
		if (process_line(ctx->lines[i], ctx, &i))
			break ;
		i ++;
	}
}

void	parse_file(const char *file, t_config *config)
{
	t_parsing	ctx;
	char		*content;

	if (!has_cub_extension(file))
		parse_error("File must have .cub extension", NULL);
	init_config(config);
	ctx.cfg = config;
	content = file_to_string(file);
	if (!content)
		parse_error("Cannot read file", NULL);
	ctx.lines = ft_split(content, '\n');
	free(content);
	if (!ctx.lines)
		parse_error("Memory allocation failed", NULL);
	parse_lines(&ctx);
	validate_map(config, &ctx);
	free_split(ctx.lines);
}

char	*file_to_string(const char *path)
{
	int		fd;
	char	*line;
	char	*content;
	char	*tmp;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		tmp = content;
		content = ft_strjoin(content, line);
		free(tmp);
		free(line);
		if (!content)
			return (close(fd), NULL);
		line = get_next_line(fd);
	}
	close(fd);
	return (content);
}
