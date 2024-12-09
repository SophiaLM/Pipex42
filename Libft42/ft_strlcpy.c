/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soluna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:37:51 by soluna            #+#    #+#             */
/*   Updated: 2024/01/14 16:55:05 by soluna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//copia cadenas de manera segura, sin desbordamiento de buffer.
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(src);
	if (size < 1)
		return (len);
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
/*#include <stdio.h>
int	main()
{
	char	dst[10];
	const char	*src = "Hello my people";
	size_t	result = ft_strlcpy(dst, src, 10);

	printf("%ld\n", result);
}*/
