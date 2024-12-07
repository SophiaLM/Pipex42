/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soluna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:41:01 by soluna            #+#    #+#             */
/*   Updated: 2023/11/29 17:06:33 by soluna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//un strlcat maloceada 
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;
	int		g;

	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	g = 0;
	while (s1[i] || s2[j])
	{
		while (s1[i])
			s3[g++] = s1[i++];
		while (s2[j])
			s3[g++] = s2[j++];
	}
	s3[g] = '\0';
	return (s3);
}
/*#include <stdio.h>
int	main()
{
	char	*s1 = "Hola ";
	char	*s2 = "Mundo";
	char	*result = ft_strjoin(s1, s2);

	printf("%s\n", result);
}*/
