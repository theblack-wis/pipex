/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:28:16 by aerrajiy          #+#    #+#             */
/*   Updated: 2022/12/29 04:34:57 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_data
{
	int	fd[2];
	int	proc1;
	int	pip;
}	t_data_file;

typedef struct s_proc
{
	int		infile;
	int		outfile;
	int		start;
	int		check;
	int		argc;
	char	**argv;
}	t_process;

void	execute_c(char *cmd, char *env[], t_process data);
char	**read_and_split_path(char *env[]);
void	run_execve(char *cmd, char *env[]);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *path, char *slash, char const *cmd);
char	*get_next_line(int fd);
int		ft_strcmp(const char *s1, const char *s2);
void	heredoc(char *limiter);
void	read_heredoc(int *fd, char *limiter);

#endif