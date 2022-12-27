/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:28:16 by aerrajiy          #+#    #+#             */
/*   Updated: 2022/12/28 00:35:05 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

# define HERE_DOC ".data_heroc_store"

typedef struct s_data
{
	int	infile;
	int	outfile;
	int	fd[2];
	int	proc1;
	int	pip;
	int	start;
	int	flag;
}	t_data_file;

void	wis_execute_first(char *cmd, char *env[], int intfile);
void	wis_execute_last(char *cmd, char *env[], int outfile);
void	execute_c(char *cmd, char *env[]);
char	**read_and_split_path(char *env[]);
void	run_execve(char *cmd, char *env[]);
int		ft_strcmp(const char *s1, const char *s2);
void	here_doc(char *limiter);
void	close_fd(int *fd);
char	*get_next_line(int fd);

#endif