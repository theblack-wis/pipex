/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:32:39 by aerrajiy          #+#    #+#             */
/*   Updated: 2022/12/28 00:30:25 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

int	open_trunc_append(char *name, int flag)
{
	int	out;

	if (flag == 0)
		return (open(name, O_CREAT | O_APPEND | O_RDWR, 0644));
	return (open(name, O_CREAT | O_TRUNC | O_RDWR, 0644));
	return (out);
}

int	main(int argc, char *argv[], char *env[])
{
	t_data_file	data;

	data.flag = 1;
	data.infile = -1;
	if (ft_strcmp(argv[1], "here_doc"))
	{
		here_doc(argv[2]);
		data.infile = open(HERE_DOC, O_RDONLY);
		data.flag = 0;
		data.start = 3;
	}
	else
	{
		data.infile = open(argv[1], O_RDONLY);
		data.start = 2;
	}
	data.outfile = open_trunc_append(argv[argc - 1], data.flag);
	wis_execute_first(argv[data.start++], env, data.infile);
	while (data.start < argc - 2)
		execute_c(argv[data.start++], env);
	wis_execute_last(argv[argc - 2], env, data.outfile);
	while (wait(NULL) != -1)
		;
	unlink(HERE_DOC);
	return (0);
}
