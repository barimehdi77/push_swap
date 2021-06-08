/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:21:35 by mbari             #+#    #+#             */
/*   Updated: 2021/06/01 17:22:59 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_store(char *str, int int_size, int n)
{
	int	i;

	if (n > 0)
		i = 1;
	else
		i = 0;
	str[int_size] = '\0';
	while (i <= --int_size)
	{
		str[int_size] = n % 10 + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int				i;
	char			*str;
	int				int_size;

	i = 0;
	int_size = ft_intsize(n);
	str = (char *)malloc(sizeof(char) * int_size + 1);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n <= 0)
		int_size += 1;
	if (!str)
		return (NULL);
	if (n <= 0)
	{
		i = 1;
		if (n == 0)
			str[0] = '0';
		else
			str[0] = '-';
		n = -n;
	}
	ft_store(str, int_size, n);
	return (str);
}
