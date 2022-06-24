/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:22:45 by jschreye          #+#    #+#             */
/*   Updated: 2022/06/23 15:46:21 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_pwd(t_data *data)
{
    char *str;
    str = ft_getenv(data, "PWD");
    printf("%s\n", str);
    free(str);
}