/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:19:45 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/21 20:42:00 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test2.h"

/**
 * Display error message and exit
 */
void	pip_error(char *s)
{
	ft_putstr_fd(s, STDERR_FILENO);
	exit(1);
}

/**
 * Close two file descriptors
 */
void	pip_close_fd(int fd1, int fd2)
{
	if (fd1 >= 0)
		close(fd1);
	if (fd2 >= 0)
		close(fd2);
}

/**
 * Display command not found error and exit
 */
void	pip_no_exec(char *s)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	if (s)
		ft_putstr_fd(s, STDERR_FILENO);
	else
		ft_putstr_fd("(null)", STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	exit(127);
}

/**
 * Read heredoc input until delimiter is found
 */
void	pip_read_here_d(char *limiter, int fd_out)
{
	char	*line;
	char	*tmp;

	if (!limiter)
		pip_error("Heredoc: No delimiter specified\n");
	ft_putstr_fd("heredoc> ", STDOUT_FILENO);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		tmp = ft_strtrim(line, "\n");
		if (ft_strncmp(tmp, limiter, ft_strlen(limiter) + 1) == 0)
		{
			free(tmp);
			free(line);
			break ;
		}
		ft_putstr_fd(line, fd_out);
		free(tmp);
		free(line);
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
	}
	close(fd_out);
}
