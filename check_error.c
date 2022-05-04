
int ft_check_error_quote(char **tab)
{
    int count_sq;
    int count_dq;
    int i;
    int j;

    count_sq = 0;
    count_dq = 0;
    i = 0;
    while (tab[i])
    {
        j = 0;
        while(tab[i][j])
        { //peu etre utiliser fonction count_quote
            if (tab[i][j] == '\'')
                count_sq++;
            if (tab[i][j] == '\"')
                count_dq++;
            j++;
        }
        i++;
    }
    if (count_sq % 2 == 0)
        return (1);
    if (count_dq % 2 == 0)
        return (1);
    else
        return (2);
}

int ft_check_error_pipe(char **tab)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (tab[i])
    {
        if (tab[i] == '|' && tab[i + 1] == '|')
            return (2)
        i++;
    }
    return (0);
}

/*int ft_check_error_chevron(char **tab)
{
    return (0);
}

int ft_check_error(char **tab)
{
    return (0);
}
*/

