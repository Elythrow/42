/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:19:45 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/22 21:50:10 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	pipex_error(char *s)
{
	ft_putstr_fd(s, STDERR_FILENO);
	exit(1);
}

void	pipex_close_fd(int fd1, int fd2)
{
	if (fd1 >= 0)
		close(fd1);
	if (fd2 >= 0)
		close(fd2);
}

void	pipex_read_here_d(char *limiter, int fd_out)
{
	char	*line;
	char	*tmp;

	if (!limiter)
		pipex_error("Heredoc: No delimiter specified\n");
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

void	pipex_paths_kill(char **paths)
{
	if (paths)
		ft_free_tab(paths);
	exit(127);
}

int	pipe_first_pars(int argc, char **argv)
{
	int	here_d;

	here_d = pipex_check_here_doc(argv);
	if (here_d && argc < 6)
		pipex_error("Usage: ./pipex here_doc LIMITER cmd1 cmd2 file2\n");
	if (argc < 5)
		pipex_error("Usage: ./pipex file1 cmd1 cmd2 file2\n");
	return (here_d);
}
