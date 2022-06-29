/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunck.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:16:04 by grubin            #+#    #+#             */
/*   Updated: 2022/06/22 11:17:05 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_if_charact_while(t_data *data, int i)
{
	while (data->str_rl[i])
	{
		if (data->str_rl[i] == '\'')
		{
			i = ft_str_chunck(data, i);
			while (data->str_rl[i] != '\'' && data->str_rl[i] != '\0')
				i = ft_str_chunck(data, i);
		}
		if (data->str_rl[i] == '"')
		{
			i = ft_str_chunck(data, i);
			while (data->str_rl[i] != '"' && data->str_rl[i] != '\0')
				i = ft_str_chunck(data, i);
		}
		if (data->str_rl[i] == '|' || data->str_rl[i] == '<'
			|| data->str_rl[i] == '>' || data->str_rl[i] == ' ')
			break ;
		else
			i = ft_str_chunck(data, i);
	}
	return (i);
}

int	ft_if_charact(t_data *data)
{
	int	i;

	i = 0;
	i = ft_if_charact_while(data, i);
	ft_create_chunck(data, i);
	return (0);
}

int	ft_create_str_chunck(t_data *data)
{
	int	i;

	i = 0;
	while (data->str_rl[i])
	{
		if (data->str_rl[i] == '\'')
			ft_if_sq(data);
		else if (data->str_rl[i] == '"')
			ft_if_dq(data);
		else if (data->str_rl[i] == '|')
			ft_if_pipe(data);
		else if (data->str_rl[i] == '<' || data->str_rl[i] == '>')
			ft_if_chevron(data);
		else if (data->str_rl[i] == ' ')
			ft_if_space(data);
		else if (data->str_rl[i])
			ft_if_charact(data);
		else
			i++;
		i = 0;
	}
	return (0);
}
