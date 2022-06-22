/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:54:59 by jschreye          #+#    #+#             */
/*   Updated: 2022/06/21 17:38:28 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_egal(char *str)
{
    int i;

    i = 0;
    while (str[i] != '=')
        i++;
    return (i + 1);
}

int ft_envcmp(t_data *data, int i_cmd)
{
    char *tmp;
    int i;

    i = 0;
    tmp = ft_calloc(1024, sizeof(char));
    while (data->envp[i])
    {
        ft_strcpy(tmp, &data->envp[i][ft_egal(data->envp[i])]);
        if (ft_strncmp(data->tab_cmd[i_cmd].args[0], tmp, ft_strlen(data->tab_cmd[i_cmd].args[0])) == 0)
        {
            free(tmp);
            return (0);
        }
        else
            ft_bzero(tmp, ft_strlen(tmp));
        i++;
    }
    free(tmp);
    return (1);
}

void ft_lol(t_data *data, int i_cmd, int i_arg, int i)
{
    while (data->tab_cmd[i_cmd].args[i_arg])
    {
        if ((ft_strncmp(data->tab_cmd[i_cmd].args[i_arg], ">\0", 2) == 0
            && data->tab_cmd[i_cmd].args[i_arg + 1])
            ||(ft_strncmp(data->tab_cmd[i_cmd].args[i_arg], "<\0", 2) == 0
            && data->tab_cmd[i_cmd].args[i_arg + 1]) 
            || (ft_strncmp(data->tab_cmd[i_cmd].args[i_arg], ">>\0", 3) == 0
            && data->tab_cmd[i_cmd].args[i_arg + 1])
            ||(ft_strncmp(data->tab_cmd[i_cmd].args[i_arg], "<<\0", 3) == 0
            && data->tab_cmd[i_cmd].args[i_arg + 1]) )
            i_arg += 2;
        else if (ft_strncmp(data->tab_cmd[i_cmd].args[i_arg], ">\0", 2) == 0
            || ft_strncmp(data->tab_cmd[i_cmd].args[i_arg], "<\0", 2) == 0
            || ft_strncmp(data->tab_cmd[i_cmd].args[i_arg], ">>\0", 2) == 0
            || ft_strncmp(data->tab_cmd[i_cmd].args[i_arg], "<<\0", 2) == 0)
            i_arg++;
        else
        {
            data->tab_cpy[i] = ft_strdup(data->tab_cmd[i_cmd].args[i_arg]);
            i++;
            i_arg++;
        }
    }
    data->tab_cpy[i] = NULL;
}

void ft_tabcpy(t_data *data, int i_cmd, int i_arg)
{
    int len;
    int i;

    i = 0;
    len = ft_count_args(data, i_cmd);
    data->tab_cpy = ft_calloc(len + 1, sizeof(char*));
    ft_lol(data, i_cmd, i_arg, i);
}

int ft_builtins_with_pipe(t_data *data, int i)
{ 
    if (data->tab_cpy[0] == NULL)
        return (0);
    if (ft_strncmp(data->tab_cpy[0], "echo\0", 5) == 0)
        ft_echo(data->tab_cpy);
    else if (ft_strncmp(data->tab_cpy[0], "cd\0", 3) == 0)
        ft_cd(data, 0);
    else if (ft_strncmp(data->tab_cpy[0], "pwd\0", 4) == 0)
        ft_pwd(data);
    else if (ft_strncmp(data->tab_cpy[0], "export\0", 7) == 0)
        ft_export(data);
    else if (ft_strncmp(data->tab_cpy[0], "unset\0", 6) == 0)
        ft_unset(data);
    else if (ft_strncmp(data->tab_cpy[0], "env\0", 4) == 0)
        ft_env(data, data->tab_cpy);
    else if (ft_envcmp(data, i) == 0 && ft_count_args(data, i) == 1)
        printf("%s\n", data->tab_cpy[0]);
    else
        return (return_sig = 0);
    exit(0);
}

int ft_builtins_without_pipe(t_data *data)
{
    if (ft_del_quote(data->tab_cmd[0].args) == 1)
        return (0);
    if (data->tab_cmd[0].args[0] == NULL)
        return (0);
    if (ft_strncmp(data->tab_cmd[0].args[0], "exit\0", 5) == 0)
        ft_exit(data, 0);
    else if (ft_strncmp(data->tab_cmd[0].args[0], "echo\0", 5) == 0)
        ft_echo(data->tab_cmd[0].args);
    else if (ft_strncmp(data->tab_cmd[0].args[0], "cd\0", 3) == 0)
        ft_cd(data, 0);
    else if (ft_strncmp(data->tab_cmd[0].args[0], "pwd\0", 4) == 0)
       ft_pwd(data);
    else if (ft_strncmp(data->tab_cmd[0].args[0], "export\0", 7) == 0)
        ft_export(data);
    else if (ft_strncmp(data->tab_cmd[0].args[0], "unset\0", 6) == 0)
        ft_unset(data);
    else if (ft_strncmp(data->tab_cmd[0].args[0], "env\0", 4) == 0)
        ft_env(data, data->tab_cmd[0].args);
    else if (ft_envcmp(data, 0) == 0 && ft_count_args(data, 0) == 1)
         printf("%s\n", data->tab_cmd[0].args[0]);
    else
        ft_pipe(data);
    return (0);
}