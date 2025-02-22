/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:17:01 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/22 21:50:11 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_exec_kill(char *original_cmd, char **args, char **paths)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	if (original_cmd)
		ft_putstr_fd(original_cmd, STDERR_FILENO);
	else
		ft_putstr_fd("(null)", STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	ft_free_tab(args);
	if (paths)
		ft_free_tab(paths);
	exit(127);
}

void	pipex_exec(char *bin, int fd_in, int fd_out, char **env)
{
	char	**args;
	char	**paths;
	char	*exec_path;
	char	*original_cmd;

	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_in);
	close(fd_out);
	paths = pipex_get_path(env);
	args = ft_split(bin, ' ');
	if (!args)
		pipex_paths_kill(paths);
	original_cmd = args[0];
	exec_path = pipex_get_exec(original_cmd, paths);
	if (!exec_path)
		pipex_exec_kill(original_cmd, args, paths);
	free(original_cmd);
	args[0] = exec_path;
	execve(args[0], args, env);
	ft_free_tab(args);
	if (paths)
		ft_free_tab(paths);
	pipex_error("Execution failed\n");
}

char	**pipex_get_path(char **env)
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

char	*pipex_get_exec(char *cmd, char **paths)
{
	char	*path;
	char	*temp;

	if (cmd && cmd[0] == '/' && access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	if (cmd && cmd[0] == '.' && cmd[1] == '/' && access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	if (!cmd || !paths)
		return (NULL);
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
	return (NULL);
}

int	pipex_check_here_doc(char **av)
{
	if (av[1] && ft_strncmp(av[1], "here_doc", 9) == 0)
		return (1);
	return (0);
}
