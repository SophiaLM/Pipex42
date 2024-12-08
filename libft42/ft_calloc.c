/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soluna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:40:28 by soluna            #+#    #+#             */
/*   Updated: 2023/11/28 06:40:29 by soluna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Reserva un espacio de memoria
//lleno de ceros.
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	str = (void *)malloc(nmemb * size);
	if (!str)
		return (NULL);
	ft_bzero(str, nmemb * size);
	return (str);
}
/*#include <stdio.h>
#include <stdlib.h>
int	main()
{
	void	*result1 = calloc(7, 5);
	void	*result2 = ft_calloc(7, 5);

	printf("%p\n", result1);
	printf("%p\n", result2);
}*/
