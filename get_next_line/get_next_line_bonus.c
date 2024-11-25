/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:09:43 by gbazin            #+#    #+#             */
/*   Updated: 2024/11/25 19:54:04 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *ptr, size_t n)
{
	unsigned char	*str;

	str = ptr;
	while (n)
	{
		*str = '\0';
		str ++;
		n --;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(0);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	else if (size != 0 && SIZE_MAX / size <= nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

static char	*fill_buffer(int fd, char *rest, char *buffer)
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

static char	*store_rest(char *line_buffer)
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
	static char	*rest[1024] = {0};
	char		*line;
	char		*buffer;

	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		free(rest[fd]);
		buffer = NULL;
		rest[fd] = NULL;
		line = NULL;
		return (NULL);
	}
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	line = fill_buffer(fd, rest[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (line == NULL)
		return (NULL);
	rest[fd] = store_rest(line);
	return (line);
}
/*
int main(void)
{
    int		fd1;
	int		fd2;
	int		fd3;
    char 	*line1;
	char	*line2;
	char	*line3;
    int 	tour;

	tour = 1;
    fd1 = open("test1.txt", O_RDONLY);
    fd2 = open("test2.txt", O_RDONLY);
    fd3 = open("test3.txt", O_RDONLY);
    if (fd1 < 0 || fd2 < 0 || fd3 < 0)
    {
        printf("Erreur lors de l'ouverture des fichiers\n");
        return 1;
    }
    line1 = get_next_line(fd1);
    line2 = get_next_line(fd2);
    line3 = get_next_line(fd3);

    while (line1 || line2 || line3)
    {
        printf("--- Tour %d ---\n", tour);

        if (line1)
        {
            printf("Fichier 1: %s", line1);
            free(line1);
            line1 = get_next_line(fd1);
        }
        else
            printf("Fichier 1: fin de fichier\n");

        if (line2)
        {
            printf("Fichier 2: %s", line2);
            free(line2);
            line2 = get_next_line(fd2);
        }
        else
            printf("Fichier 2: fin de fichier\n");

        if (line3)
        {
            printf("Fichier 3: %s", line3);
            free(line3);
            line3 = get_next_line(fd3);
        }
        else
            printf("Fichier 3: fin de fichier\n");

        printf("\n");
        tour++;
    }
    close(fd1);
    close(fd2);
    close(fd3);
    return 0;
}
*/