/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:56:47 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/21 20:09:28 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(int ac, char *av[], char *envp[])
{
	int	pipe1[2];
	int	pipe2[2];
	int	i;
	int	here_d;

	pip_check_ac(ac);
	pip_renew_pipe(&pipe1);
	pip_renew_pipe(&pipe2);
	here_d = pip_check_here_doc(av, &pipe2);
	i = 0;
	while (i < ac - here_d - 3)
	{
		if (i % 2 == 0)
			pip_new_f_process(av[i + here_d + 2], &pipe2, &pipe1, envp);
		else
			pip_new_s_process(av[i + here_d + 2], &pipe2, &pipe1, envp);
		i++;
	}
	pip_close_fd(pipe1[1], pipe2[1]);
	pip_wait_children(i);
	pip_write_result(ac, av, &pipe1, &pipe2);
	return (0);
}
