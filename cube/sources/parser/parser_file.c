/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:13:54 by gbazin            #+#    #+#             */
/*   Updated: 2025/12/05 19:00:45 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*skip_whitespace(char *line)
{
	while (*line == ' ' || *line == '\t')
		line ++;
	return (line);
}

static int	check_identifier(char *line, char *id, int id_len)
{
	if (ft_strncmp(line, id, id_len) != 0)
		return (0);
	if (line[id_len] != ' ' && line[id_len] != '\t')
		return (0);
	return (1);
}

static int	process_line(char *line, t_parsing *ctx, int *i)
{
	char	*trimmed;

	if (is_empty_line(line))
		return (0);
	trimmed = skip_whitespace(line);
	if (is_empty_line(trimmed))
		return (0);
	if (check_identifier(trimmed, "NO", 2))
		return (parse_texture(trimmed, &ctx->cfg->textures.north, ctx, "NO"));
	if (check_identifier(trimmed, "SO", 2))
		return (parse_texture(trimmed, &ctx->cfg->textures.south, ctx, "SO"));
	if (check_identifier(trimmed, "WE", 2))
		return (parse_texture(trimmed, &ctx->cfg->textures.west, ctx, "WE"));
	if (check_identifier(trimmed, "EA", 2))
		return (parse_texture(trimmed, &ctx->cfg->textures.east, ctx, "EA"));
	if (trimmed[0] == 'F' && (trimmed[1] == ' ' || trimmed[1] == '\t'))
		return (parse_color(trimmed, ctx->cfg, 1, ctx));
	if (trimmed[0] == 'C' && (trimmed[1] == ' ' || trimmed[1] == '\t'))
		return (parse_color(trimmed, ctx->cfg, 0, ctx));
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
