/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:05:17 by grubin            #+#    #+#             */
/*   Updated: 2022/06/22 15:34:43 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_exec_child(t_data *data, int fd[data->nbr_cmd - 1][2], int i, t_fd *files)
{
    if (i > 0)
        dup2(fd[i - 1][0], STDIN_FILENO);
    if (i < data->nbr_cmd - 1)
        dup2(fd[i][1], STDOUT_FILENO); 
    close_pipes(data->nbr_cmd - 1, fd);
    if (files->red == 1 && files->tab_in != NULL)
        exec_red(data, files);
    else if (files->red == 0)
        ft_execve(data);
    return (0);   
}

int ft_init_fd(t_data *data, t_fd *files, int i)
{
    ft_init_red(files);
    error_red(data->tab_cmd[i].args, files, i);
    ft_check_fd_in(data->tab_cmd[i].args, files);
    ft_tabcpy(data, i, 0);
    return (0);
}

int ft_pipe(t_data *data)
{
    t_fd    files;
    int     i;
    int     fd[data->nbr_cmd-1][2];
    int     pid;
    int     status;
   
    i = 0;
    while (i < data->nbr_cmd-1)
    {
        pipe(fd[i]);
        i++;
    }
    i = 0;
    while (i <= data->nbr_cmd-1)
    {
        ft_init_fd(data, &files, i);
        pid = fork();
        if (pid == 0)
        {
            ft_exec_child(data, fd, i, &files);
            ft_free_tab(data->tab_cpy);
            close_pipes(data->nbr_cmd-1, fd);
            exit(0);
        }
        ft_free_tab(data->tab_cpy);
        i++;
    }
    close_pipes(data->nbr_cmd-1, fd);
    waitpid(pid, &status, 0);
    return_sig = WEXITSTATUS(status);
    return (0);
}

int ft_check_redir(t_data *data)
{
    int i_arg;

    i_arg = 0;
    while (data->tab_cmd[0].args[i_arg])
    {
        if (ft_strncmp(data->tab_cmd[0].args[i_arg], ">\0", 2) == 0
            || ft_strncmp(data->tab_cmd[0].args[i_arg], "<\0", 2) == 0
            || ft_strncmp(data->tab_cmd[0].args[i_arg], ">>\0", 3) == 0
            || ft_strncmp(data->tab_cmd[0].args[i_arg], "<<\0", 3) == 0)
            return (1);
        i_arg++;
    }
    return (0);
}

int ft_exec_cmds(t_data *data)
{
    char *tmp;

    tmp = "|\0";
    if (ft_check_error_redir(data) == 1)
        return (1);
    if (data->nbr_cmd > 1 && ft_strncmp(data->tab_chunck[0], tmp, 2) == 0)
    {
        printf("$: syntax error near unexpected token `|'\n");
        return (0);
    }
    if (data->nbr_cmd == 1 && ft_check_redir(data) == 0)
        ft_builtins_without_pipe(data);
    else
        ft_pipe(data);
    return (0);;
}