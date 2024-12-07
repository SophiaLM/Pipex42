/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soluna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:36:58 by soluna            #+#    #+#             */
/*   Updated: 2023/11/28 06:37:01 by soluna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Bzero pero con cualquier caracter.
#include "libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	char	*destino;
	size_t	i;

	destino = (char *)dest;
	i = 0;
	if (count == 0)
		return (dest);
	while (count--)
		destino[i++] = c;
	return (dest);
}
/*#include <stdio.h>
int	main()
{
	char	str[10] = "Hola mundo";
	char	*result = ft_memset(str, 'z', 4);

	printf("%s\n", result);
	return (0);
}*/
