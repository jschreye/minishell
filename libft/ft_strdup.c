/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:01:32 by grubin            #+#    #+#             */
/*   Updated: 2021/10/22 09:26:58 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *source)
{
	char	*str;
	char	*p;
	int		i;

	i = 0;
	while (source[i])
	{
		i++;
	}
	str = (char *)malloc(i + 1);
	if (str == NULL)
		return (NULL);
	p = str;
	while (*source)
	{
		*p++ = *(unsigned char *)source++;
	}
	*p = '\0';
	return (str);
}
