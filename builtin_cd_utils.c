/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:48:39 by grubin            #+#    #+#             */
/*   Updated: 2022/06/22 15:31:41 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_count_args(t_data *data, int i_cmd)
{
	int	i_args;
	int	count;

	i_args = 0;
	count = 0;
	while (data->tab_cmd[i_cmd].args[i_args])
	{
		i_args++;
		count++;
	}
	return (count);
}

int	ft_chdir(t_cd *cd, t_data *data, int i_cmd)
{
	int	res;

	res = chdir(cd->path);
	if (res == 0)
		ft_change_envp(cd, data);
	else
	{
		printf("cd: no such file or directory: %s\n",
			data->tab_cmd[i_cmd].args[1]);
		ft_free_cd(cd);
	}
	return (g_return_sig = 0);
}

int	ft_count_double_point(t_cd *cd, t_data *data)
{
	int		i;
	char	**tab;

	i = 0;
	cd->tab = NULL;
	cd->count_point = 0;
	cd->count_slash = 0;
	tab = ft_split(data->tab_cmd[0].args[1], '/');
	while (tab[i])
	{
		if (strncmp(tab[i], "..\0", 3) == 0)
		cd->count_point++;
		i++;
	}
	ft_free_tab(tab);
	i = 0;
	while (cd->pwd[i])
	{
		if (cd->pwd[i] == '/')
			cd->count_slash++;
		i++;
	}
	return (g_return_sig = 0);
}

int	ft_split_slash(t_cd *cd)
{
	if (cd->count_point < cd->count_slash)
		cd->tab = ft_split(cd->pwd, '/');
	else
	{
		cd->path = ft_strcpy(cd->path, "/");
		return (0);
	}
	return (g_return_sig = 0);
}

int	ft_go_up_the_path(t_cd *cd, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_count_double_point(cd, data);
	ft_split_slash(cd);
	while (cd->tab[i])
		i++;
	cd->path = ft_strjoin(cd->path, "/");
	while (i - cd->count_point != 0)
	{
		cd->path = ft_strjoin(cd->path, cd->tab[j]);
		if (i - cd->count_point != 1)
			cd->path = ft_strjoin(cd->path, "/");
		i--;
		j++;
	}
	ft_free_tab(cd->tab);
	return (g_return_sig = 0);
}
