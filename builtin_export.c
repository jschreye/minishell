/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:35:46 by grubin            #+#    #+#             */
/*   Updated: 2022/06/23 15:32:55 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_realloc_envp(t_data *data, t_export *export)
{
	int	i;

	i = 0;
	while (export->tab[i])
		i++;
	data->envp = ft_calloc(i + 2, sizeof(char *));
	i = 0;
	while (export->tab[i])
	{
		data->envp[i] = ft_strdup(export->tab[i]);
		i++;
	}
	data->envp[i + 1] = NULL;
	ft_free_tab(export->tab);
	return (0);
}

int	ft_creat_new_env(t_export *export, t_data *data, int i_arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_init_struct_export(export, data);
	while (data->envp[i])
	{
		if (data->envp[i][0] != '=')
		{
			export->tab[j] = ft_strdup(data->envp[i]);
			j++;
			i++;
		}
		else
			i++;
	}
	if (data->tab_cmd[0].args[i_arg][0] != '=')
		export->tab[i] = ft_strdup(data->tab_cmd[0].args[i_arg]);
	ft_free_tab(data->envp);
	ft_realloc_envp(data, export);
	return (0);
}

int	ft_count_egale(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=')
	{
		i++;
	}
	return (i + 1);
}

int	ft_similar(t_data *data, int i_arg)
{
	int	i;

	i = 0;
	while (data->envp[i])
	{
		if (ft_strncmp(data->tab_cmd[0].args[i_arg], data->envp[i],
				ft_count_egale(data->envp[i])) == 0)
		{
			data->envp[i] = ft_realloc(data->envp[i],
					ft_strlen(data->tab_cmd[0].args[i_arg]) + 1);
			ft_bzero(data->envp[i], ft_strlen(data->envp[i]));
			ft_strcpy(data->envp[i], data->tab_cmd[0].args[i_arg]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_export(t_data *data)
{
	t_export	export;

	export.tab = NULL;
	ft_error_export(data);
	if (ft_count_args(data, 0) == 1)
	{
		ft_init_struct_export(&export, data);
		ft_tri_env(data, &export);
		ft_print_tab_export(&export);
	}
	else if (ft_count_args(data, 0) > 1)
		ft_export_new_env(&export, data);
	return (g_return_sig = 0);
}
