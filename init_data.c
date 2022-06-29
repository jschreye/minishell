/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:36:26 by grubin            #+#    #+#             */
/*   Updated: 2022/06/28 10:06:12 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_init_struct(t_data *data)
{
	data->nbr_cat = 0;
	data->nbr_cmd = 0;
	data->i_chunk = 0;
	data->str_chunk = NULL;
	data->str_getenv = NULL;
	data->str_rl = NULL;
	data->str_path = NULL;
	data->tab_getenv = NULL;
	data->tab_chunck = NULL;
	data->str_chunk = ft_calloc(2048, sizeof(char));
	data->i_chunk = 0;
	data->tab_cmd = NULL;
	data->tab_cpy = NULL;
	return (0);
}
