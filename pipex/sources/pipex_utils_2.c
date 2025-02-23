/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:19:45 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/23 17:46:57 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_first(t_data *data, char **argv, int *pipe_fd, char **envp)
{
	int	pid;

	data->infile = open(argv[1], O_RDONLY);
	pid = fork();
	if (pid < 0)
	{
		if (data->infile >= 0)
			close(data->infile);
		pipex_error("Fork error\n");
	}
	if (pid == 0)
	{
		if (data->infile < 0)
		{
			handle_infile_error(argv[1]);
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			exit(1);
		}
		exec_first_command(argv, pipe_fd, envp, data->infile);
	}
	if (data->infile >= 0)
		close(data->infile);
	return (pid);
}

int	handle_second(t_data *data, char **argv, int *pipe_fd, char **envp)
{
	int	pid;

	pid = fork();
	if (pid < 0)
	{
		close(data->outfile);
		pipex_error("Fork error\n");
	}
	if (pid == 0)
		exec_second_command(argv, pipe_fd, envp, data->outfile);
	return (pid);
}

void	exec_first_command(char **argv, int *pipe_fd, char **envp, int fd_in)
{
	close(pipe_fd[0]);
	pipex_exec(argv[2], fd_in, pipe_fd[1], envp);
}

void	exec_second_command(char **argv, int *pipe_fd, char **envp, int fd_out)
{
	close(pipe_fd[1]);
	pipex_exec(argv[3], pipe_fd[0], fd_out, envp);
}
