/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:22:22 by jschreye          #+#    #+#             */
/*   Updated: 2022/06/23 15:32:51 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_args_exit(char **tab)
{
	int	i;

	i = 0;
	while (tab[1][i])
	{
		if (ft_isdigit((int)tab[1][i]) == 0)
		{
			printf("$: exit: %s: numeric argument required\n", tab[1]);
			exit(255);
		}
		i++;
	}
	exit (ft_atoi(tab[1]));
}

int	ft_exit(t_data *data, int i_cmd)
{
	if (ft_count_args(data, i_cmd) > 2)
	{
		printf("exit: too many arguments\n");
		return (g_return_sig = 1);
	}
	else if (ft_count_args(data, i_cmd) == 2)
	{
		ft_check_args_exit(data->tab_cmd[i_cmd].args);
	}
	else
	{
		exit(0);
	}
	return (g_return_sig = 1);
}
