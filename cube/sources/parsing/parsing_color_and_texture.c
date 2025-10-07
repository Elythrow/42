/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:51:55 by gbazin            #+#    #+#             */
/*   Updated: 2025/10/07 17:53:18 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*extract_texture_path(char *line)
{
	char	*path;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != ' ')
		i ++;
	while (line[i] && line[i] == ' ')
		i ++;
	if (!line[i])
		return (NULL);
	j = i;
	while (line[j] && line[j] != ' ' && line[j] != '\n')
		j ++;
	path = ft_substr(line, i, j - i);
	return (path);
}

int	parse_texture_line(t_game *game, char *line)
{
	char	*path;
	char	**target;

	if (ft_strncmp(line, "NO ", 3) == 0)
		target = &game->map.north_texture;
	else if (ft_strncmp(line, "SO ", 3) == 0)
		target = &game->map.south_texture;
	else if (ft_strncmp(line, "WE ", 3) == 0)
		target = &game->map.west_texture;
	else if (ft_strncmp(line, "EA ", 3) == 0)
		target = &game->map.east_texture;
	else
		return (0);
	if (*target != NULL)
		return (print_error("Duplicate texture definition"));
	
	path = extract_texture_path(line);
	if (!path)
		return (print_error("Invalid texture path"));
	int fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(path);
		return (print_error("Cannot open texture file"));
	}
	close(fd);
	*target = path;
	return (1);
}

int	validate_rgb_value(int value)
{
	return (value >= 0 && value <= 255);
}

int	parse_rgb_values(char *str, t_color *color)
{
	char	**values;
	int		r, g, b;
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i ++;
	while (str[i] && str[i] == ' ')
		i ++;
	if (!str[i])
		return (0);
	
	values = ft_split(str + i, ',');
	if (!values)
		return (0);
	i = 0;
	while (values[i])
		i ++;
	if (i != 3)
	{
		free_array(values);
		return (0);
	}
	r = ft_atoi(values[0]);
	g = ft_atoi(values[1]);
	b = ft_atoi(values[2]);
	free_array(values);
	if (!validate_rgb_value(r) || !validate_rgb_value(g) || !validate_rgb_value(b))
		return (print_error("RGB values must be between 0 and 255"));
	color->r = r;
	color->g = g;
	color->b = b;
	color->is_set = true;
	return (1);
}

int	parse_color_line(t_game *game, char *line)
{
	t_color	*target;

	if (ft_strncmp(line, "F ", 2) == 0)
		target = &game->map.floor_color;
	else if (ft_strncmp(line, "C ", 2) == 0)
		target = &game->map.ceiling_color;
	else
		return (0);
	if (target->is_set)
		return (print_error("Duplicate color definition"));
	if (!parse_rgb_values(line, target))
		return (0);
	return (1);
}

int	create_rgb_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}
