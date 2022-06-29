/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:39:08 by grubin            #+#    #+#             */
/*   Updated: 2022/06/24 16:02:30 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_env(t_data *data, t_env *env)
{
	int	i;
	int	i_env;

	i = 0;
	i_env = 0;
	while (env->str_tmp[i])
	{
		if (env->str_tmp[i] == '$')
		{
			i++;
			while (ft_isalpha(env->str_tmp[i]) == 1)
			{
				env->env_tmp[i_env] = env->str_tmp[i];
				i++;
				i_env++;
			}
			break ;
		}
		i++;
	}
	env->size_env = ft_strlen(env->env_tmp);
	env->result = ft_getenv(data, env->env_tmp);
	free(env->env_tmp);
	return (env->result);
}

int	ft_change_env(t_data *data, t_env *env, int i)
{
	ft_init_env(env);
	env->result = ft_get_env(data, env);
	i = 0;
	while ((size_t)i < ft_strlen(env->str_tmp) && env->result)
	{
		if (env->str_tmp[i] == '$' && env->count < 1)
		{
			env->count++;
			while (env->result[env->i_res])
			{
				env->tmp[env->i_tmp] = env->result[env->i_res];
				env->i_tmp++;
				env->i_res++;
			}
			i = i + (env->size_env + 1);
		}
		env->tmp[env->i_tmp] = env->str_tmp[i];
		env->i_tmp++;
		i++;
	}
	env->str_tmp = ft_realloc(env->str_tmp, 2048);
	ft_strlcpy(env->str_tmp, env->tmp, ft_strlen(env->tmp) + 1);
	free(env->result);
	return (i);
}

int	ft_no_change(t_env *env, int i)
{
	char	*str;

	env->tmp = ft_calloc(2048, sizeof(char));
	if (strncmp(env->str_tmp, "$?\0", 3) == 0)
	{
		str = ft_itoa(g_return_sig);
		ft_strcpy(env->str_tmp, str);
		free(str);
	}
	while (env->str_tmp[i])
	{
		env->tmp[i] = env->str_tmp[i];
		i++;
	}
	return (i);
}

void	ft_include_env(t_data *data, t_env *env, int i)
{
	i = 0;
	while (env->str_tmp[i])
	{
		i = ft_check_quote(env, i);
		if (ft_strncmp(env->str_tmp, "\"$\"", 3) == 0)
			i = ft_no_change(env, i);
		else if (env->str_tmp[i] == '"' && env->str_tmp[i + 1] != '\0')
		{
			i++;
			i = ft_check_dollar(data, env, i);
		}
		else if (env->str_tmp[i] == '$' && env->str_tmp[i + 1] == '\'')
			ft_memmove(&env->str_tmp[i], &env->str_tmp[i + 1],
				ft_strlen(env->str_tmp));
		else if ((env->str_tmp[i] == '$' && env->str_tmp[i + 1] == '"')
			|| (env->str_tmp[i] == '$' && env->str_tmp[i + 1] == '\0'))
			i = ft_no_change(env, i);
		else if (env->str_tmp[i] == '$' && env->str_tmp[i + 1] == '?')
			i = ft_no_change(env, i);
		else if (env->str_tmp[i] == '$')
			i = ft_change_env(data, env, i);
		else
			i++;
	}
}

int	ft_dollar(t_data *data, char **tab)
{
	t_env	env;
	int		i;

	env.env_tmp = NULL;
	env.result = NULL;
	env.tmp = NULL;
	i = 0;
	while (tab[i])
	{
		if (ft_count_quote(tab[i]) == 1)
			break ;
		if (ft_strchr(tab[i], '$'))
		{
			env.str_tmp = ft_strdup(tab[i]);
			ft_include_env(data, &env, i);
			tab[i] = ft_realloc(tab[i], 2048);
			ft_strlcpy(tab[i], env.str_tmp, ft_strlen(env.str_tmp) + 1);
			free(env.str_tmp);
			i++;
		}
		else
			i++;
	}
	free(env.tmp);
	return (0);
}
