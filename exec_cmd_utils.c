/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:31:59 by grubin            #+#    #+#             */
/*   Updated: 2022/06/28 09:31:23 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_wait_pid(t_data *data, t_fd *files)
{
	int	i;

	i = 0;
	while (i < data->nbr_cmd)
	{
		ft_check_if_child(files->pid[i]);
		waitpid(files->pid[i], &files->status, 0);
		if (WIFEXITED(files->status))
			g_return_sig = WEXITSTATUS(files->status);
		i++;
	}
	ft_check_if_child(0);
	return (0);
}

int	ft_init_fd(t_data *data, t_fd *files, int i)
{
	ft_init_red(files);
	error_red(data->tab_cmd[i].args, files, i);
	ft_check_fd_in(data->tab_cmd[i].args, files);
	ft_tabcpy(data, i, 0);
	return (0);
}

void	ft_lol(t_data *data, int i_cmd, int i_arg, int i)
{
	while (data->tab_cmd[i_cmd].args[i_arg])
	{
		if ((ft_strncmp(data->tab_cmd[i_cmd].args[i_arg], ">\0", 2) == 0
				&& data->tab_cmd[i_cmd].args[i_arg + 1])
			|| (ft_strncmp(data->tab_cmd[i_cmd].args[i_arg], "<\0", 2) == 0
				&& data->tab_cmd[i_cmd].args[i_arg + 1])
			|| (ft_strncmp(data->tab_cmd[i_cmd].args[i_arg], ">>\0", 3) == 0
				&& data->tab_cmd[i_cmd].args[i_arg + 1])
			|| (ft_strncmp(data->tab_cmd[i_cmd].args[i_arg], "<<\0", 3) == 0
				&& data->tab_cmd[i_cmd].args[i_arg + 1]))
			i_arg += 2;
		else if (ft_strncmp(data->tab_cmd[i_cmd].args[i_arg], ">\0", 2) == 0
			|| ft_strncmp(data->tab_cmd[i_cmd].args[i_arg], "<\0", 2) == 0
			|| ft_strncmp(data->tab_cmd[i_cmd].args[i_arg], ">>\0", 2) == 0
			|| ft_strncmp(data->tab_cmd[i_cmd].args[i_arg], "<<\0", 2) == 0)
			i_arg++;
		else
		{
			data->tab_cpy[i] = ft_strdup(data->tab_cmd[i_cmd].args[i_arg]);
			i++;
			i_arg++;
		}
	}
	data->tab_cpy[i] = NULL;
}

void	ft_tabcpy(t_data *data, int i_cmd, int i_arg)
{
	int	len;
	int	i;

	i = 0;
	len = ft_count_args(data, i_cmd);
	data->tab_cpy = ft_calloc(len + 1, sizeof(char *));
	ft_lol(data, i_cmd, i_arg, i);
}
