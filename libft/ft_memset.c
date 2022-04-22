/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 09:24:56 by grubin            #+#    #+#             */
/*   Updated: 2021/11/18 08:31:15 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int character, size_t number)
{
	unsigned char	*str2;

	str2 = (unsigned char *) str;
	while (number-- > 0)
	{
		*str2++ = character;
	}
	return (str);
}

//int main()
//{
//    char str[50] = "Aticleworld is a programming Blog.";
//    printf("\nBefore memset(): %s\n\n", str);
// Fill 6 characters starting from str[11] with '*'
//    ft_memset(str + 11, '*', 6);
//    printf("After memset(): %s\n\n", str);
//    return 0;
//}
