#include "minishell.h"

int ft_exec_cmd(t_data *data, char **envp)
{
    pid_t   pid;
    int     status;

    status = 0;
    pid = fork();
    if (pid == -1)
		perror("fork");
    else if (pid > 0)
    {
        waitpid(pid, &status, 0);
        kill(pid, SIGTERM);
    }
    else
    {
        if(execve(data->str_path, &data->tab_chunck[0], envp) == - 1)
            perror("shell");
        exit(EXIT_FAILURE);
    }
    return (0);
}

int ft_access_path(t_data *data)
{
    int i;
    int len;
    char *final_path;

    len = ft_strlen(data->tab_chunck[0]);
    final_path = malloc(len * sizeof(char) + 1);
    final_path = ft_strdup("");
    final_path = ft_join("/", data->tab_chunck[0]);
    i = 0;
    while (data->tab_getenv[i])
    {
        data->str_path = ft_join(data->tab_getenv[i], final_path);
        if (!access(data->str_path, X_OK))
            return (1);
        i++;
    }
    free(final_path);
    return (0);
}