/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:14:59 by gbazin            #+#    #+#             */
/*   Updated: 2025/12/05 18:59:52 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_config(t_config *cfg)
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
	cfg->player.pos.x = 0;
	cfg->player.pos.y = 0;
	cfg->player.dir.x = 0;
	cfg->player.dir.y = 0;
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
			&& line[i] != '\r')
			return (0);
		i ++;
	}
	return (1);
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	if (!line || !line[0])
		return (0);
	while (line[i] == ' ' || line[i] == '\t')
		i ++;
	if (line[i] == '1' || line[i] == '0')
		return (1);
	return (0);
}

void	free_split(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i ++;
	}
	free(tab);
}

int	has_cub_extension(const char *path)
{
	int	len;

	if (!path)
		return (0);
	len = ft_strlen(path);
	if (len < 4)
		return (0);
	if (ft_strncmp(path + len - 4, ".cub", 4) == 0)
		return (1);
	return (0);
}
