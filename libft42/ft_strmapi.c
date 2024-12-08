/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soluna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:42:09 by soluna            #+#    #+#             */
/*   Updated: 2023/11/29 17:07:14 by soluna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//aplica una funcion a cada caracter de un str.
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*len;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	len = (char *)malloc(ft_strlen(s) + 1);
	if (!len)
		return (NULL);
	while (s[i])
	{
		len[i] = f(i, s[i]);
		i++;
	}
	len[i] = '\0';
	return (len);
}
