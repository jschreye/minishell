/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunck_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:37:00 by grubin            #+#    #+#             */
/*   Updated: 2022/06/22 11:19:19 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_if_pipe(t_data *data)
{
	int	i;

	i = 0;
	i = ft_str_chunck(data, i);
	ft_create_chunck(data, i);
	return (0);
}

int	ft_if_spacestr(t_data *data, int i)
{
	while (data->str_rl[i] == ' ')
		i = ft_str_chunck(data, i);
	return (i);
}

int	ft_if_chevron(t_data *data)
{
	int	i;

	i = 0;
	i = ft_str_chunck(data, i);
	while (data->str_rl[i])
	{
		if (data->str_rl[i] != data->str_rl[i - 1])
			break ;
		else
			i = ft_str_chunck(data, i);
	}
	ft_create_chunck(data, i);
	return (0);
}

int	ft_if_space(t_data *data)
{
	int	i;

	i = 0;
	while (data->str_rl[i] == ' ')
		i++;
	ft_memmove(data->str_rl, data->str_rl + i, ft_strlen(data->str_rl));
	return (0);
}
