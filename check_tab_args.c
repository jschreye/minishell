/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:05:17 by grubin            #+#    #+#             */
/*   Updated: 2022/05/05 13:55:47 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_check_tab_args(t_data *data)
{
    // lire la cmd
    //int i_cmd;
    //int i_arg;
    
    ft_dollar(data->tab_cmd); 
  
    
        // si cmd[0] pas valide -> error
        // si dans cmd[] il y a $ remplacer ce qui suis le $ par sa valeur
        // si dans cmd < ou << ou > ou >> 
            // check si valide (infile avant et outfile après)
                // si pas valide -> error
                // sinon ft_redirection
        // si cmd[0] = buildting -> ft_truc
            // sinon ft_execve
        // si cmd[0] = / utiliser le chemin absolue tel quel
            // sinon utiliser PATH
        // si cmd > 1 -> pipe
        // sinon execute cmd
    return (0);
}