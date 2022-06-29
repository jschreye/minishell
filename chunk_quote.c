/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:10:24 by grubin            #+#    #+#             */
/*   Updated: 2022/06/22 11:24:48 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_if_sq_while(t_data *data, int i)
{
	while (data->str_rl[i])
	{
		if (data->str_rl[i] == '\'')
		{
			i = ft_str_chunck(data, i);
			if (data->str_rl[i] == ' ')
				break ;
			else if (data->str_rl[i] == '|')
				break ;
			else
			{
				while (data->str_rl[i] != ' ' && data->str_rl[i])
					i = ft_str_chunck(data, i);
				if (data->str_rl[i] == ' ')
					break ;
			}
		}
		else
			i = ft_str_chunck(data, i);
	}
	return (i);
}

int	ft_if_dq_while(t_data *data, int i)
{
	while (data->str_rl[i])
	{
		if (data->str_rl[i] == '"')
		{
			i = ft_str_chunck(data, i);
			if (data->str_rl[i] == ' ')
				break ;
			else if (data->str_rl[i] == '|')
				break ;
			else
			{
				while (data->str_rl[i] != ' ' && data->str_rl[i])
					i = ft_str_chunck(data, i);
				if (data->str_rl[i] == ' ')
					break ;
			}
		}
		else
			i = ft_str_chunck(data, i);
	}
	return (i);
}

int	ft_if_sq(t_data *data)
{
	int	i;

	i = 0;
	i = ft_str_chunck(data, i);
	i = ft_if_sq_while(data, i);
	ft_create_chunck(data, i);
	return (0);
}

int	ft_if_dq(t_data *data)
{
	int	i;

	i = 0;
	i = ft_str_chunck(data, i);
	i = ft_if_dq_while(data, i);
	ft_create_chunck(data, i);
	return (0);
}
