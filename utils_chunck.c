/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_chunck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:54:30 by grubin            #+#    #+#             */
/*   Updated: 2022/06/22 15:23:21 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_str_chunck(t_data *data, int i)
{
	data->str_chunk[data->i_chunk] = data->str_rl[i];
	data->i_chunk++;
	i++;
	return (i);
}

void	ft_create_chunck(t_data *data, int i)
{
	char	*tmp;

	tmp = ft_calloc(1024, sizeof(char));
	ft_strcpy(tmp, &data->str_rl[i]);
	ft_bzero(data->str_rl, ft_strlen(data->str_rl));
	ft_strcpy(data->str_rl, tmp);
	free(tmp);
	data->str_chunk = ft_strjoin(data->str_chunk, "\n");
	data->i_chunk++;
}
