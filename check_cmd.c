/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:59:47 by grubin            #+#    #+#             */
/*   Updated: 2022/06/28 10:43:33 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_err(t_data *data, t_err *err)
{
	err->i = 0;
	err->k = 0;
	err->cmd = NULL;
	err->cmd_path = NULL;
	data->str_getenv = ft_getenv(data, "PATH");
	data->tab_getenv = ft_split(data->str_getenv, ':');
	free(data->str_getenv);
}

int	ft_error_exception(t_data *data, t_err *err)
{
	if (ft_strncmp(data->tab_cmd[err->i].args[0], "exit\0", 5) == 0
		|| ft_strncmp(data->tab_cmd[err->i].args[0], "unset\0", 6) == 0
		|| ft_strncmp(data->tab_cmd[err->i].args[0], "export\0", 6) == 0
		|| access(data->tab_cmd[0].args[0], X_OK) == 0
		|| ft_strncmp(data->tab_cmd[err->i].args[0], "<\0", 2) == 0
		|| ft_strncmp(data->tab_cmd[err->i].args[0], ">\0", 2) == 0
		|| ft_strncmp(data->tab_cmd[err->i].args[0], "<<\0", 3) == 0
		|| ft_strncmp(data->tab_cmd[err->i].args[0], ">>\0", 3) == 0
		|| ft_strncmp(data->tab_cmd[err->i].args[0], "./a.out\0", 6) == 0)
		return (1);
	return (0);
}

int	ft_check_valid_command(t_data *data, t_err *err)
{
	ft_init_err(data, err);
	while (data->tab_cmd[err->i].args)
	{
		err->j = 0;
		while (data->tab_getenv[err->j])
		{
			err->cmd_path = ft_join(data->tab_getenv[err->j], "/");
			err->cmd = ft_join(err->cmd_path, data->tab_cmd[err->i].args[0]);
			free(err->cmd_path);
			err->k = access(err->cmd, X_OK);
			free(err->cmd);
			if (err->k != -1)
				break ;
			err->j++;
		}
		if (err->k == -1 && data->tab_cmd[err->i].args[0] != NULL
			&& ft_error_exception(data, err) == 0)
		{
			printf("$: %s: command not found\n", data->tab_cmd[err->i].args[0]);
			g_return_sig = 1;
		}
		err->i++;
	}
	ft_free_tab(data->tab_getenv);
	return (g_return_sig = 0);
}
