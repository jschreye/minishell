/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:23:56 by grubin            #+#    #+#             */
/*   Updated: 2022/06/24 10:25:16 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_fd_in(char **tab, t_fd *files)
{
	int	j;

	j = 0;
	while (tab[j])
	{
		if (tab[j][0] == '<' && tab[j][1] != '<')
		{
			if (!(check_file_in(tab[j + 1], files)))
				return (0);
		}
		if (tab[j][0] == '<' && tab[j][1] == '<')
			check_heredoc(tab[j + 1], files);
		if (tab[j][0] == '>' && tab[j][1] != '>')
		{
			if (!(check_file_out(tab[j + 1], files, 0)))
				return (0);
		}
		if (tab[j][0] == '>' && tab[j][1] == '>')
		{
			if (!(check_file_out(tab[j + 1], files, 1)))
				return (0);
		}
		j++;
	}
	return (1);
}
