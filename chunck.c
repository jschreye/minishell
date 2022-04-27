#include "minishell.h"

int ft_if_sq(t_data *data)
{
    int i;
    int count;

    count = 0;
    i = 0; 
    while (data->str_rl[i])
    {
        if (ft_count_quote(data->str_rl) % 2 == 1
            && ft_count_quote(data->str_rl) == 1)
            i = ft_str_chunck(data, i);
        else
        {
            count++;
            i = ft_str_chunck(data, i);
            if (count >= 2)
                break;
            while (data->str_rl[i] != '\'')
                i = ft_str_chunck(data, i);
            count++;
        }   
    }
    ft_create_chunck(data, i);;
    return (0);
}

int ft_if_dq(t_data *data)
{
    int i;
    int count;

    count = 0;
    i = 0; 
    while (data->str_rl[i])
    {
        if (ft_count_quote(data->str_rl) % 2 == 1
            && ft_count_quote(data->str_rl) == 1)
            i = ft_str_chunck(data, i);
        else
        {
            count++;
            i = ft_str_chunck(data, i);
            if (count >= 2)
                break;
            while (data->str_rl[i] != '"')
                i = ft_str_chunck(data, i);
            count++;
        }   
    }
    ft_create_chunck(data, i);
    return (0);
}

int ft_if_charact(t_data *data)
{
    int i;

    i = 0; 
    while (data->str_rl[i])
    {
        if (data->str_rl[i] == '"' || data->str_rl[i] == '\''
            || data->str_rl[i] == '|' || data->str_rl[i] == '<'
            || data->str_rl[i] == '>' || data->str_rl[i] == ' ')
            break ;
        else
            i = ft_str_chunck(data, i);
    }
    ft_create_chunck(data, i);
    return (0);
}

int ft_if_pipe(t_data *data)
{
    int i;

    i = 0;
    i = ft_str_chunck(data, i);
    ft_create_chunck(data, i);
    return (0);
}

int ft_create_str_chunck(t_data *data)
{   
    int i = 0;
    ft_del_consec_quote(data);
    while (data->str_rl[i])
    {
        if (data->str_rl[i] == '\'')
            ft_if_sq(data);
        else if (data->str_rl[i] == '"')
            ft_if_dq(data);
        else if (data->str_rl[i] == '|')
            ft_if_pipe(data);
        else if (data->str_rl[i] == '<' || data->str_rl[i] == '>')
            ft_if_chevron(data);
        else if (data->str_rl[i] == ' ')
            ft_if_space(data);
        else if (data->str_rl[i])
            ft_if_charact(data);
        else
            i++;
        i = 0;
    }
    return (0);
}
