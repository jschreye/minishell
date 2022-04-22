/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:03:16 by grubin            #+#    #+#             */
/*   Updated: 2021/11/18 09:00:30 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *str, size_t number)
{
	unsigned char	*str2;

	str2 = (unsigned char *)str;
	while (number-- > 0)
	{
		*str2++ = '\0';
	}
}

/*int main()
{
	char str[50] = "Aticleworld is a programming Blog.";
	printf("\nBefore ft_bzero(): %s\n\n", str);
	ft_bzero(str + 11, 6);
	printf("after ft_bzero(): %s\n\n", str);
	return (0);
}*/
