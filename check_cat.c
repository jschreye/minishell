/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:31:01 by jschreye          #+#    #+#             */
/*   Updated: 2022/06/22 14:37:38 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_check_cat(t_data *data)
{
    int i;
    int j;
    int count;
    char *str;
    
    j = 0;
    count = 0;
    i = 0;
    if (!data->tab_cmd[0].args[0] || data->nbr_cmd == 1)
        return (0);
    while (data->tab_cmd[i].args)
    {
        if (ft_strncmp(data->tab_cmd[i].args[0], "cat\0", 4) == 0)
            count++;
        else if (ft_strncmp(data->tab_cmd[i].args[0], "cat\0", 4) == 1)
            break;
        i++;
    }
    while (j < count)
    {
        str = readline(" ");
        j++;
        count--;
        free(str);
    }
    return (0);
}