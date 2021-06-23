/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:34:44 by mbari             #+#    #+#             */
/*   Updated: 2021/06/06 20:06:50 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	carcts(char *str, char c)
{
	int			i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
	}
	return (i);
}

void	ft_after_equal(char *str, char **s, int i)
{
	int	j;

	j = 0;
	if (str[i] == '=' && str[i + 1] == '\0')
		s[1][0] = '\0';
	else if (str[i] == '\0')
	{
		free(s[1]);
		s[1] = NULL;
	}
	else
	{
		while (str[++i] != '\0')
			s[1][j++] = str[i];
		s[1][j] = '\0';
	}
}

char	**my_split(char *str)
{
	int		i;
	int		j;
	char	**s;

	i = 0;
	j = 0;
	s = (char **)malloc(sizeof(char **) * 2);
	s[0] = (char *)malloc(sizeof(char) * (carcts(str, '=') + 1));
	s[1] = (char *)malloc(sizeof(char)
			* ((ft_strlen(str) - carcts(str, '=')) + 1));
	while (str[i] != '=' && str[i])
	{
		s[0][i] = str[i];
		i++;
	}
	s[0][i] = '\0';
	ft_after_equal(str, s, i);
	return (s);
}
