/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:21:39 by grubin            #+#    #+#             */
/*   Updated: 2022/06/22 09:25:11 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = dst;
	if (!dst && !src)
		return (dst);
	if (dst <= src)
	{
		i = 0;
		while (i < n)
		{
			p[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i)
		{
			p[i - 1] = ((unsigned char *)src)[i - 1];
			i--;
		}
	}
	return (dst);
}

//int main() 
//{
//   char dest[] = "oldstring";
//   const char src[]  = "newstring";

//   printf("Before memmove dest = %s, src = %s\n", dest, src);
//   memmove(dest, src, 9);
//   printf("After memmove dest = %s, src = %s\n", dest, src);

//   return(0);
//}
