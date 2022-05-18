#include "minishell.h"

int ft_init_struct(t_data *data)
{
    data->str_chunk = ft_calloc(2048, sizeof(char));//free
    data->str_getenv = getenv("PATH");
    data->tab_getenv = ft_split(data->str_getenv, ':');//free
    data->i_chunk = 0;
    return (0);
}
