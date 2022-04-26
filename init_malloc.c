#include "minishell.h"

int ft_init_struct(t_data *data)
{
    data->str_getenv = malloc(2048 * sizeof(char));
    data->str_path = malloc(2048 * sizeof(char));
    data->str_chunk = ft_calloc(2048, sizeof(char));
    data->str_getenv = getenv("PATH");
    data->tab_getenv = ft_split(data->str_getenv, ':');
    data->i_chunk = 0;
    return (0);
}
