/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soluna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:38:02 by soluna            #+#    #+#             */
/*   Updated: 2024/01/26 18:57:50 by soluna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//concatena cadenas de manera segurai. Retorna la longitud de len + src.
#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	lendest;
	unsigned int	lensrc;
	unsigned int	i;

	i = 0;
	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	if (size <= lendest)
		lensrc += size;
	else
		lensrc += lendest;
	while (src[i] && lendest + 1 < size)
	{
		dest[lendest++] = src[i++];
	}
	dest[lendest] = '\0';
	return (lensrc);
}
/*#include <stdio.h>
int	main()
{
	char	dest[7] = "Hola";
	char	src[5] = "Mundo";

	printf("%d\n", ft_strlcat(dest, src, 7));
	printf("%s\n", dest);
	return (0);
}*/
