/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:31:01 by jschreye          #+#    #+#             */
/*   Updated: 2022/06/23 11:09:42 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_check_cat(t_data *data)
{
    int i;
    int j;
    
    j = 0;
    data->c_cat = 0;
    i = 0;
    if (!data->tab_cmd[0].args[0] || data->nbr_cmd == 1)
        return (0);
    while (data->tab_cmd[i].args)
    {
        if (!data->tab_cmd[i + 1].args)
            return (0);
        else if (ft_strncmp(data->tab_cmd[i].args[0], "cat\0", 4) == 0)
            data->c_cat++;
        else if (ft_strncmp(data->tab_cmd[i].args[0], "cat\0", 4) == 1)
            break;
        i++;
    }
    return (0);
}

void ft_return_cat(t_data *data)
{
    int j;
    char *str;
    
    j = 0;
    while (j < data->c_cat)
    {
        str = readline(" ");
        j++;
        free(str);
    }
}