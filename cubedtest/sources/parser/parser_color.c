/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:15:46 by gbazin            #+#    #+#             */
/*   Updated: 2025/10/27 17:33:08 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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

static void	parse_rgb_values(char **parts, int *rgb, t_parsing *ctx)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!parts[i])
			parse_error("Invalid color format", ctx);
		rgb[i] = ft_atoi(parts[i]);
		i ++;
	}
	if (parts[3] != NULL)
		parse_error("Too many color values", ctx);
}

int	parse_color(char *line, t_config *cfg, int is_floor, t_parsing *ctx)
{
	char	**parts;
	char	*color_str;
	int		rgb[3];
	int		color;

	color_str = ft_strtrim(line + 2, " \t\n\r");
	if (!color_str)
		parse_error("Memory allocation failed", ctx);
	parts = ft_split(color_str, ',');
	free(color_str);
	if (!parts)
		parse_error("Memory allocation failed", ctx);
	parse_rgb_values(parts, rgb, ctx);
	if (!validate_rgb(rgb[0], rgb[1], rgb[2]))
	{
		free_split(parts);
		parse_error("RGB values must be between 0 and 255", ctx);
	}
	color = rgb_to_int(rgb[0], rgb[1], rgb[2]);
	free_split(parts);
	if (is_floor && !cfg->floor_set)
		return (cfg->floor_color = color, cfg->floor_set = 1, 0);
	if (!is_floor && !cfg->ceiling_set)
		return (cfg->ceiling_color = color, cfg->ceiling_set = 1, 0);
	parse_error("Duplicate color definition", ctx);
	return (0);
}
