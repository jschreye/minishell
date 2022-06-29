/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:29:51 by grubin            #+#    #+#             */
/*   Updated: 2022/06/22 15:06:56 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(t_data *data, char *str)
{
	char	*new_str;
	char	*tmp;
	int		i;

	i = 0;
	tmp = getenv(str);
	if (tmp == NULL)
	{
		free(tmp);
		return (NULL);
	}
	if (str[0] == '\0')
		return (new_str = ft_strdup(""));
	while (data->envp[i])
	{
		if (ft_strncmp(data->envp[i], str, ft_strlen(str)) == 0)
		{
			new_str = ft_calloc(ft_strlen(data->envp[i]) + ft_strlen(str),
					sizeof(char));
			new_str = ft_strcpy(new_str, &data->envp[i][ft_strlen(str) + 1]);
			return (new_str);
		}
		i++;
	}
	return (NULL);
}

void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("tab = %s\n", tab[i]);
		i++;
	}
}

int	ft_check_cat(t_data *data)
{
	int		i;
	char	*str;

	i = data->nbr_cmd;
	if (!data->tab_cmd[0].args[0] || data->nbr_cmd == 1)
		return (0);
	while (i > 0)
	{
		if (ft_strncmp(data->tab_cmd[i - 1].args[0], "cat\0", 4) == 0)
		{
			str = readline("");
			free(str);
			i--;
		}
		i--;
	}
	return (0);
}

int	ft_init_envp(t_data *data, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	data->envp = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (envp[i])
	{
		data->envp[i] = ft_strdup(envp[i]);
		i++;
	}
	data->envp[i] = NULL;
	return (0);
}
