/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:34:32 by grubin            #+#    #+#             */
/*   Updated: 2022/06/24 15:00:28 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_fd(t_fd *files)
{
	if (files->heredocs == 1)
		ft_free_tab(files->tab_in);
	if (files->fd_in != -1)
		close(files->fd_in);
	if (files->fd_out != -1)
		close(files->fd_out);
}

void	ft_pid_one(int pid_1, int fd[2], t_fd *files)
{
	int	j;

	j = 0;
	if (pid_1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		if (files->heredocs == 1 && files->tab_in)
		{
			while (files->tab_in[j])
			{
				printf("%s\n", files->tab_in[j]);
				j++;
			}
		}
		exit(0);
	}
}

void	ft_wait(int pid_1, int pid_2, int fd[2], t_fd *files)
{
	close(fd[0]);
	close(fd[1]);
	close_fd(files);
	waitpid(pid_1, NULL, 0);
	waitpid(pid_2, NULL, 0);
}

int	exec_red(t_data *data, t_fd *files)
{
	int	pid_1;
	int	pid_2;
	int	fd[2];

	pipe(fd);
	pid_1 = fork();
	ft_pid_one(pid_1, fd, files);
	pid_2 = fork();
	if (pid_2 == 0)
	{
		if (files->fd_in != -1 && files->heredocs == 0)
			dup2(files->fd_in, STDIN_FILENO);
		if (files->heredocs == 1)
			dup2(fd[0], STDIN_FILENO);
		if (files->fd_out)
			dup2(files->fd_out, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		ft_execve(data);
	}
	ft_wait(pid_1, pid_2, fd, files);
	return (0);
}
