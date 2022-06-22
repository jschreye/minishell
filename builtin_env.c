/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:23:05 by jschreye          #+#    #+#             */
/*   Updated: 2022/06/21 17:29:41 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_env(t_data *data, char **tab)
{
    int i;

    i = 0;
    if (tab[1])
    {    
        printf("env: %s: No such file or directory\n", data->tab_cmd[0].args[1]);
        return (return_sig = 127);
    }
    while (data->envp[i])
    {
        printf("%s\n", data->envp[i]);
        i++;
    }
    return (return_sig = 0);
}