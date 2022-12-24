/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:48:46 by aerrajiy          #+#    #+#             */
/*   Updated: 2022/12/23 22:02:10 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	free_me(char **pointer)
{
	int	i;

	i = 0;
	while (pointer[i])
	{
		free(pointer[i]);
		i++;
	}
	free(pointer);
}

int	words_count(char *s, char c)
{
	int	nb_strings;
	int	i;

	i = 0;
	nb_strings = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			nb_strings++;
		}
		if (s[i])
			i++;
	}
	return (nb_strings);
}

char	*insert_cpy(char **ptr, char *str, char c)
{
	int	i;
	int	k;
	int	len;
	int	lop;

	i = 0;
	k = 0;
	len = 0;
	lop = 0;
	while (str[len] == c)
		len++;
	while ((str + len)[k] != c && (str + len)[k] != '\0')
		k++;
	*ptr = malloc((k + 1) * sizeof(char));
	if (*ptr != NULL)
	{
		lop = len;
		while (str[lop] != '\0' && str[lop] != c)
		{
			(*ptr)[i++] = str[lop++];
		}
		(*ptr)[i] = '\0';
		return (str + (k + len));
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tabs;
	int		i;
	int		count;
	char	*ppp;

	ppp = (char *)s;
	if (!ppp)
		return (NULL);
	i = -1;
	count = words_count(ppp, c);
	tabs = (char **)malloc(sizeof(char *) * (count + 1));
	if (tabs != NULL)
	{
		tabs[count] = NULL;
		while (++i < count)
		{
			ppp = insert_cpy(tabs + i, ppp, c);
			if (ppp == NULL)
				return (NULL);
		}
	}
	return (tabs);
}
