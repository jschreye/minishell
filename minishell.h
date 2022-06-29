/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:48:32 by grubin            #+#    #+#             */
/*   Updated: 2022/06/28 09:32:30 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <termios.h>
# include <fcntl.h>
# include <dirent.h>

int	g_return_sig;

typedef struct s_her
{
	char	*input;
	int		nb_lines;
	char	**tmp;
}			t_her;

typedef struct s_err
{
	int		i;
	int		j;
	int		k;
	char	*cmd;
	char	*cmd_path;
}			t_err;

typedef struct s_fd
{
	int		value;
	int		pid[100];
	int		fd[100][2];
	int		red;
	int		fd_in;
	int		fd_out;
	int		heredocs;
	int		append;
	int		status;
	char	**tab_in;
}			t_fd;

typedef struct s_unset
{
	char	**tab;
}			t_unset;

typedef struct s_export
{
	int		val_min;
	char	**tab;
}			t_export;

typedef struct s_cd
{
	int		count_point;
	int		count_slash;
	char	**tab;
	char	*pwd;
	char	*oldpwd;
	char	*path;
}			t_cd;

typedef struct s_env
{
	int		size_env;
	int		count;
	int		i_res;
	int		i_str;
	int		i_tmp;
	char	*env_tmp;
	char	*str_tmp;
	char	*tmp;
	char	*result;
}			t_env;

typedef struct s_cmd
{
	int		input_fd;
	int		output_fd;
	char	*path;
	char	**args;
	pid_t	pid;
}			t_cmd;

typedef struct s_data
{
	int		nbr_cat;
	int		nbr_cmd;
	int		i_chunk;
	char	*str_chunk;
	char	*str_getenv;
	char	*str_rl;
	char	*str_path;
	char	**envp;
	char	**tab_getenv;
	char	**tab_chunck;
	char	**tab_cpy;
	t_cmd	*tab_cmd;
}			t_data;

void	ft_print_tab(char **tab);
void	ft_free(t_data *data);
int		ft_init_envp(t_data *data, char **envp);
int		ft_check_first_quote(char *str);
int		ft_exec_cmd(t_data *data, int i_cmd);
int		ft_access_path(t_data *data, int i_cmd, int i_arg);
int		ft_count_quote(char *str);
int		ft_init_struct(t_data *data);
void	ft_malloc_chunck(t_data *data);
int		ft_create_str_chunck(t_data *data);
void	ft_create_chunck(t_data *data, int i);
int		ft_str_chunck(t_data *data, int i);
int		ft_del_consec_backn(t_data *data);
int		ft_del_chunck_full_space(t_data *data);
int		ft_if_space(t_data *data);
int		ft_if_chevron(t_data *data);
int		ft_init_cmd(t_data *data);
int		ft_if_pipe(t_data *data);
int		ft_if_sq(t_data *data);
int		ft_if_dq(t_data *data);
int		ft_pipe(t_data *data, t_fd *files);
int		ft_dollar(t_data *data, char **tab);
int		ft_check_builtins(t_data *data, int i);
int		ft_cmds_with_pipe(t_data *data);
int		ft_check_dollar(t_data *data, t_env *env, int i);
int		ft_check_quote(t_env *env, int i);
int		ft_change_env(t_data *data, t_env *env, int i);
int		ft_exec_cmds(t_data *data);
int		ft_execve(t_data *data);
int		ft_env(t_data *data, char **tab);
void	ft_pwd(t_data *data);
int		ft_echo(char **tab);
int		ft_exit(t_data *data, int i_cmd);
int		ft_init_env(t_env *env);
int		ft_cd(t_data *data, int i_cmd);
int		ft_unset(t_data *data);
void	init_signals(struct termios *sig);
int		ft_builtins_with_pipe(t_data *data, int i);
int		ft_builtins_without_pipe(t_data *data, t_fd *files);
int		ft_chdir(t_cd *cd, t_data *data, int i_cmd);
int		ft_go_up_the_path(t_cd *cd, t_data *data);
void	ft_free_cd(t_cd *cd);
int		ft_count_args(t_data *data, int i_cmd);
int		ft_change_envp(t_cd *cd, t_data *data);
int		ft_check_cat(t_data *data);
int		ft_export(t_data *data);
void	ft_free_tab(char **tab);
void	ft_print_tab_export(t_export *export);
int		ft_error_export(t_data *data);
int		ft_export_new_env(t_export *export, t_data *data);
int		ft_similar(t_data *data, int i_arg);
int		ft_creat_new_env(t_export *export, t_data *data, int i_arg);
void	ft_tri_env(t_data *data, t_export *export);
int		ft_init_struct_export(t_export *export, t_data *data);
int		ft_count_egale(char *str);
int		ft_del_quote(char **tab);
char	*ft_getenv(t_data *data, char *str);
int		exec_red(t_data *data, t_fd *files);
int		check_file_out(char *file_name, t_fd *files, int append);
int		check_file_in(char *file_name, t_fd *files);
char	**cpy_tab_heredocs(char **tab, int nb_lines, char *input);
int		check_heredoc(char *key_word, t_fd *files);
int		ft_check_fd_in(char **tab, t_fd *files);
char	*copy_new_line(char *new_line);
void	ft_tabcpy(t_data *data, int i_cmd, int i_arg);
void	close_pipes(int nb_pipe, int (*fd)[2]);
int		error_red(char **cmd, t_fd *files, int i);
void	ft_init_red(t_fd *files);
int		ft_check_error_redir(t_data *data);
int		ft_init_fd(t_data *data, t_fd *files, int i);
int		ft_check_valid_command(t_data *data, t_err *err);
int		ft_wait_pid(t_data *data, t_fd *files);
int		ft_check_if_child(int new_val);

#endif
