/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:56:48 by gbazin            #+#    #+#             */
/*   Updated: 2025/10/07 17:57:17 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_empty_line(char *line)
{
	int	i;

	if (!line)
		return (1);
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && 
			line[i] != '\n' && line[i] != '\r')
			return (0);
		i ++;
	}
	return (1);
}

int	is_map_line(char *line)
{
	int	i;

	if (!line || is_empty_line(line))
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] != EMPTY_SPACE && line[i] != WALL &&
			line[i] != NORTH && line[i] != SOUTH &&
			line[i] != EAST && line[i] != WEST &&
			line[i] != SPACE && line[i] != '\n' &&
			line[i] != '\t')
			return (0);
		i ++;
	}
	return (1);
}

int	is_valid_map_char(char c)
{
	return (c == EMPTY_SPACE || c == WALL || 
			c == SPACE || c == NORTH || 
			c == SOUTH || c == EAST || c == WEST);
}

char	*trim_newline(char *line)
{
	int	len;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	array_len(char **array)
{
	int	i;

	if (!array)
		return (0);
	i = 0;
	while (array[i])
		i ++;
	return (i);
}

int	count_file_lines(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		count ++;
		free(line);
	}
	close(fd);
	return (count);
}

char	**read_file_lines(char *filename)
{
	int		fd;
	int		lines;
	char	**result;
	char	*line;
	int		i;

	lines = count_file_lines(filename);
	if (lines == 0)
		return (NULL);
	result = malloc(sizeof(char *) * (lines + 1));
	if (!result)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(result);
		return (NULL);
	}
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		result[i] = line;
		i ++;
	}
	result[i] = NULL;
	close(fd);
	return (result);
}
