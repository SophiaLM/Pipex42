/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soluna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:39:50 by soluna            #+#    #+#             */
/*   Updated: 2023/11/28 06:39:51 by soluna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (0);
}
/*#include <stdio.h>
#include <memory.h>
int	main()
{
	char	*s1 = "hola";
	char	*s2 = "holab";

	char	result1 = memcmp(s1, s2, 5);
	char	result2 = ft_memcmp(s1, s2, 5);

	printf("%d\n", result1);
	printf("%d\n", result2);
}*/
