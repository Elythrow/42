/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:30:33 by gbazin            #+#    #+#             */
/*   Updated: 2024/11/25 19:51:15 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_line_buffer(int fd, char *rest, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(rest);
			return (0);
		}
		else if (b_read == 0)
			break ;
		buffer[b_read] = 0;
		if (!rest)
			rest = ft_strdup("");
		tmp = rest;
		rest = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (rest);
}

static char	*set_line(char *line_buffer)
{
	char	*lstring;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0)
		return (0);
	lstring = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*lstring == 0)
	{
		free(lstring);
		lstring = NULL;
	}
	line_buffer[i + 1] = 0;
	return (lstring);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*buffer;

	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		free(rest);
		buffer = NULL;
		rest = NULL;
		line = NULL;
		return (NULL);
	}
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	line = fill_line_buffer(fd, rest, buffer);
	free(buffer);
	buffer = NULL;
	if (line == NULL)
		return (NULL);
	rest = set_line(line);
	return (line);
}
