/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:27:26 by grubin            #+#    #+#             */
/*   Updated: 2022/06/24 15:03:31 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_red(t_fd *files)
{
	files->value = 0;
	files->append = 0;
	files->fd_in = -1;
	files->fd_out = -1;
	files->heredocs = 0;
	files->red = 0;
	files->tab_in = NULL;
}

char	*copy_new_line(char *new_line)
{
	char	*stock;
	int		i;

	i = 0;
	stock = malloc(sizeof(char) * ft_strlen(new_line) + 1);
	while (new_line[i] != '\0')
	{
		stock[i] = new_line[i];
		i++;
	}
	stock[i] = '\0';
	return (stock);
}

void	close_pipes(int nb_pipe, int (*fd)[2])
{
	int	j;

	j = 0;
	while (j < nb_pipe)
	{
		close(fd[j][0]);
		close(fd[j][1]);
		j++;
	}
}

int	error_red(char **cmd, t_fd *files, int i_cmd)
{
	while (cmd[i_cmd])
	{
		if (cmd[i_cmd][0] == '<' || cmd[i_cmd][0] == '>')
		{
			files->red = 1;
		}
		i_cmd++;
	}
	return (1);
}
