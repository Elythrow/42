/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:15:03 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/22 20:49:47 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST2_H
# define TEST2_H
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_data
{
	int	infile;
	int	outfile;		
	int	here_d;	
}	t_data;

void	pipex_exec(char *bin_path, int fd_in, int fd_out, char **env);
char	**pipex_get_path(char **env);
char	*pipex_get_exec(char *cmd, char **paths);
void	pipex_error(char *s);
void	pipex_close_fd(int fd1, int fd2);
int		pipex_check_here_doc(char **av);
void	pipex_read_here_d(char *limiter, int fd_out);
void	pipex_exec_kill(char *original_cmd, char **args, char **paths);
void	pipex_paths_kill(char **paths);
int		pipe_first_pars(int argc, char **argv);
void	init_pipe(int *pipe_fd);
void	init_data(t_data *data, int ac, char **argv);
int		handle_here_doc(t_data *data, char **argv, int *pipe_fd, int ac);
int		handle(t_data *data, char **argv, int *pipe_fd, char **envp);
int		handle_s(t_data *data, char **argv, int *pipe_fd, char **envp);

#endif