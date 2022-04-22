/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:21:39 by grubin            #+#    #+#             */
/*   Updated: 2021/11/01 14:28:27 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!d || !s)
		return (NULL);
	if (s < d)
		while (len-- > 0)
			d[len] = s[len];
	else
		while (len-- > 0)
			*(d++) = *(s++);
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
