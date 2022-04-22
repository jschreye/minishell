/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 09:37:52 by grubin            #+#    #+#             */
/*   Updated: 2021/11/01 13:47:26 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*debut;

	debut = s;
	while (*s != '\0')
	{
		s++;
	}
	while (s != debut - 1)
	{
		if ((char)c == *s)
		{
			return ((char *)s);
		}
		s--;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return (0);
}

/*int main () 
{
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;

   ret = ft_strrchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, ret);

   return(0);
}*/
