/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:11:12 by aerrajiy          #+#    #+#             */
/*   Updated: 2022/12/29 04:36:32 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	do_proccess(int *fd, t_process data)
{
	close(fd[0]);
	if (data.start == (data.argc - 1))
		dup2(data.outfile, 1);
	else
		dup2(fd[1], 1);
	close(fd[1]);
}

void	file_not_found(char *file)
{
	char	*msg;

	msg = ft_strjoin(file, ":", "no such file or directory \n");
	ft_putstr_fd(msg, 2);
	free(msg);
	exit(1);
}

void	execute_c(char *cmd, char *env[], t_process data)
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
		if (data.start == 3 && data.infile < 0)
			file_not_found(data.argv[1]);
		do_proccess(fd, data);
		run_execve(cmd, env);
	}
}
