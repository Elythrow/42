/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:16:10 by gbazin            #+#    #+#             */
/*   Updated: 2025/10/27 17:32:07 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	count_map_lines(char **lines, int start)
{
	int	count;

	count = 0;
	while (lines[start + count])
	{
		if (is_empty_line(lines[start + count]))
			break ;
		count ++;
	}
	return (count);
}

static int	get_max_width(char **lines, int start, int height)
{
	int	i;
	int	len;
	int	max_width;

	max_width = 0;
	i = 0;
	while (i < height)
	{
		len = ft_strlen(lines[start + i]);
		if (len > max_width)
			max_width = len;
		i ++;
	}
	return (max_width);
}

static void	fill_map_line(char *dst, char *src, int width)
{
	int	i;

	i = 0;
	while (src[i] && i < width)
	{
		dst[i] = src[i];
		i ++;
	}
	while (i < width)
	{
		dst[i] = ' ';
		i ++;
	}
	dst[i] = '\0';
}

static void	copy_map(t_config *cfg, char **lines, int start, t_parsing *ctx)
{
	int	i;

	i = 0;
	while (i < cfg->map.height)
	{
		cfg->map.grid[i] = malloc(sizeof(char) * (cfg->map.width + 1));
		if (!cfg->map.grid[i])
			parse_error("Memory allocation failed", ctx);
		fill_map_line(cfg->map.grid[i], lines[start + i], cfg->map.width);
		i  ++;
	}
	cfg->map.grid[i] = NULL;
}

int	parse_map(char **lines, int start, t_config *cfg, t_parsing *ctx)
{
	cfg->map.height = count_map_lines(lines, start);
	if (cfg->map.height == 0)
		parse_error("Empty map", ctx);
	cfg->map.width = get_max_width(lines, start, cfg->map.height);
	cfg->map.grid = malloc(sizeof(char *) * (cfg->map.height + 1));
	if (!cfg->map.grid)
		parse_error("Memory allocation failed", ctx);
	copy_map(cfg, lines, start, ctx);
	return (1);
}
