/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soluna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:00:46 by soluna            #+#    #+#             */
/*   Updated: 2023/11/29 17:10:07 by soluna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//pasar un numero entero a una cadena.
#include "libft.h"

int	count(int n, int j)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	if (j == -1)
		i++;
	return (i);
}

char	*mats(int n, int contador, char *re, int j)
{
	re[contador] = '\0';
	while (contador-- > 0)
	{
		re[contador] = (n % 10) + '0';
		n = n / 10;
	}
	if (j == -1)
	{
		re[0] = '-';
	}
	return (re);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		j;

	j = 1;
	if (n < 0)
	{
		j = -1;
		n *= -1;
	}
	i = count(n, j);
	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = (char *)malloc(sizeof(char) * i + 1);
	if (!result)
		return (NULL);
	return (mats(n, i, result, j));
}
/*
int     main()
{
	int	n = 123;
	char    *result = ft_itoa(n);

	printf("%s\n", result);
}
*/
