/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:55:05 by aerrajiy          #+#    #+#             */
/*   Updated: 2022/10/31 23:08:25 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef struct t_space {
    char *save;
    char *line;
}   s_space;

s_space *op()
{
    s_space *new;
    new = malloc(sizeof(s_space));
    
    new->line = strdup("abcd");
    new->save = strdup("bacd");
    return new;
}

int main()
{
    s_space *n = op();
    printf("%s", n->save);
}