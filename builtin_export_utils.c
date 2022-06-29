/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:39:54 by grubin            #+#    #+#             */
/*   Updated: 2022/06/22 15:31:41 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_init_struct_export(t_export *export, t_data *data)
{
	int	i;

	i = 0;
	while (data->envp[i])
		i++;
	export->tab = ft_calloc(i + ft_count_args(data, 0) + 1, sizeof(char *));
	export->tab[i + 1] = NULL;
	return (0);
}

void	ft_print_tab_export(t_export *export)
{
	int	i;

	i = 0;
	while (export->tab[i])
	{
		printf("declare -x %s\n", export->tab[i]);
		i++;
	}
	ft_free_tab(export->tab);
}

int	ft_error_export(t_data *data)
{
	int	i;

	i = 0;
	while (data->tab_cmd[0].args[i])
	{
		if (data->tab_cmd[0].args[i][0] == '=')
			printf("export: `%s': not a valide identifier\n",
				data->tab_cmd[0].args[i]);
		i++;
	}
	return (g_return_sig = 1);
}

void	ft_tri_env(t_data *data, t_export *export)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	export->val_min = 32;
	while (export->val_min < 127)
	{
		i = 0;
		while (data->envp[i])
		{
			if ((int)data->envp[i][0] == export->val_min)
			{
				export->tab[j] = ft_strdup(data->envp[i]);
				j++;
			}
			i++;
		}
		export->val_min++;
	}
}

int	ft_export_new_env(t_export *export, t_data *data)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (data->tab_cmd[0].args[i])
	{
		j = 0;
		while (data->tab_cmd[0].args[i][j])
		{
			if (data->tab_cmd[0].args[i][j] == '=' && ft_similar(data, i) == 0)
				ft_creat_new_env(export, data, i);
			j++;
		}
		i++;
	}
	return (0);
}
