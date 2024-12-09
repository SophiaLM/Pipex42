/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soluna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:37:24 by soluna            #+#    #+#             */
/*   Updated: 2023/11/29 17:05:14 by soluna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//copia n bytes en la memoria, de src a dst, sin overlap.
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*destino;
	char	*origen;
	size_t	i;

	if (!src && !dest)
		return (dest);
	destino = (char *)dest;
	origen = (char *)src;
	i = 0;
	while (i++ < n)
		*destino++ = *origen++;
	return (dest);
}
/*#include <stdio.h>
int	main()
{
	char	dest[10];
	char	*src = "Hola mundo";
	char	*result = ft_memcpy(dest, src, 6);
	
	printf("%s\n", result);
	return (0);
}*/
