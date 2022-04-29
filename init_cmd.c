#include "minishell.h"

int ft_malloc_tab_args(t_data *data)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (data->tab_chunck[i])
    {
        if (data->tab_chunck[i][0] == '|')
            count++;
        i++;
    }
    data->tab_args = ft_calloc((count + 2), sizeof(t_cmd));
    return (0);
}
int ft_count_token(t_data *data)
{
    int i = 0;

    while(data->tab_chunck[i])
    {
        i++;
    }
    return (i);
}

int ft_init_cmd(t_data *data, t_cmd *cmd)
{
    int i = 0;
    int count;
    int x = 0;

    cmd->path = NULL;
    ft_malloc_tab_args(data);
    count = ft_count_token(data);
    while (data->tab_chunck[i])
    {
        data->tab_args[x].args = ft_calloc(count, sizeof(char*));
        while (data->tab_chunck[i][0] != '|' || data->tab_chunck[i] != NULL)
        {
            data->tab_args[x].args = &data->tab_chunck[i];
            if (data->tab_chunck[i + 1][0] == '|' || data->tab_chunck[i] != NULL)
            {
                i++;
                x++;
            }
            i++;
        }
        i++;
    }
    return (0);
}