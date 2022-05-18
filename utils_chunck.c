/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_chunck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:54:30 by grubin            #+#    #+#             */
/*   Updated: 2022/05/02 11:57:12 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_str_chunck(t_data *data, int i)
{
    data->str_chunk[data->i_chunk] = data->str_rl[i];
    data->i_chunk++;
    i++;
    return (i);
}

void ft_create_chunck(t_data *data, int i)
{
    ft_memmove(data->str_rl, data->str_rl + i , ft_strlen(data->str_rl));
    data->str_chunk = ft_strjoin(data->str_chunk, "\n");
    data->i_chunk++;
}