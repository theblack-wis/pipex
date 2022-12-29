/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:46:39 by aerrajiy          #+#    #+#             */
/*   Updated: 2022/12/29 03:00:27 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

// structs to mak life easy and f*k norm
typedef struct s_proc
{
	int		fd[2];
	int		proc1;
	int		proc2;
	int		pip;
	int		status;
	char	**splited;
	char	**command;
	char	*path;
}	t_proc;

// tools
char	*ft_strjoin(char const *path, char *slash, char const *cmd);
size_t	ft_strlen(const char *str);
char	*ft_strstr(const char *haystack, const char *needle);
char	**read_and_split_path(char *env[]);
void	check_path_error(char *path, char *cmd);
void	run_execve(char *cmd, char *env[]);

char	**ft_split(char const *s, char c);
char	*insert_cpy(char **ptr, char *str, char c);
int		words_count(char *s, char c);
void	free_me(char **pointer);
void	ft_putstr_fd(char *s, int fd);

#endif