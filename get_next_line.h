/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:33:50 by aerrajiy          #+#    #+#             */
/*   Updated: 2022/10/31 23:10:46 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include <fcntl.h> 

typedef struct t_space {
    char *save;
    char *line;
}   s_space;

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char *read_text_form_file(int fd, char *save);
char *get_next_line(int fd);

#endif