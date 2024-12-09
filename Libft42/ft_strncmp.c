/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soluna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:39:09 by soluna            #+#    #+#             */
/*   Updated: 2023/11/29 17:09:02 by soluna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] && str2[i] && i < n)
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (str1[i] - str2[i]);
	}
	if (i == n)
		return (0);
	return (str1[i] - str2[i]);
}
/*#include <stdio.h>
int	main()
{
	char	*s1 = "a";
	char	*s2 = "b";

	int	result = ft_strncmp(s1, s2, 4);

	printf("%d\n", result);
	return (0);
}*/
