/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:10:33 by jschreye          #+#    #+#             */
/*   Updated: 2022/06/22 14:13:48 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_init_err(t_data *data, t_err *err)
{
    err->i = 0;
    err->k = 0;
    err->cmd = NULL;
    err->cmd_path = NULL;
    data->str_getenv = ft_getenv(data, "PATH");
    data->tab_getenv = ft_split(data->str_getenv, ':');
    free(data->str_getenv);
}

int ft_check_valid_command(t_data *data, t_err *err)
{
    ft_init_err(data, err);
    while(data->tab_cmd[err->i].args)
    {
        err->j = 0;
        while(data->tab_getenv[err->j])
        {
            err->cmd_path = ft_join(data->tab_getenv[err->j], "/");
            err->cmd = ft_join(err->cmd_path, data->tab_cmd[err->i].args[0]);
            free(err->cmd_path);
            err->k = access(err->cmd, X_OK);
            free(err->cmd);
            if (err->k != - 1)
                break;
            err->j++;
        }
        if (err->k == -1 && data->tab_cmd[err->i].args[0] != NULL)
        {
            printf("$: %s: command not found\n", data->tab_cmd[err->i].args[0]);
            return_sig = 1;
        }
        err->i++;
    }
    ft_free_tab(data->tab_getenv);
    return (return_sig = 0);
}