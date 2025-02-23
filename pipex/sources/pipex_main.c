/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:06:37 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/23 15:58:40 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipe(int *pipe_fd)
{
	if (pipe(pipe_fd) < 0)
		pipex_error("Pipe error\n");
}

void	init_data(t_data *data)
{
	data->infile = -1;
	data->outfile = -1;
}

int	main(int ac, char **argv, char **envp)
{
	int		pipe_fd[2];
	int		pid1;
	int		pid2;
	t_data	data;

	if (ac != 5)
		pipex_error("Usage: ./pipex file1 cmd1 cmd2 file2\n");
	init_data(&data);
	init_pipe(pipe_fd);
	pid1 = handle_first(&data, argv, pipe_fd, envp);
	data.outfile = open(argv[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data.outfile < 0)
		pipex_error("Error opening output file\n");
	pid2 = handle_second(&data, argv, pipe_fd, envp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(data.outfile);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
