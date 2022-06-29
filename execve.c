/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:39:13 by jschreye          #+#    #+#             */
/*   Updated: 2022/06/28 10:36:55 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execve(t_data *data)
{
	int		i;
	char	*cmd;
	char	*cmd_path;

	if (ft_del_quote(data->tab_cpy) == 1)
		return (0);
	if (access(data->tab_cpy[0], X_OK) == 0)
		execve(data->tab_cpy[0], data->tab_cpy, data->envp);
	ft_builtins_with_pipe(data, 0);
	data->str_getenv = ft_getenv(data, "PATH");
	data->tab_getenv = ft_split(data->str_getenv, ':');
	i = 0;
	while (data->tab_getenv[i])
	{
		cmd_path = ft_join(data->tab_getenv[i], "/");
		cmd = ft_join(cmd_path, data->tab_cpy[0]);
		free(cmd_path);
		if (access(cmd, X_OK) == 0)
			execve(cmd, data->tab_cpy, data->envp);
		free(cmd);
		i++;
	}
	exit(127);
}
