#include "minishell.h"

/*int ft_check_quote(t_data *data)
{
    int i;

    i = 0;
    data->str_rl = ft_chunck_quote(data->str_rl);//A FAIRE
    if (ft_count_quote(data->str_rl) == 1)
        data->str_rl = ft_prompt_quote(data->str_rl);
    data->str_rl = ft_del_quote(data->str_rl);
    printf("str_rl = %s\n", data->str_rl);
    return (0);
}*/

int main(int argc, char **argv, char **envp) 
{
    t_data data;
    //int i = 0;

    ft_init_struct(&data);
    while (1)
    {
        data.str_rl = readline("$ ");
        add_history(data.str_rl);
        ft_chunck_quote(&data);
        /*data.tab_rl = ft_split(data.str_rl, ' ');
        if(!data.tab_rl || !data.tab_rl[0])
            continue; 
        ft_access_path(&data);
        ft_exec_cmd(&data, envp); */  
    }
  	(void)argc;//tester que argc soit = 1
	(void)argv;
    (void)envp;
    return 0; 
}