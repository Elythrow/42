/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:06:37 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/22 21:50:10 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipe(int *pipe_fd)
{
	if (pipe(pipe_fd) < 0)
		pipex_error("Pipe error\n");
}

void	init_data(t_data *data, int ac, char **argv)
{
	data->here_d = pipe_first_pars(ac, argv);
	data->infile = -1;
	data->outfile = -1;
}

int	handle_here_doc(t_data *data, char **argv, int *pipe_fd, int ac)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		pipex_error("Fork error\n");
	if (pid == 0)
	{
		close(pipe_fd[0]);
		pipex_read_here_d(argv[2], pipe_fd[1]);
		exit(0);
	}
	waitpid(pid, NULL, 0);
	data->outfile = open(argv[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	return (pid);
}

int	handle(t_data *data, char **argv, int *pipe_fd, char **envp)
{
	int	pid;

	data->infile = open(argv[1], O_RDONLY);
	if (data->infile < 0)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	pid = fork();
	if (pid < 0)
	{
		if (data->infile >= 0)
			close(data->infile);
		pipex_error("Fork error\n");
	}
	if (pid == 0)
	{
		close(pipe_fd[0]);
		pipex_exec(argv[2], data->infile, pipe_fd[1], envp);
	}
	if (data->infile >= 0)
		close(data->infile);
	return (pid);
}

int	main(int ac, char **argv, char **envp)
{
	int		pipe_fd[2];
	int		pid1;
	int		pid2;
	t_data	data;

	init_data(&data, ac, argv);
	init_pipe(pipe_fd);
	if (data.here_d)
	{
		pid1 = handle_here_doc(&data, argv, pipe_fd, ac);
	}
	else
	{
		pid1 = handle(&data, argv, pipe_fd, envp);
		data.outfile = open(argv[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (data.outfile < 0)
		pipex_error("Error opening output file\n");
	pid2 = handle_s(&data, argv, pipe_fd, envp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(data.outfile);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
