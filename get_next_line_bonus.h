/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:12:15 by aerrajiy          #+#    #+#             */
/*   Updated: 2022/11/04 17:00:42 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*read_data_by_buffer_bonus(int fd, char *saved);
char	*split_line_bonus(char *saved);
char	*get_rest_data_bonus(char *saved);

char	*ft_strdup_bonus(char *s);
char	*ft_strjoin_bonus(char *s1, char *s2);
size_t	ft_strlen_bonus(char *s);
char	*ft_strchr_bonus(char *s, int c);

#endif
