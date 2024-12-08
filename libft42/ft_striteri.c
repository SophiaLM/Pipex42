/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soluna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:12:15 by soluna            #+#    #+#             */
/*   Updated: 2023/11/29 17:12:19 by soluna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//aplica una funcion a cada caracter de un str
//esta ves trabajamos sobre la memoria.
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (s && f)
	{
		i = 0;
		while (*s)
			f(i++, s++);
	}
}
