/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:16:01 by gbazin            #+#    #+#             */
/*   Updated: 2025/10/27 17:30:15 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parse.h"

static int	check_file_exists(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	parse_texture(char *line, char **store, t_parsing *ctx, char *label)
{
	char	*path;
	int		label_len;

	if (*store != NULL)
	{
		parse_error_detail("Duplicate texture", label, ctx);
		return (0);
	}
	label_len = ft_strlen(label);
	path = ft_strtrim(line + label_len, " \t\n\r");
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
