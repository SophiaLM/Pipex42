/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soluna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:41:20 by soluna            #+#    #+#             */
/*   Updated: 2023/11/29 20:41:01 by soluna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//elimina los caracteres inciales y finales del str 
//que set diga.
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1);
	while (j && ft_strchr(set, s1 [j]))
		j--;
	return (ft_substr(s1, i, (j - i + 1)));
}

/*
#include <stdio.h>
int	main()
{
	char	*result = ft_strtrim("", "");

	printf("%s\n", result);
}
*/
