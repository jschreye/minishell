#include "minishell.h"

int ft_init_struct(t_data *data)
{
    data->str_getenv = malloc(2048 * sizeof(char));
    data->str_rl = malloc(2048 * sizeof(char));
    data->str_path = malloc(2048 * sizeof(char));
    data->str_getenv = getenv("PATH");
    data->tab_getenv = ft_split(data->str_getenv, ':');
    return (0);
}

void ft_malloc_chunck(t_data *data)
{
    int size;
    int i;

    i = 0;
    size = ft_strlen(data->str_rl);
    data->tab_rl = malloc(size * sizeof(char));
    while (i < size)
    {
        data->tab_rl[i] = malloc(size * sizeof(char));
        i++;
    }
}