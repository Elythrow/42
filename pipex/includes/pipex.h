/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:15:03 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/23 17:18:21 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_data
{
	int		infile;
	int		outfile;
}	t_data;

void	init_pipe(int *pipe_fd);
void	init_data(t_data *data);
void	pipex_exec_kill(char *original_cmd, char **args, char **paths);
void	pipex_exec(char *bin, int fd_in, int fd_out, char **env);
char	**pipex_get_path(char **env);
char	*pipex_get_exec(char *cmd, char **paths);
void	pipex_paths_kill(char **paths);
int		handle_first(t_data *data, char **argv, int *pipe_fd, char **envp);
int		handle_second(t_data *data, char **argv, int *pipe_fd, char **envp);
void	exec_first_command(char **argv, int *pipe_fd, char **envp, int fd_in);
void	exec_second_command(char **argv, int *pipe_fd, char **envp, int fd_out);
void	handle_infile_error(char *filename);
void	pipex_error(char *s);
void	pipex_close_fd(int fd1, int fd2);

#endif