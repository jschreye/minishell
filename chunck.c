#include "minishell.h"

int ft_if_sq(t_data *data)
{
    int i;

    i = 0;
    while (data->str_rl[i])
    {
        if (ft_count_quote(data->str_rl) == 1)
            data->tab_rl[data->i_tab][i] = data->str_rl[i];
        else if (data->str_rl[i] == (char)39)
        {
            data->tab_rl[data->i_tab][i] = data->str_rl[i];
            break ;
        }
        i++;
    }
    ft_memmove(data->str_rl, data->str_rl + i, ft_strlen(data->str_rl));
    data->tab_rl[data->i_tab][i + 1] = '\0';
    data->i_tab++;
    return (0);
}

int ft_create_chunck(t_data *data)
{   
    int i = 0;

    data->i_tab = 0;
    while (data->str_rl[i])
    {
        if (data->str_rl[0] == (char)39)
        {
            ft_if_sq(data);
                //si count_quote = 1  enregistre tout
                //sinon enregistre jusqu a la suivante
                //il faut mememove
        }
            /*else if (data->str_rl[i] == (char)34)
            {
                //faire fonction
                //si count_quote = 1  enregistre tout
                //sinon enregistre jusqu a la suivante
                //il faut mememove
            }
            else
            {
                //faire fonction
                //il faut mememove
            }*/
        i++;
    }
    return (0);
}

int ft_chunck_quote(t_data *data)
{
    int i = 0;

    ft_malloc_chunck(data);
    ft_create_chunck(data);
    while(data->tab_rl[i])
    {
        printf("tab =%s\n", data->tab_rl[i]);
        i++;
    }
    return(0);
}

/*            while (j < i)
            {
                data->tab_rl[i_tab][j] = str_tmp[j];
                j++;
            }
            ft_memmove(str_tmp, str_tmp + i, ft_strlen(str_tmp));
            printf("str_tmp = %s\n", str_tmp);
            data->tab_rl[i_tab][j] = '\0';
            i = 0;
            j = 0;
            i_tab++;
*/