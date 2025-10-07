/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:50:46 by gbazin            #+#    #+#             */
/*   Updated: 2025/10/04 20:51:01 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_file_extension(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (ft_strncmp(filename + len - 4, ".cub", 4) != 0)
		return (0);
	return (1);
}

int	parse_element(t_game *game, char *line)
{
	char	*trimmed;
	int		result;

	trimmed = trim_newline(line);
	if (!trimmed || is_empty_line(trimmed))
		return (0);
	if (ft_strncmp(trimmed, "NO ", 3) == 0 || 
		ft_strncmp(trimmed, "SO ", 3) == 0 ||
		ft_strncmp(trimmed, "WE ", 3) == 0 || 
		ft_strncmp(trimmed, "EA ", 3) == 0)
		result = parse_texture_line(game, trimmed);
	else if (ft_strncmp(trimmed, "F ", 2) == 0 || 
			ft_strncmp(trimmed, "C ", 2) == 0)
		result = parse_color_line(game, trimmed);
	else if (is_map_line(trimmed))
		result = 1;
	else
		result = -1;
	return (result);
}

int	check_elements_complete(t_game *game)
{
	if (!game->map.north_texture || !game->map.south_texture ||
		!game->map.east_texture || !game->map.west_texture)
	{
		print_error("Missing texture path");
		return (0);
	}
	if (!game->map.floor_color.is_set || !game->map.ceiling_color.is_set)
	{
		print_error("Missing floor or ceiling color");
		return (0);
	}
	return (1);
}

int	parse_map_file(t_game *game, int fd)
{
	char	*line;
	char	**map_lines;
	int		map_start;
	int		i;

	map_lines = malloc(sizeof(char *) * 1024);
	if (!map_lines)
		return (0);
	map_start = -1;
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (map_start == -1 && is_map_line(line))
		{
			if (!check_elements_complete(game))
			{
				free(line);
				free_array(map_lines);
				return (0);
			}
			map_start = i;
		}
		else if (map_start == -1)
		{
			if (parse_element(game, line) == -1)
			{
				print_error("Invalid element in file");
				free(line);
				free_array(map_lines);
				return (0);
			}
		}
		if (map_start != -1)
			map_lines[i - map_start] = ft_strdup(line);
		free(line);
		i++;
	}
	if (map_start == -1)
	{
		print_error("No map found in file");
		free_array(map_lines);
		return (0);
	}
	map_lines[i - map_start] = NULL;
	if (!parse_map_grid(game, map_lines, 0))
	{
		free_array(map_lines);
		return (0);
	}
	free_array(map_lines);
	return (validate_map(game));
}

int	parse_file(t_game *game, char *filename)
{
	int	fd;

	if (!validate_file_extension(filename))
		return (print_error("Invalid file extension (must be .cub)"));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (print_error("Cannot open file"));
	init_map(&game->map);
	init_player(&game->player);
	if (!parse_map_file(game, fd))
	{
		close(fd);
		free_map(&game->map);
		return (0);
	}
	close(fd);
	return (1);
}
