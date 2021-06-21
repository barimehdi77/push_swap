/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 23:34:36 by mbari             #+#    #+#             */
/*   Updated: 2020/01/23 23:47:42 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t				ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char				*ft_strdup(const char *s1)
{
	size_t		i;
	char		*t;

	i = ft_strlen(s1);
	if (!(t = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		t[i] = s1[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		i;

	if (!s)
		return (NULL);
	dest = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	while (len--)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	return (dest);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char				*ft_strchr(const char *s, int c)
{
	size_t				i;
	size_t				n;
	char				*str;

	str = (char *)s;
	i = 0;
	n = ft_strlen(str);
	while (i <= n)
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}
