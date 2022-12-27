/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:24:39 by aerrajiy          #+#    #+#             */
/*   Updated: 2022/12/28 00:33:37 by aerrajiy         ###   ########.fr       */
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

void	here_doc(char *limiter)
{
	char	*line;
	int		fd;

	unlink(HERE_DOC);
	fd = open(HERE_DOC, O_CREAT | O_RDWR | O_TRUNC, 0644);
	line = get_next_line(0);
	while (line)
	{
		if (!ft_strcmp(line, limiter))
			ft_putendl_fd(line, fd);
		else
			break ;
		line = get_next_line(0);
	}
}
