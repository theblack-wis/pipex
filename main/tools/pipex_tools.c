/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:11:34 by aerrajiy          #+#    #+#             */
/*   Updated: 2022/12/23 22:02:37 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

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

void	check_path_error(char *path)
{
	if (access(path, F_OK) == -1)
	{
		write(2, "pip : command not found\n", 25);
		exit(127);
	}
}