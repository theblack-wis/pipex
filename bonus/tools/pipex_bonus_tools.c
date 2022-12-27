/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:11:12 by aerrajiy          #+#    #+#             */
/*   Updated: 2022/12/28 00:33:32 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	wis_execute_first(char *cmd, char *env[], int intfile)
{
	t_data_file	data;

	data.pip = pipe(data.fd);
	data.proc1 = fork();
	if (data.proc1 == 0)
	{
		if (intfile < 0)
			exit(1);
		close(data.fd[0]);
		dup2(intfile, 0);
		dup2(data.fd[1], 1);
		close(data.fd[1]);
		run_execve(cmd, env);
	}
	else
	{
		close(data.fd[1]);
		dup2(data.fd[0], 0);
		close(data.fd[0]);
	}
}

void	wis_execute_last(char *cmd, char *env[], int outfile)
{
	t_data_file	data;

	data.pip = pipe(data.fd);
	data.proc1 = fork();
	if (data.proc1 == 0)
	{
		close(data.fd[0]);
		dup2(outfile, 1);
		close(data.fd[1]);
		run_execve(cmd, env);
	}
	else
	{
		close(data.fd[1]);
		close(data.fd[0]);
	}
}

void	execute_c(char *cmd, char *env[])
{
	int	fd[2];
	int	proc;
	int	pip;

	pip = pipe(fd);
	if (pip < 0)
		perror("ERROR 2");
	proc = fork();
	if (proc < 0)
		perror("ERROR 3");
	if (proc != 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		run_execve(cmd, env);
	}
}

void	ft_putendl_fd(char *s, int fd)
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
	write(fd, "\n", 1);
}

void	close_fd(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}
