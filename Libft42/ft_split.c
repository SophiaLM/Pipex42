/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soluna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:41:34 by soluna            #+#    #+#             */
/*   Updated: 2023/11/29 18:03:26 by soluna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//te divide una cadena en subcadenas segun el delimitador
//y las coloca dentro de una matriz;
#include "libft.h"

size_t	count_word(char	*str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str != c && *str)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

size_t	len_word(char *s, char c, size_t start)
{
	size_t	i;

	i = 0;
	while (s[start] && s[start] != c)
	{
		i++;
		start++;
	}
	return (i);
}

void	free_array(char **s1)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		free(s1[i]);
		i++;
	}
	free(s1);
}

char	**divisor(char *str1, char c, char **array, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		while (str1[j] && str1[j] == c)
			j++;
		array[i] = ft_substr(str1, j, len_word(str1, c, j));
		if (!array[i])
		{
			free_array(array);
			return (NULL);
		}
		while (str1[j] && str1[j] != c)
			j++;
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**array;

	if (!s)
		return (NULL);
	words = count_word((char *)s, c);
	array = (char **)malloc((words + 1) * (sizeof(char *)));
	if (!array)
		return (NULL);
	array = divisor((char *)s, c, array, words);
	return (array);
}

/*int	main()
{
	int	i;
	char	*s = "Hola mundo Adios Mundo ";
	char	c = ' ';
	char	**result = ft_split(s, c);

	i = 0;
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	return (0);
}*/
