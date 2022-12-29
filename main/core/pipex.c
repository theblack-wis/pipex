/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:51:30 by aerrajiy          #+#    #+#             */
/*   Updated: 2022/12/29 03:06:58 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	execute_second_command(char *argv[], char *env[], t_proc var)
{
	int	out_file;

	out_file = open(argv[4], O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (out_file == -1)
		perror("Error : can't open outfile");
	if (dup2(out_file, 1) == -1)
		perror("ERROR 4");
	if (dup2(var.fd[0], 0) == -1)
		perror("ERROR 3");
	close(var.fd[1]);
	close(out_file);
	close(var.fd[0]);
	run_execve(argv[3], env);
}

void	execute_first_command(char *argv[], char *env[], t_proc var)
{
	int	in_file;

	in_file = open(argv[1], O_RDONLY);
	if (in_file == -1)
	{
		perror("infile ");
		exit(1);
	}
	if (dup2(in_file, 0) == -1)
		perror("ERROR 2");
	if (dup2(var.fd[1], 1) == -1)
		perror("ERROR 1");
	close(var.fd[0]);
	close(in_file);
	close(var.fd[1]);
	run_execve(argv[2], env);
}

int	main(int argc, char *argv[], char *env[])
{
	t_proc	proc_env;

	if (argc != 5)
		exit(0);
	proc_env.pip = pipe(proc_env.fd);
	proc_env.proc1 = fork();
	if (proc_env.proc1 == 0)
		execute_first_command(argv, env, proc_env);
	proc_env.proc2 = fork();
	if (proc_env.proc2 == 0)
		execute_second_command(argv, env, proc_env);
	close(proc_env.fd[0]);
	close(proc_env.fd[1]);
	waitpid(proc_env.proc1, NULL, 0);
	waitpid(proc_env.proc2, &proc_env.status, 0);
	if (WIFEXITED(proc_env.status))
		exit(WEXITSTATUS(proc_env.status));
	return (0);
}
