/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soluna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:39:32 by soluna            #+#    #+#             */
/*   Updated: 2023/11/28 06:39:33 by soluna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//La función ft_memchr busca la primera aparición de un 
//carácter específico en un bloque de memoria.
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
/*#include <stdio.h>
#include <memory.h>
int	main()
{
	char	*str = "buenas tardes guapa";
	int	c = 'r';
	
	char	*result1 = memchr(str, c, 17);
	char	*result2 = ft_memchr(str, c, 17);

	printf("%s\n", result1);
	printf("%s\n", result2);
	return (0);
}*/
