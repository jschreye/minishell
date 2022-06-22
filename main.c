/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:05:12 by jschreye          #+#    #+#             */
/*   Updated: 2022/06/22 14:48:59 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int main(int argc, char **argv, char **envp) 
{
    t_data data;
    t_err err;
    struct termios sig;
    
    return_sig = 0;
    ft_init_envp(&data, envp);
    init_signals(&sig);
    if (argc == 1)
    {
        while (1)
        {
            ft_init_struct(&data);
            data.str_rl = readline("$ ");//free
            if (!data.str_rl)
                break ;
            add_history(data.str_rl);
            ft_create_str_chunck(&data);
            data.tab_chunck = ft_split(data.str_chunk, '\n');//free
            ft_dollar(&data, data.tab_chunck);
            ft_init_cmd(&data);
            ft_check_valid_command(&data, &err);
            ft_exec_cmds(&data);
            //for(int i_cmd = 0; data.tab_cmd[i_cmd].args; i_cmd++)
                //for(int i_arg = 0; data.tab_cmd[i_cmd].args[i_arg]; i_arg++)
                    //printf("str_tab_args[%d][%d] = %s\n",i_cmd, i_arg, data.tab_cmd[i_cmd].args[i_arg]);
            ft_free(&data);
        }
        tcsetattr(STDIN_FILENO, TCSANOW, &sig);
    }
    else
        printf("Error argument\n");
    free(data.str_chunk);
    (void)argv;
    return (return_sig); 
}
