#include "minishell.h"

int ft_exec_cmd(t_data *data)
{
    pid_t   pid;
    int     status;

    status = 0;
    pid = fork();
    if (pid == -1)
		perror("fork");
    else if (pid > 0)
        waitpid(pid, &status, 0);
    else
    {
        if(execve(data->str_path, &data->tab_cmd[0].args[0], data->envp) == - 1)
            perror("shell");
        exit(EXIT_FAILURE);
    }
    if (data->str_path)
        free(data->str_path);
    return (0);
}

int ft_access_path(t_data *data)
{
    int i;
    char *final_path;

    final_path = ft_join("/", data->tab_cmd[0].args[0]);
    i = 0;
    while (data->tab_getenv[i])
    {
        data->str_path = ft_join(data->tab_getenv[i], final_path);
        if (!access(data->str_path, X_OK))
            break ;
        i++;
        free(data->str_path);
        data->str_path = NULL;
    }
    free(final_path);
    ft_exec_cmd(data);
    return (0);
}