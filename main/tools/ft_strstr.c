/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:45:21 by aerrajiy          #+#    #+#             */
/*   Updated: 2022/12/23 22:01:40 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	f;

	i = 0;
	f = 0;
	if (!haystack)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			while ((haystack[i + f] == needle[f]) && needle[f] != '\0')
				f++;
			if (f == ft_strlen(needle))
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
