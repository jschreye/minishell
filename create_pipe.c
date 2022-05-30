/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:05:17 by grubin            #+#    #+#             */
/*   Updated: 2022/05/24 13:44:17 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_free_pipe(int **pipe, int size)
{
    if (pipe && size)
    {
        while (size--)
            free(pipe[size]);
        free(pipe);
    }
}

void ft_close_pipe(t_data *data)
{
    int i;

    i = data->nbr_pipe;
    while (i)
    {
        if (close(data->pipe[i][0]) != 0 || close(data->pipe[i][1]) != 0)
            perror("Error: pipe close() failed");
        i--;
    }
    ft_free_pipe(data->pipe, data->nbr_pipe);
}

int ft_create_pipe(t_data *data)
{
    int i;

    i = 0;
    data->nbr_pipe = data->size_cmd - 1;
    data->pipe = (int **)ft_calloc(sizeof(int *), data->nbr_pipe);
    if (!data->pipe)
        return (0);
    while (i < data->nbr_pipe)
    {
        data->pipe[i] = (int *)ft_calloc(sizeof(int), 2);
        if (pipe(data->pipe[i]) != 0)
        {
            perror("Error: pipe() failed");
            return (0);
        }
        i++;
    }
    return (1);
}