/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soluna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:37:35 by soluna            #+#    #+#             */
/*   Updated: 2023/11/29 17:06:09 by soluna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//copia n bytes de memoria de src a dest, la memoria puede solaparse.
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*destino;
	char	*origen;

	destino = (char *)dest;
	origen = (char *)src;
	if (!src && !dest)
		return (dest);
	if (destino >= origen)
		while (n--)
			destino[n] = origen[n];
	else
		ft_memcpy(destino, origen, n);
	return (dest);
}
/*#include <stdio.h>
#include <string.h>
int	main() 
{
	char dest[20];
	char *src = "12345";

//	char *r1 = memmove(dest, src, 16);
	char *r2 = ft_memmove(dest, src, 16);

//	printf("%s\n", r1);
	printf("%s\n", r2);
	return (0);
}*/
