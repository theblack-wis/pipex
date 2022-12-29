/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:11:34 by aerrajiy          #+#    #+#             */
/*   Updated: 2022/12/29 03:13:15 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

char	**read_and_split_path(char *env[])
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strstr(env[i], "PATH"))
			return (ft_split(env[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

void	check_path_error(char *path, char *cmd)
{
	char	*msg;

	if (access(path, X_OK) == -1)
	{
		msg = ft_strjoin(cmd, ":", " command not found\n");
		ft_putstr_fd(msg, 2);
		free(msg);
		exit(127);
	}
}

void	run_execve(char *cmd, char *env[])
{
	t_proc	data;
	int		i;
	int		k;

	i = 0;
	k = 1;
	data.splited = read_and_split_path(env);
	data.command = ft_split(cmd, ' ');
	data.path = cmd;
	if (access(data.path, X_OK) != -1)
		k = 0;
	while (k && data.splited && data.splited[i])
	{
		data.path = ft_strjoin(data.splited[i++], "/", data.command[0]);
		if (access(data.path, X_OK) != -1)
			break ;
		free(data.path);
	}
	free_me(data.splited);
	if (execve(data.path, data.command, NULL) == -1)
	{
		check_path_error(data.path, cmd);
		exit(1);
	}
}
