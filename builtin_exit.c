/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:22:22 by jschreye          #+#    #+#             */
/*   Updated: 2022/06/21 17:28:24 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_check_args_exit(char **tab)
{
    int i;

    i = 0;
    while (tab[1][i])
    {
        if (ft_isdigit((int)tab[1][i]) == 0)
        {
            printf("$: exit: %s: numeric argument required\n", tab[1]);
            exit(255);
        }
        i++;
    }
    exit (ft_atoi(tab[1]));
}

int ft_exit(t_data *data, int i_cmd)
{
    if (ft_count_args(data, i_cmd) > 2)
    {
        printf("exit: too many arguments\n");
        return (return_sig = 1);
    }
    else if (ft_count_args(data, i_cmd) == 2)
    {
        ft_check_args_exit(data->tab_cmd[i_cmd].args);
    }
    else
    {
        exit(0);
    }
    return (return_sig = 1);
}
/*
int ft_exit_prog(t_data *data)
{
    int i_cmd;

    i_cmd = 0;
    
    return (0);
}

*/
 /*   if (!data->tab_cmd[0].args[0])
        return (0);
    while(data->tab_cmd[i_cmd].args)
    {
        if (ft_strncmp(data->tab_cmd[0].args[0], "exit\0", 5) == 0)
        {
            if (ft_exit(data, i_cmd) == 1)
                return (1);    
        }
        else if (ft_strncmp(data->tab_cmd[data->nbr_cmd - 1].args[0],
            "exit\0", 5) == 0)
        {
            i_cmd = data->nbr_cmd - 1;
            if (ft_exit(data, i_cmd) == 1)
                return (1);    
        }
        else
            i_cmd++;
    }*/