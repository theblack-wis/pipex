/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 03:24:36 by aerrajiy          #+#    #+#             */
/*   Updated: 2022/12/29 04:37:03 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while ((ss1[i] != '\0' || ss2[i] != '\0'))
	{
		if (ss1[i] != ss2[i])
			return (0);
		i++;
	}
	return (1);
}

void	read_heredoc(int *fd, char *limiter)
{
	char	*line;

	close(fd[0]);
	ft_putstr_fd("heredoc> ", 1);
	line = get_next_line(0);
	while (line)
	{
		ft_putstr_fd("heredoc> ", 1);
		line = get_next_line(0);
		if (ft_strcmp(line, limiter))
		{
			close(fd[1]);
			exit(0);
		}
		ft_putstr_fd(line, fd[1]);
		write(fd[1], "\n", 1);
	}
	close(fd[1]);
}

void	heredoc(char *limiter)
{
	t_data_file	data;

	data.pip = pipe(data.fd);
	data.proc1 = fork();
	if (data.proc1 == 0)
		read_heredoc(data.fd, limiter);
	else
	{
		close(data.fd[1]);
		dup2(data.fd[0], 0);
		close(data.fd[0]);
		waitpid(data.proc1, NULL, 0);
	}
}
