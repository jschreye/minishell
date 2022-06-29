/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:21:52 by jschreye          #+#    #+#             */
/*   Updated: 2022/06/24 10:39:56 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **tab)
{
	int	i;

	i = 1;
	if (!tab[i])
		printf("\n");
	else if (ft_strncmp(tab[i], "-n\0", 3) == 0 && !tab[i + 1])
		return (0);
	else if (ft_strncmp(tab[i], "-n\0", 3) == 0 && tab[i + 1])
	{
		while (tab[++i])
		{
			printf("%s", tab[i]);
			if (tab[i + 1])
				printf(" ");
		}
	}
	else
	{
		i = i - 1;
		while (tab[++i])
			printf("%s ", tab[i]);
		printf("\n");
	}
	return (g_return_sig = 0);
}
