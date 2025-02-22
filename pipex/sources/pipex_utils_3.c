/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:50:56 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/22 21:50:08 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_s(t_data *data, char **argv, int *pipe_fd, char **envp)
{
	int	pid;

	pid = fork();
	if (pid < 0)
	{
		close(data->outfile);
		pipex_error("Fork error\n");
	}
	if (pid == 0)
	{
		close(pipe_fd[1]);
		pipex_exec(argv[3], pipe_fd[0], data->outfile, envp);
	}
	return (pid);
}
