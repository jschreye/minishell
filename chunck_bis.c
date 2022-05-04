
#include "minishell.h"

int ft_if_chevronstr(t_data *data, int i)
{
    while (data->str_rl[i] != ' ')
    {
        if (data->str_rl[i] == '\0' || data->str_rl[i] == '|')
            break ;
        i = ft_str_chunck(data, i);
    }
    return (i);
}

int ft_if_spacestr(t_data *data, int i)
{
    while (data->str_rl[i] == ' ')
        i = ft_str_chunck(data, i);
    return (i);
}

int ft_if_chevron(t_data *data)
{
    int i;

    i = 0;
    while (data->str_rl[i])
    {
        //i = ft_str_chunck(data, i);
        if (data->str_rl[i + 1] == '<' || data->str_rl[i + 1] == '>')
            i = ft_str_chunck(data, i);
        if (data->str_rl[i] == '<' || data->str_rl[i] == '>')
        {
            i = ft_str_chunck(data, i);
            break ;
        }
        if (data->str_rl[i] == ' ')
            i = ft_if_spacestr(data, i);
        if (data->str_rl[i])
        {
            i = ft_if_chevronstr(data, i);
            if (data->str_rl[i] == ' ' || data->str_rl[i] == '\0')
                break ;
        }
        if (data->str_rl[i] == '|')
            break ;
    }
    ft_create_chunck(data, i);
    return (0);
}

int ft_if_space(t_data *data)
{
    int i;

    i = 0;
    while (data->str_rl[i] == ' ')
        i++;
    ft_memmove(data->str_rl, data->str_rl + i , ft_strlen(data->str_rl));
    return (0);
}

int ft_check_quote_space(t_data *data , int i)
{
    if (data->str_rl[0] == '\"')
        while (data->str_rl[i])
        {
            if (data->str_rl[i] == '\"' && (data->str_rl[i + 1] == ' ' 
                || data->str_rl[i + 1] == '|'))
                break;
            else if (data->str_rl[i] == '|' && ft_count_quote(data->str_rl) % 2 == 1)
                break;
            else
                i = ft_str_chunck(data, i);
        }
    else if (data->str_rl[0] == '\'')
        while (data->str_rl[i])
        {
            if (data->str_rl[i] == '\'' && (data->str_rl[i + 1] == ' ' 
                || data->str_rl[i + 1] == '|'))
                break;
            else if (data->str_rl[i] == '|' && ft_count_quote(data->str_rl) % 2 == 1)
                break;
            else
                i = ft_str_chunck(data, i);
        }
    return (i);
}