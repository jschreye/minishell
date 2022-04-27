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

int main(int argc, char **argv, char **envp) 
{
    t_data data;
    if (argc == 1)
    {
        while (1)
        {
            ft_init_struct(&data);
            data.str_rl = readline("$ ");
            add_history(data.str_rl);
            ft_create_str_chunck(&data);
            data.tab_chunck = ft_split(data.str_chunk, '\n');
            if(!data.tab_chunck || !data.tab_chunck[0])
                continue;
            ft_print_tab(data.tab_chunck);
            ft_access_path(&data);
            ft_exec_cmd(&data, envp);
            free(data.str_rl);
            free(data.str_chunk);
        }
    }
    else
        printf("Error argument\n");
	(void)argv;
    (void)envp;
    return 0; 
}