/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:32:39 by aerrajiy          #+#    #+#             */
/*   Updated: 2022/12/29 04:36:43 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

int	main(int argc, char *argv[], char *env[])
{
	t_process	data;
	int			res;

	if (ft_strcmp("here_doc", argv[1]))
	{
		data.outfile = open(argv[argc - 1], O_CREAT | O_APPEND | O_RDWR, 0644);
		heredoc(argv[2]);
		data.start = 3;
	}
	else
	{
		data.infile = open(argv[1], O_RDONLY);
		data.outfile = open(argv[argc - 1], O_CREAT | O_TRUNC | O_RDWR, 0644);
		dup2(data.infile, 0);
		data.start = 2;
	}
	data.argc = argc;
	data.argv = argv;
	while (data.start < argc - 1)
		execute_c(argv[data.start++], env, data);
	while (wait(&res) != -1)
		;
}
