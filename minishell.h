/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:48:32 by grubin            #+#    #+#             */
/*   Updated: 2022/04/25 16:22:02 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"
#include <sys/types.h>
#include <signal.h>

typedef struct s_data
{
    int     i_chunk;
    char    *str_chunk;
    char    *str_getenv;
    char    *str_rl;
    char    *str_path;
    char    **tab_getenv;
    char    **tab_chunck;
}   t_data;

void ft_print_tab(char **tab);

//char *ft_prompt_quote(char *str);
int ft_check_first_quote(char *str);
int ft_exec_cmd(t_data *data, char **envp);
int ft_access_path(t_data *data);
int ft_del_consec_quote(t_data *data);
int ft_count_quote(char *str);
//char *ft_check_new_dquote(char *new_str);
//char *ft_check_new_quote(char *new_str);
//char *ft_del_quote(char *str);
//char *ft_prompt_quote(char *str);
//int ft_chunck_quote(t_data *data);
int ft_init_struct(t_data *data);
void ft_malloc_chunck(t_data *data);
int ft_create_str_chunck(t_data *data);
void ft_create_chunck(t_data *data, int i);
int ft_str_chunck(t_data *data, int i);
int ft_del_consec_backn(t_data *data);
int ft_del_chunck_full_space(t_data *data);
int ft_if_space(t_data *data);
int ft_if_chevron(t_data *data);


#endif