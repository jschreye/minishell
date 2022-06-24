/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:29:51 by grubin            #+#    #+#             */
/*   Updated: 2022/06/23 12:57:58 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *ft_getenv(t_data *data, char *str)
{
    char *new_str;
    char *tmp;
    int i;

    i = 0;
    tmp = getenv(str);
    if (tmp == NULL)
    {
        free(tmp);
        return (NULL);
    }
    if (str[0] == '\0')
        return (new_str = ft_strdup(""));
    while (data->envp[i])
    {
        if (ft_strncmp(data->envp[i], str, ft_strlen(str)) == 0)
        {
            new_str = ft_calloc(ft_strlen(data->envp[i]) + ft_strlen(str), sizeof(char));
            new_str = ft_strcpy(new_str, &data->envp[i][ft_strlen(str) + 1]);
            return (new_str);
        }
        i++;
    }
    return (NULL);
}

void ft_print_tab(char **tab)
{
    int i = 0;

    while (tab[i])
    {
        printf("tab = %s\n", tab[i]);
        i++;
    }
}

int ft_init_envp(t_data *data, char **envp)
{
    int i;

    i = 0;
    while (envp[i])
        i++;
    data->envp = ft_calloc(i + 1, sizeof(char*));
    i = 0;
    while (envp[i])
    {
        data->envp[i] = ft_strdup(envp[i]);
        i++;
    }
    data->envp[i] = NULL;
    return (0);
}