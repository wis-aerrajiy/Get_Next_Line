/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:33:15 by aerrajiy          #+#    #+#             */
/*   Updated: 2022/11/01 17:49:14 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	
	i = 0;
	if(!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *) s + i);
		i++;
	}	
	if ((char)c == '\0')
		return ((char *)s + strlen(s));
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		i;
	int		s;
	char	*joined;

	if (!s1)
	{
		s1 = (char *) malloc (sizeof(char));
		s1[0] = '\0';
	}
	s = 0;
	i = 0;
	len = strlen((char *)s1) + strlen((char *)s2);
	joined = (char *) malloc((len + 1) * sizeof(char));
	if (joined == NULL)
		return (NULL);
	while (((char *)s1)[i] != '\0')
		joined[s++] = ((char *)s1)[i++];
	i = 0;
	while (((char *)s2)[i] != '\0')
		joined[s++] = ((char *)s2)[i++];
	joined[s] = '\0';
	free (s1);
	return (joined);
}