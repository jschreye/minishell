#include "minishell.h"
void ft_print_tab(char **tab)
{
    int i = 0;

    while (tab[i])
    {
        printf("tab = %s\n", tab[i]);
        i++;
    }
}

/*
            for(int i_cmd = 0; data.tab_args[i_cmd].args; i_cmd++)
                for(int i_arg = 0; data.tab_args[i_cmd].args[i_arg]; i_arg++)
                    printf("str_tab_args[%d][%d] = %s\n",i_cmd, i_arg, data.tab_args[i_cmd].args[i_arg]);
*/

void ft_free(t_data *data)
{
    int i;


    i = 0;
    if (data->str_rl)
        free(data->str_rl);
    if (data->str_chunk)
        free(data->str_chunk);
    i=0;
    while (data->tab_getenv[i])
    {
        free(data->tab_getenv[i]);
        i++;
    }
    free(data->tab_getenv);
    
    i = 0;
    while (data->tab_chunck[i])
    {
        free(data->tab_chunck[i]);
        i++;
    }
    
    free(data->tab_chunck);
    i = 0;
    while (data->tab_cmd[i].args)
    {
        free(data->tab_cmd[i].args);
        i++;
    }
    free(data->tab_cmd);
}

int main(int argc, char **argv, char **envp) 
{
    t_data data;

    data.envp = envp;
    if (argc == 1)
    {
        while (1)
        {
            ft_init_struct(&data);
            data.str_rl = readline("$ ");//free
            if (!data.str_rl)
                break ;
            add_history(data.str_rl);
            ft_create_str_chunck(&data);
            data.tab_chunck = ft_split(data.str_chunk, '\n');//free
            ft_dollar(data.tab_chunck);
            ft_init_cmd(&data);
            ft_check_tab_args(&data);
            for(int i_cmd = 0; data.tab_cmd[i_cmd].args; i_cmd++)
                for(int i_arg = 0; data.tab_cmd[i_cmd].args[i_arg]; i_arg++)
                    printf("str_tab_args[%d][%d] AVANT = %s\n",i_cmd, i_arg, data.tab_cmd[i_cmd].args[i_arg]);
            //ft_access_path(&data);
            //ft_exec_cmd(&data, envp);
            ft_free(&data);
        }
    }
    else
        printf("Error argument\n");
    (void)argv;
    return 0; 
}
