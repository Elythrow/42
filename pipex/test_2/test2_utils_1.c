/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:17:01 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/21 20:45:51 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test2.h"

/**
 * Execute a command with redirected input and output
 */
void	pip_exec(char *bin, int fd_in, int fd_out, char **env)
{
	char	**args;
	char	**paths;

	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_in);
	close(fd_out);
	paths = pip_get_path(env);
	args = ft_split(bin, ' ');
	args[0] = pip_get_exec(args[0], paths);
	execve(args[0], args, env);
	pip_error("Execution failed\n");
}

char	**pip_get_path(char **env)
{
	char	**paths;

	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			break ;
		env++;
	}
	if (*env)
		paths = ft_split(*env + 5, ':');
	else
		paths = NULL;
	return (paths);
}


char	*pip_get_exec(char *cmd, char **paths)
{
	char	*path;
	char	*temp;

	if (cmd && cmd[0] == '/' && access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	if (cmd && cmd[0] == '.' && cmd[1] == '/' && access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	if (!cmd)
	{
		pip_no_exec("empty command");
		return (NULL);
	}
	if (!paths)
	{
		pip_no_exec(cmd);
		return (NULL);
	}
	while (*paths)
	{
		temp = ft_strjoin(*paths, "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		paths++;
	}
	pip_no_exec(cmd);
	return (NULL);
}

int	pip_check_here_doc(char **av)
{
	if (av[1] && ft_strncmp(av[1], "here_doc", 9) == 0)
		return (1);
	return (0);
}
