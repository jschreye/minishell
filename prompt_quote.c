#include "minishell.h"

char *ft_prompt_quote(char *str)
{
    char *new_str;

    new_str = malloc(2048 * sizeof(char));
    if (ft_check_first_quote(str) == 1)
    {
        new_str = readline("quote> ");
        new_str = ft_check_new_quote(new_str);
        if (new_str[0] == (char)39)
            str = ft_strjoin(str, &new_str[0]);
        else
            str = ft_prompt_quote(new_str);
    }
    else if (ft_check_first_quote(str) == 2)
    {
        new_str = readline("dquote> ");
        new_str = ft_check_new_dquote(new_str);
        if (new_str[0] == (char)34)
            str = ft_strjoin(str, &new_str[0]);     
        else
            str = ft_prompt_quote(new_str);
    }
    if (ft_count_quote(str) == 1)
        str = ft_prompt_quote(str);
    return (str);
}