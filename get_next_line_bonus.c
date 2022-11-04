/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:11:36 by aerrajiy          #+#    #+#             */
/*   Updated: 2022/11/04 17:01:47 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_data_by_buffer_bonus(int fd, char *saved)
{
	char	*buffer;
	int		i;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	i = 1;
	while ((ft_strchr_bonus(saved, '\n') == NULL) && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i <= 0)
			break ;
		buffer[i] = '\0';
		saved = ft_strjoin_bonus(saved, buffer);
	}
	free(buffer);
	return (saved);
}

char	*split_line_bonus(char *saved)
{
	char	*new_line;
	int		i;

	new_line = malloc(sizeof(char) * ft_strlen_bonus(saved) + 1);
	if (new_line)
	{
		i = 0;
		while (saved[i] && saved[i] != '\n')
		{
			new_line[i] = saved[i];
			i++;
		}
		if (saved[i] == '\n')
			new_line[i++] = '\n';
		new_line[i] = '\0';
	}
	return (new_line);
}

char	*get_rest_data_bonus(char *saved)
{
	char	*result;
	int		i;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (!saved[i] || !saved[i + 1])
		return (free(saved), NULL);
	i++;
	result = ft_strdup_bonus(saved + i);
	free(saved);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*data[10240];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	data[fd] = read_data_by_buffer_bonus(fd, data[fd]);
	if (!data[fd])
		return (NULL);
	line = split_line_bonus(data[fd]);
	data[fd] = get_rest_data_bonus(data[fd]);
	return (line);
}
