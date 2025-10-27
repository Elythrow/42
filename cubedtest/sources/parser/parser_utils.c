/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:14:59 by gbazin            #+#    #+#             */
/*   Updated: 2025/10/27 17:31:48 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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
