/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:30:47 by grubin            #+#    #+#             */
/*   Updated: 2021/11/01 15:28:39 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	i_s1;
	size_t	i_s2;

	i_s1 = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i_s1] != '\0' && i_s1 < len)
	{
		i_s2 = 0;
		while (s1[i_s1] != s2[i_s2] && s1[i_s1] != '\0')
			i_s1++;
		if (s1[i_s1] == '\0')
			return (NULL);
		i = i_s1;
		while ((s1[i] == s2[i_s2] || s2[i_s2] == '\0') && i++ <= len)
			if (s2[i_s2++] == '\0')
				return ((char *)&s1[i_s1]);
		if (i > len)
			return (NULL);
		i_s1++;
	}
	return (NULL);
}
