/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:26:03 by grubin            #+#    #+#             */
/*   Updated: 2022/06/24 10:01:13 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	tab = NULL;
}

void	ft_free_cd(t_cd *cd)
{
	free(cd->oldpwd);
	free(cd->path);
	free(cd->pwd);
}

void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	if (data->str_rl)
		free(data->str_rl);
	if (data->str_chunk)
		free(data->str_chunk);
	i = 0;
	while (data->tab_chunck[i])
	{
		free(data->tab_chunck[i]);
		i++;
	}
	free(data->tab_chunck);
	i = 0;
	while (data->tab_cmd[i].args)
	{
		free(data->tab_cmd[i].args);
		i++;
	}
	free(data->tab_cmd);
}
