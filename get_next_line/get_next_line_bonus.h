/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:13:07 by gbazin            #+#    #+#             */
/*   Updated: 2024/11/15 13:56:57 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# elif BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# elif BUFFER_SIZE > 999999
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 999999
# endif

char	*get_next_line(int fd);
char	*fill_line_buffer(int fd, char *left_c, char *buffer);
char	*set_line(char *line_buffer);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(char *str);
size_t	ft_strlen(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);

#endif