/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:48:32 by grubin            #+#    #+#             */
/*   Updated: 2022/05/24 13:07:52 by jschreye         ###   ########.fr       */
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
#include <sys/wait.h>
#include <signal.h>

typedef struct  s_env
{
    int     size_env;
    int     count;
    int     i_res;
    int     i_str;
    int     i_tmp;
    char     *env_tmp;
    char     *str_tmp;
    char     *tmp;
    char     *result;
} t_env;

typedef struct  s_cmd
{
    char *path;
    char **args;
    int output_fd;
    int input_fd;
} t_cmd;

typedef struct s_data
{
    int     **pipe;
    int     nbr_pipe;
    int     i_chunk;
    int     size_cmd;
    char    *str_chunk;
    char    *str_getenv;
    char    *str_rl;
    char    *str_path;
    char    **envp;
    char    **tab_getenv;
    char    **tab_chunck;
    t_cmd   *tab_cmd;
}   t_data;

void ft_print_tab(char **tab);

//char *ft_prompt_quote(char *str);
int ft_check_first_quote(char *str);
int ft_exec_cmd(t_data *data);
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
int ft_init_cmd(t_data *data);
int ft_if_pipe(t_data *data);
int ft_if_sq(t_data *data);
int ft_if_dq(t_data *data);
int ft_create_pipe(t_data *data);
int ft_dollar(char **tab);

#endif