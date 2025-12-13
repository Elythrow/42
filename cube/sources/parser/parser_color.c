/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:15:46 by gbazin            #+#    #+#             */
/*   Updated: 2025/12/05 17:48:13 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	validate_rgb(int r, int g, int b)
{
	if (r < 0 || r > 255)
		return (0);
	if (g < 0 || g > 255)
		return (0);
	if (b < 0 || b > 255)
		return (0);
	return (1);
}

static int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

static void	parse_rgb(char **parts, int *rgb, t_parsing *ctx, char *color_str)
{
	int		i;
	char	*trimmed;

	i = 0;
	while (i < 3)
	{
		if (!parts[i])
		{
			free_split(parts);
			free(color_str);
			parse_error("Invalid color format", ctx);
		}
		trimmed = ft_strtrim(parts[i], " \t");
		if (!trimmed)
			parse_error("Memory allocation failed", ctx);
		rgb[i] = ft_atoi(trimmed);
		free(trimmed);
		i ++;
	}
	if (parts[3] != NULL)
		parse_error("Too many color values", ctx);
}

static int	create_color(char *color_str, t_parsing *ctx)
{
	char	**parts;
	int		rgb[3];
	int		color;

	parts = ft_split(color_str, ',');
	if (!parts)
	{
		free(color_str);
		parse_error("Memory allocation failed", ctx);
	}
	parse_rgb(parts, rgb, ctx, color_str);
	if (!validate_rgb(rgb[0], rgb[1], rgb[2]))
	{
		free_split(parts);
		free(color_str);
		parse_error("RGB values must be between 0 and 255", ctx);
	}
	color = rgb_to_int(rgb[0], rgb[1], rgb[2]);
	free_split(parts);
	return (color);
}

int	parse_color(char *line, t_config *cfg, int is_floor, t_parsing *ctx)
{
	char	*color_str;
	int		color;
	int		i;

	i = 1;
	while (line[i] == ' ' || line[i] == '\t')
		i ++;
	color_str = ft_strtrim(line + i, " \t\n\r");
	if (!color_str)
		parse_error("Memory allocation failed", ctx);
	color = create_color(color_str, ctx);
	free(color_str);
	if (is_floor && !cfg->floor_set)
	{
		cfg->floor_color = color;
		cfg->floor_set = 1;
		return (0);
	}
	if (!is_floor && !cfg->ceiling_set)
	{
		cfg->ceiling_color = color;
		cfg->ceiling_set = 1;
		return (0);
	}
	return (parse_error("Duplicate color definition", ctx), 0);
}
