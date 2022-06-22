/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:22:41 by grubin            #+#    #+#             */
/*   Updated: 2022/06/22 14:46:07 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_file_in(char *file_name, t_fd *files)
{
    if (files->fd_in != -1)
        close(files->fd_in);
    files->fd_in = open(file_name, O_RDONLY);
    if (files->fd_in == -1)
    {
        printf("$ %s: no such file or directory\n", file_name);
        return (0);
    }
    if (files->heredocs == 1)
    {
        ft_free_tab(files->tab_in);
        files->heredocs = 0;
    }
    return (1);
}

char **cpy_tab_heredocs(char **tab, int nb_lines, char *input)
{
    char **copied_tab;
    int j;

    j = 0;
    copied_tab = malloc(sizeof(char *) * (nb_lines + 1));
    while (tab[j])
    {
        copied_tab[j] = copy_new_line(tab[j]);
        j++;
    }
    if (input)
    {
        copied_tab[j] = copy_new_line(input);
        copied_tab[j + 1] = 0; 
    }
    else
        copied_tab[j] = 0;
    return(copied_tab);
}

void    check_heredoc(char *key_word, t_fd *files)
{
    char *input;
    int nb_lines;
    char    **tmp;
    static int  freed = 1;
    
    nb_lines = 1;
    if (files->heredocs == 1)
        ft_free_tab(files->tab_in);
    input = readline("> ");
    if(input[0] == '\0')
    {
        free(input);
        input = ft_strdup(" \0");
    }
    while ((ft_strncmp(input, key_word, ft_strlen(input)) != 0))
    {
        if (freed == 1)
        {
            files->tab_in = malloc(sizeof(char *) * 2);
            files->tab_in[0] = copy_new_line(input);
            free(input);
            files->tab_in[1] = 0;
            freed = 0;
        }
        else
        {
            tmp = cpy_tab_heredocs(files->tab_in, nb_lines, input);
            ft_free_tab(files->tab_in);
            free(input);
            files->tab_in = cpy_tab_heredocs(tmp, nb_lines, NULL);
            ft_free_tab(tmp);
        }
        input = readline("> ");
        if(input[0] == '\0')
        {
            free(input);
            input = ft_strdup(" \0");
        }
        nb_lines++;
    }
    free(input);
    freed = 1;
    files->heredocs = 1;
}