/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:39:08 by grubin            #+#    #+#             */
/*   Updated: 2022/05/18 15:46:15 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_init_var(t_var *var, char **str, char **result)
{
    var->i = 0;
    var->i_res = 0;
    var->i_tok = 0;
    var->count = 0;
    if ((*result) == NULL)
        (*result) = ft_strdup("");
    var->token_tmp = ft_calloc(ft_strlen(*str) + ft_strlen(*result), sizeof(char));
}

int ft_include_env(char **str, char **result, int size_env)//il y a un leaks  quelque part
{
    t_var var;
    
    ft_init_var(&var, str, result);
    while ((*str)[var.i])
    {
        if ((*str)[var.i] == '$' && var.count < 1)
        {
            var.count++;
            while((*result)[var.i_res])
            {
                var.token_tmp[var.i_tok] = (*result)[var.i_res];
                var.i_tok++;
                var.i_res++;
            }
            var.i = var.i + (size_env + 1);
        }
        var.token_tmp[var.i_tok] = (*str)[var.i];
        var.i_tok++;
        var.i++;
    }
    *str = var.token_tmp;// str pas free
    return (var.i_res);
}

int ft_check_env(char **str, int i)//il y a un leaks  quelque part
{
    int     i_env;
    char    *env_tmp;
    char    *result;
    i_env = 0;
    env_tmp = ft_calloc(ft_strlen(*str), sizeof(char));//free
    i++;
    while ((*str)[i])
    {
        if ((*str)[i] == '"' || (*str)[i] == ' ' || (*str)[i] == '$')
            break ;
        env_tmp[i_env] = (*str)[i];
        i++;
        i_env++;
    }
    result = getenv(env_tmp);
    i = ft_include_env(str, &result, ft_strlen(env_tmp));
    free(env_tmp);
    return (i);
}

int ft_check_str_with_dollar(char **str)
{
    int i;
    
    i = 0;
    while ((*str)[i])
    {
        if ((*str)[i] == '"' && (*str)[i + 1] != '\0')
        {    
            i++;
            while ((*str)[i])
            {
                if ((*str)[i] == '$' && (*str)[i + 1] != ' ')
                    i = ft_check_env(str, i);
                else
                    i++;
            } 
        }
        else if ((*str)[i] == '$' && (*str)[i + 1] == '\'')
            ft_memmove(*str, *str + 1, ft_strlen(*str));
        else if ((*str)[i] == '$')
            i = ft_check_env(str, i);
        else
            i++;
    }
    return (0);
}

int ft_check_dollar(char **str)
{
    int i;

    i = 0;
    while ((*str)[i])
    {
        if ((*str)[i] == '$')
        {
            ft_check_str_with_dollar(str);
            break ;
        }
        i++;
    }
    return (0);
}

int ft_dollar(t_cmd *tab)
{
    int i_cmd;
    int i_arg;
    
    i_cmd = 0;
    while (tab[i_cmd].args)
    {
        i_arg = 0;
        while (tab[i_cmd].args[i_arg])
        {
            ft_check_dollar(&tab[i_cmd].args[i_arg]);
            i_arg++;
        }
        i_cmd++;
    }
    return (0);
}