/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:24:38 by mbari             #+#    #+#             */
/*   Updated: 2021/06/01 17:45:11 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trim_start(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (set[j] != '\0')
	{
		if (set[j] == s1[i])
		{
			while (set[j] == s1[i])
				i++;
			j = -1;
		}
		j++;
	}
	return (i);
}

static int	trim_end(char const *s1, char const *set)
{
	int			s1len;
	int			j;

	j = 0;
	s1len = ft_strlen(s1) - 1;
	while (set[j])
	{
		if (set[j] == s1[s1len])
		{
			while (set[j] == s1[s1len])
				s1len--;
			j = -1;
		}
		j++;
	}
	return (s1len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	int			start;
	int			end;
	char		*s2;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	start = trim_start(s1, set);
	if (!s1[start])
		return (ft_substr(s1, 0, 0));
	end = trim_end(s1, set);
	i = (end - start) + 1;
	s2 = ft_substr(s1, start, i);
	return (s2);
}
