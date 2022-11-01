/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:23:11 by aerrajiy          #+#    #+#             */
/*   Updated: 2022/11/01 17:52:13 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_text_form_file(int fd, char *save)
{
    char *buffer;
    int i;
    
    i = 1;
    buffer = (char *)malloc( (BUFFER_SIZE + 1) * sizeof(char) );
    while (!ft_strchr(save, '\n') && i != 0)
    {
        i = read(fd, buffer, BUFFER_SIZE);
        
        if(i <= 0)
        {
            free(save);
            free(buffer);
            return (NULL);
        }
        
        buffer[i] = '\0';
        save = ft_strjoin(save, buffer);
    }
    free(buffer);
    return (save);
}

char *split_line_from_save(char *save)
{
    int i;
    char *new_save;

    i = 0;
    while (save[i] && save[i] != '\n')
        i++;
    if(!save[i])
        return (0);
    new_save = (char *) malloc (sizeof (char) * (i + 2));
    if(!new_save)
        return (NULL);
    i = 0;
    while (save[i] && save[i - 1] != '\n')
    {
        new_save[i] = save[i];
        i++;
    }
    //new_save[i++] = '\n';
    new_save[i] = '\0';
    return (new_save);
}

char * save_the_rest_after_back_n(char *save)
{
    int i;
    int j;
    char *rest_save;

    i = 0;
    j = 0;
    while (save[i] && save[i] != '\n')
        i++;
    if(!save[i])
    {
        free (save);
        return (NULL);
    }
    rest_save = (char *) malloc (sizeof(char) * (strlen(save) - i + 1));
    i++;
    while (save[i])
        rest_save[j++] = save[i++];
    rest_save[j] = '\0';
    free (save);
    return (rest_save);
}

char *get_next_line(int fd)
{
    static char *saved;
    char *line;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    saved = read_text_form_file(fd, saved);
    if(!saved)
        return (NULL);
    line  = split_line_from_save(saved);
    saved = save_the_rest_after_back_n(saved);

    return (line);
}

// int main()
// {
//     int fd = open("wis.txt", O_RDWR);
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//    // system("leaks a.out");
// }