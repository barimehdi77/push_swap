/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:50:42 by abdel-ke          #+#    #+#             */
/*   Updated: 2021/06/01 17:44:02 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rst;
	size_t	i;

	if (!s)
		return (NULL);
	rst = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!rst)
		return (NULL);
	i = 0;
	while (s[i])
	{
		rst[i] = f(i, s[i]);
		i++;
	}
	rst[i] = '\0';
	return (rst);
}
