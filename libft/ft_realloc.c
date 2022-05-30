/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:59:37 by grubin            #+#    #+#             */
/*   Updated: 2022/05/19 16:04:22 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_realloc(void *ptr, size_t size)
{
    void* new_data = NULL;

    if(size)
    {
        if(!ptr)
            return (ft_calloc(size, sizeof(char))); //marche uniquement pour des chars revenir sur un malloc size si besoin
        new_data = ft_calloc(size, sizeof(char)); //marche uniquement pour des chars revenir sur un malloc size si besoin
        if(new_data)
        {
            ft_memcpy(new_data, ptr, size);
            free(ptr);
        }
    }
    return (new_data);
}