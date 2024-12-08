/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soluna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:40:48 by soluna            #+#    #+#             */
/*   Updated: 2023/11/28 06:40:50 by soluna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//crea una subcadena a partir de la cadena especificada.
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (len > ft_strlen(s) - start)
	{
		len = ft_strlen(s) - start;
	}
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	str = (char *)malloc(((sizeof(char) * (len + 1))));
	if (!str)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		str[i++] = s[start++];
	}
	str[i] = '\0';
	return (str);
}
/*#include <stdio.h>
int	main()
{
	char	*s = "Hola mundo";
	char	*result = ft_substr(s, 9, 10);

	printf("%s\n", result);
}*/
