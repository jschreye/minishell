/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:37:12 by grubin            #+#    #+#             */
/*   Updated: 2022/06/22 15:27:54 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_first_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 39)
			return (1);
		else if (str[i] == 34)
			return (2);
		i++;
	}
	return (0);
}

int	ft_count_quote(char *str)
{
	while (*str)
	{
		if (*str == 39)
		{
			str = ft_strchr(str + 1, *str);
			if (str == NULL)
				return (1);
		}
		else if (*str == 34)
		{
			str = ft_strchr(str + 1, *str);
			if (str == NULL)
				return (1);
		}
		str++;
	}
	return (0);
}

int	ft_remove_quote(char *str, int i, char quote)
{
	int	len;

	len = ft_strlen(str);
	ft_memmove(&str[i], &str[i + 1], len - i);
	len = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == quote)
		{
			ft_memmove(&str[i], &str[i + 1], len - i);
			return (i);
		}
		i++;
	}
	return (i);
}

int	ft_delete_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			i = ft_remove_quote(str, i, '\'');
		else if (str[i] == '"')
			i = ft_remove_quote(str, i, '"');
		else
			i++;
	}
	return (i);
}

int	ft_del_quote(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_count_quote(tab[i]) % 2 != 0)
		{
			printf("Error quote.\n");
			return (1);
		}
		else
			ft_delete_quote(tab[i]);
		i++;
	}
	return (0);
}
