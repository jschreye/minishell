/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:01:32 by grubin            #+#    #+#             */
/*   Updated: 2022/06/24 11:53:50 by grubin           ###   ########.fr       */
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
