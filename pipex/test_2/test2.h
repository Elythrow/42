/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:15:03 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/21 20:27:17 by gbazin           ###   ########.fr       */
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

void	pip_exec(char *bin_path, int fd_in, int fd_out, char **env);
char	**pip_get_path(char **env);
char	*pip_get_exec(char *cmd, char **paths);
void	pip_error(char *s);
void	pip_close_fd(int fd1, int fd2);
void	pip_no_exec(char *s);
int		pip_check_here_doc(char **av);
void	pip_read_here_d(char *limiter, int fd_out);

#endif