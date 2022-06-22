/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:45:51 by grubin            #+#    #+#             */
/*   Updated: 2022/06/21 17:25:00 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_count_redir(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(str[i])
    {
        if (str[i] == '>' || str[i] == '<')
            count++;
        i++;
    }
    if (count > 2)
    {
        printf("Error redirection\n");
        return (return_sig = 1);
    }
    return (return_sig = 0);
}

int ft_check_redir_not_egale(char **tab)
{
    int i;

    i = 0;
    while(tab[i])
    {
        if ((tab[i][0] == '>' && !tab[i + 1])
        || (tab[i][0] == '<' && !tab[i + 1])
        || (tab[i][0] == '<' && !tab[i + 1])
        || (tab[i][0] == '>' && !tab[i + 1]))
        {
            printf("Error redirection 2\n");
            return (return_sig = 1);
        }
        else if ((tab[i][0] == '>' && tab[i + 1][0] == '<')
        || (tab[i][0] == '<' && tab[i + 1][0] == '>')
        || (tab[i][0] == '<' && tab[i + 1][0] == '<' )
        || (tab[i][0] == '>' && tab[i + 1][0] == '>' ))
        {
            printf("Error redirection 2\n");
            return (return_sig = 1);
        }
        i++;
    }
    return (return_sig = 0);
}

int ft_check_error_redir(t_data *data)
{
    int i;
    int j;

    i = 0;
    while(data->tab_chunck[i])
    {
        j = 0;
        while(data->tab_chunck[i][j])
        {
            if (data->tab_chunck[i][j] == '>' || data->tab_chunck[i][j] == '<')
            {
                if (ft_count_redir(data->tab_chunck[i]) == 1)
                    return (1);
                if (ft_check_redir_not_egale(data->tab_chunck) == 1)
                    return (1);
            }
            j++;
        }
        i++;
    }
    return (return_sig = 0);
}