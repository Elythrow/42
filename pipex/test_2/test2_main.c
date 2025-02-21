/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:06:37 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/21 20:32:20 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test2.h"

int	main(int ac, char *av[], char *envp[])
{
	int	pipe_fd[2];
	int	pid1;
	int	pid2;
	int	infile;
	int	outfile;
	int	here_d;

	// Check argument count
	if (ac < 5)
		pip_error("Usage: ./pipex file1 cmd1 cmd2 file2\n       ./pipex here_doc LIMITER cmd1 cmd2 file2\n");
	// Check for heredoc
	here_d = pip_check_here_doc(av);
	if (here_d && ac < 6)
		pip_error("Usage for here_doc: ./pipex here_doc LIMITER cmd1 cmd2 file2\n");
	// Create pipe
	if (pipe(pipe_fd) < 0)
		pip_error("Pipe error\n");
	// Handle input (file or heredoc)
	if (here_d)
	{
		// Handle heredoc input
		pid1 = fork();
		if (pid1 < 0)
			pip_error("Fork error\n");
		if (pid1 == 0)
		{
			close(pipe_fd[0]);
			pip_read_here_d(av[2], pipe_fd[1]);
			exit(0);
		}
		waitpid(pid1, NULL, 0);
		// Open output file in append mode for heredoc
		outfile = open(av[ac-1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		// Handle regular file input
		infile = open(av[1], O_RDONLY);
		if (infile < 0)
		{
			ft_putstr_fd("pipex: ", 2);
			ft_putstr_fd(av[1], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
		}
		// First child - execute first command
		pid1 = fork();
		if (pid1 < 0)
			pip_error("Fork error\n");
		if (pid1 == 0)
		{
			close(pipe_fd[0]);
			pip_exec(av[2], infile, pipe_fd[1], envp);
		}
		// Open output file in trunc mode for regular operation
		outfile = open(av[ac-1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (outfile < 0)
		pip_error("Error opening output file\n");
	// Second child - execute second command
	pid2 = fork();
	if (pid2 < 0)
		pip_error("Fork error\n");
	if (pid2 == 0)
	{
		close(pipe_fd[1]);
		// If heredoc, command index is shifted
		if (here_d)
			pip_exec(av[3], pipe_fd[0], outfile, envp);
		else
			pip_exec(av[3], pipe_fd[0], outfile, envp);
	}
	// Parent process
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (!here_d)
		close(infile);
	close(outfile);
	// Wait for the second child
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
