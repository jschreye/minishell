/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:02:21 by grubin            #+#    #+#             */
/*   Updated: 2021/10/19 14:04:50 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*s;

	s = malloc(elementCount * elementSize);
	if (!s)
	{
		return (NULL);
	}
	ft_memset(s, 0, elementCount * elementSize);
	return (s);
}
