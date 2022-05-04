#include "minishell.h"

void ft_free(t_data *data)
{
    int i;

    i = 0;
    while(data->tab_getenv[i])
    {
        free(data->tab_getenv[i]);
        i++;
    }
    free(data->tab_getenv);
    i = 0;
    while(data->tab_chunck[i])
    {
        free(data->tab_chunck[i]);
        i++;
    }
    free(data->tab_chunck);
    i = 0;
    while(data->tab_args[i].args)
    {
        free(data->tab_args[i].args);
        i++;
    }
    if (data->tab_args)
        free(data->tab_args);
    if (data->str_chunk)
        free(data->str_chunk);
    if (data->str_rl)
        free(data->str_rl);
}