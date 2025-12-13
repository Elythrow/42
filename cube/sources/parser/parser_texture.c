/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:16:01 by gbazin            #+#    #+#             */
/*   Updated: 2025/12/05 17:29:45 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parser.h"

static int	check_file_exists(char *path)
{
	int		fd;
	size_t	len;

	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".xpm", 4) != 0)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	parse_texture(char *line, char **store, t_parsing *ctx, char *label)
{
	char	*path;
	int		i;

	if (*store != NULL)
		return (parse_error_detail("Duplicate texture", label, ctx), 0);
	i = ft_strlen(label);
	while (line[i] == ' ' || line[i] == '\t')
		i ++;
	path = ft_strtrim(line + i, " \t\n\r");
	if (!path)
		parse_error("Memory allocation failed", ctx);
	if (!path[0])
	{
		free(path);
		parse_error_detail("Empty texture path", label, ctx);
	}
	if (!check_file_exists(path))
	{
		free(path);
		parse_error_detail("Texture file not found", label, ctx);
	}
	*store = path;
	return (0);
}
