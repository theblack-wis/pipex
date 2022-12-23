/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:20:37 by aerrajiy          #+#    #+#             */
/*   Updated: 2022/12/23 19:08:00 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/pipex.h"

char	*ft_strjoin(char const *path, char *slash, char const *cmd)
{
	int		len;
	int		i;
	int		s;
	char	*joined;

	if (!path || !cmd)
		return (NULL);
	s = 0;
	i = 0;
	len = ft_strlen((char *)path) + ft_strlen((char *)cmd);
	joined = malloc((len + 2) * sizeof(char));
	if (joined == NULL)
		return (NULL);
	while (((char *)path)[i] != '\0')
		joined[s++] = ((char *)path)[i++];
	i = 0;
	joined[s++] = slash[i];
	while (((char *)cmd)[i] != '\0')
		joined[s++] = ((char *)cmd)[i++];
	joined[s] = '\0';
	return (joined);
}
