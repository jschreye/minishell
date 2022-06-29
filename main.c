/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:05:12 by jschreye          #+#    #+#             */
/*   Updated: 2022/06/24 15:21:14 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_infinity_while(t_data *data)
{
	t_err	err;

	add_history(data->str_rl);
	ft_create_str_chunck(data);
	data->tab_chunck = ft_split(data->str_chunk, '\n');
	ft_dollar(data, data->tab_chunck);
	ft_init_cmd(data);
	ft_check_valid_command(data, &err);
	ft_exec_cmds(data);
	ft_free(data);
	return (0);
}

int	ft_init(t_data *data, struct termios *sig, char **envp)
{
	g_return_sig = 0;
	ft_init_envp(data, envp);
	init_signals(sig);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_data			data;
	struct termios	sig;

	ft_init(&data, &sig, envp);
	if (argc == 1)
	{
		while (1)
		{
			ft_init_struct(&data);
			data.str_rl = readline("$ ");
			if (!data.str_rl)
				break ;
			ft_infinity_while(&data);
		}
		tcsetattr(STDIN_FILENO, TCSANOW, &sig);
	}
	else
		printf("Error argument\n");
	free(data.str_chunk);
	ft_free_tab(data.envp);
	(void)argv;
	return (g_return_sig);
}
