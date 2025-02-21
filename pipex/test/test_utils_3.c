/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:58:19 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/21 20:08:44 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "test.h"

// check for here_doc before writing out
void	pip_write_result(int ac, char **av, int (*op)[2], int (*ip)[2])
{
	int	here_d;

	here_d = 0;
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		here_d = 1;
	if (((ac - here_d) % 2) == 0)
		pip_write(av[ac - 1], (*op)[0], here_d);
	else
		pip_write(av[ac - 1], (*ip)[0], here_d);
}

void	pip_no_exec(char *s)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(s, STDERR_FILENO);
	ft_putstr_fd(" : command not found.", STDERR_FILENO);
	exit(1);
}
