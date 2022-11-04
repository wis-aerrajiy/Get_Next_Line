/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 22:47:36 by aerrajiy          #+#    #+#             */
/*   Updated: 2022/11/04 17:00:53 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_bonus(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup_bonus(char *s1)
{
	char	*dup;
	int		len;
	int		i;

	len = ft_strlen_bonus(s1);
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (dup = NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strchr_bonus(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + ft_strlen_bonus(s));
	return (0);
}

char	*ft_strjoin_bonus(char *s1, char *s2)
{
	int		len;
	int		i;
	int		s;
	char	*joined;

	s = 0;
	i = 0;
	if (!s1)
		s1 = ft_strdup_bonus("");
	len = ft_strlen_bonus((char *)s1) + ft_strlen_bonus((char *)s2);
	joined = malloc((len + 1) * sizeof(char));
	if (joined == NULL)
		return (NULL);
	while (((char *)s1)[i] != '\0')
		joined[s++] = ((char *)s1)[i++];
	i = 0;
	while (((char *)s2)[i] != '\0')
		joined[s++] = ((char *)s2)[i++];
	joined[s] = '\0';
	free(s1);
	return (joined);
}
