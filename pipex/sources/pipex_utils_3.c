/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:50:56 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/23 17:43:27 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_infile_error(char *filename)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(filename, 2);
	if (access(filename, F_OK) == 0)
		ft_putstr_fd(": Permission denied\n", 2);
	else
		ft_putstr_fd(": No such file or directory\n", 2);
}

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
