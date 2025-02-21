/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:57:52 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/21 20:08:51 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	pip_error(char *s)
{
	ft_putstr_fd(s, STDERR_FILENO);
	exit(1);
}

/*
 * S_IRWXU : 00700
 * S_IRWXG : 00070
 * S_IRWXO : 00007
 * Flags for O_CREAT : 00777
 */

void	pip_write(char *name, int fd_in, int hd)
{
	int		fd_out;
	int		b_read;
	char	buff[1];

	if (hd)
		fd_out = open(name, O_RDWR | O_CREAT | O_APPEND, 00777);
	else
	{
		if (access(name, F_OK) == 0)
			unlink(name);
		fd_out = open(name, O_WRONLY | O_CREAT, 00777);
	}
	if (fd_out < 0)
		pip_error("pip_write: fd_out error.");
	if (fd_in < 0)
		pip_error("pip_write: fd_in error.");
	b_read = read(fd_in, &buff, sizeof(char));
	while (b_read > 0)
	{
		write(fd_out, &buff, 1);
		b_read = read(fd_in, &buff, sizeof(char));
	}
}

void	pip_close_fd(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

void	pip_renew_pipe(int (*p)[2])
{
	pip_close_fd((*p)[0], (*p)[1]);
	pipe((*p));
}

void	pip_wait_children(int i)
{
	int	status;

	while (i-- > 0)
		wait(&status);
}
