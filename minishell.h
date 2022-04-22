/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:48:32 by grubin            #+#    #+#             */
/*   Updated: 2022/04/20 15:19:47 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"
#include <sys/types.h>
#include <signal.h>

typedef struct s_data
{
    int     i_tab;
    char    *str_getenv;
    char    *str_rl;
    char    *str_path;
    char    **tab_getenv;
    char    **tab_rl;
}   t_data;

char *ft_prompt_quote(char *str);
int ft_check_first_quote(char *str);
int ft_exec_cmd(t_data *data, char **envp);
int ft_access_path(t_data *data);
int ft_del_consec_quote(t_data *data);
int ft_count_quote(char *str);
char *ft_check_new_dquote(char *new_str);
char *ft_check_new_quote(char *new_str);
char *ft_del_quote(char *str);
char *ft_prompt_quote(char *str);
int ft_chunck_quote(t_data *data);
int ft_init_struct(t_data *data);
void ft_malloc_chunck(t_data *data);

#endif