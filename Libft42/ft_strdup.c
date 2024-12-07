/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soluna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:40:37 by soluna            #+#    #+#             */
/*   Updated: 2023/11/28 06:40:40 by soluna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Retorna un puntero que es la duplica de *s en una nueva str.
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;

	str = (char *)malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, ft_strlen(s) + 1);
	return (str);
}
/*#include <stdio.h>
int	main()
{
	char	*str = "Holi mor123@";
	char	*result = ft_strdup(str);

	printf("%s\n", result);
}*/
