/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soluna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:40:18 by soluna            #+#    #+#             */
/*   Updated: 2024/02/11 18:10:34 by soluna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//convierte una cadena a su valor numerico.
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}
/*#include <stdio.h>
int	main()
{
	char	*str = "-123";
	char	result = ft_atoi(str);

	printf("%d\n", result);
}*/
