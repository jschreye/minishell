/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:05:17 by grubin            #+#    #+#             */
/*   Updated: 2022/06/28 09:53:53 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_child(t_data *data, int (*fd)[2], int i, t_fd *files)
{
	if (i > 0)
		dup2(fd[i - 1][0], STDIN_FILENO);
	if (i < data->nbr_cmd - 1)
		dup2(fd[i][1], STDOUT_FILENO);
	close_pipes(data->nbr_cmd - 1, fd);
	if (files->red == 1 && files->tab_in != NULL)
		exec_red(data, files);
	else if (files->red == 0)
		ft_execve(data);
	return (0);
}

int	ft_pipe(t_data *data, t_fd *files)
{
	int	i;

	i = -1;
	while (++i < data->nbr_cmd - 1)
		pipe(files->fd[i]);
	i = -1;
	while (++i <= data->nbr_cmd - 1)
	{
		if (data->tab_cpy)
			ft_free_tab(data->tab_cpy);
		ft_init_fd(data, files, i);
		files->pid[i] = fork();
		if (files->pid[i] == 0)
		{
			ft_exec_child(data, files->fd, i, files);
			close_pipes(data->nbr_cmd - 1, files->fd);
			exit(0);
		}
	}
	close_pipes(data->nbr_cmd - 1, files->fd);
	ft_wait_pid(data, files);
	return (0);
}

int	ft_check_redir(t_data *data)
{
	int	i_arg;

	i_arg = 0;
	while (data->tab_cmd[0].args[i_arg])
	{
		if (ft_strncmp(data->tab_cmd[0].args[i_arg], ">\0", 2) == 0
			|| ft_strncmp(data->tab_cmd[0].args[i_arg], "<\0", 2) == 0
			|| ft_strncmp(data->tab_cmd[0].args[i_arg], ">>\0", 3) == 0
			|| ft_strncmp(data->tab_cmd[0].args[i_arg], "<<\0", 3) == 0)
			return (1);
		i_arg++;
	}
	return (0);
}

int	ft_check_pipe_error(char **tab)
{
	int		count;
	char	*tmp;

	tmp = "|\0";
	count = 0;
	while (tab[count])
		count++;
	if (ft_strncmp(tab[0], tmp, 2) == 0
		|| ft_strncmp(tab[count - 1], tmp, 2) == 0)
		return (1);
	return (0);
}

int	ft_exec_cmds(t_data *data)
{
	t_fd	files;

	if (ft_check_error_redir(data) == 1)
		return (1);
	if (data->nbr_cmd > 1
		&& ft_check_pipe_error(data->tab_chunck) == 1)
	{
		printf("$: syntax error near unexpected token `|'\n");
		return (0);
	}
	if (data->nbr_cmd == 1 && ft_check_redir(data) == 1)
	{
		ft_init_fd(data, &files, 0);
		if (files.value == 0)
			exec_red(data, &files);
	}
	else if (data->nbr_cmd == 1 && ft_check_redir(data) == 0)
		ft_builtins_without_pipe(data, &files);
	else
		ft_pipe(data, &files);
	ft_free_tab(data->tab_cpy);
	return (0);
}
