/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soluna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:40:04 by soluna            #+#    #+#             */
/*   Updated: 2023/11/28 06:40:06 by soluna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Busca un str dentro de otro mas grande si no es mayor a len
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (i + j < len && little[j]
			&& big[i + j] && big[i + j] == little[j])
		{
			if (little[j + 1] == '\0')
			{
				return ((char *)big + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str = "Hola mundo como estas";
	char *little = "como";
	//char *result =	ft_strnstr(str, little, 20);
	char *result = ft_strnstr("", "xx", 4294967295);
	printf("el puntero es : %s\n", result);
	return (0);
} */
