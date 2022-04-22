/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:37:58 by grubin            #+#    #+#             */
/*   Updated: 2021/11/01 13:53:28 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

//int main()
//{
//	char	string[23] = "caucou";
//	char	string2[23] = "coucoutoi";
//	char	n;
//	int		result;

//	n = 5;
//	result = ft_strncmp(string, string2, n);
//	printf("%d\n", result);
//	printf("%d", strncmp(string, string2, n));
//}
