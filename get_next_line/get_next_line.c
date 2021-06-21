/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 23:34:15 by mbari             #+#    #+#             */
/*   Updated: 2020/01/24 19:54:54 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_line(char **str, int n, char **line, int fd)
{
	char	*temp;
	int		i;

	i = 0;
	while (str[fd][i] && str[fd][i] != '\n')
		i++;
	*line = ft_substr(str[fd], 0, i);
	if (!str[fd][i])
	{
		temp = str[fd];
		str[fd] = NULL;
		free(temp);
		return (0);
	}
	else
	{
		temp = str[fd];
		str[fd] = ft_strdup((str[fd]) + i + 1);
		free(temp);
	}
	if (!str[fd] || !*line)
		return (-1);
	if (n || (n == 0 && str[fd] != NULL))
		return (1);
	return (-1);
}

int				get_next_line(int fd, char **line)
{
	char			*buf;
	static char		*str[4864];
	char			*temp;
	int				n;

	buf = NULL;
	if (!line || fd < 0 || fd >= 4864 || BUFFER_SIZE <= 0
			|| !(buf = malloc(BUFFER_SIZE + 1)) || read(fd, buf, 0) == -1)
		return (-1);
	if (!str[fd])
		if (!(str[fd] = ft_strdup("")))
			return (-1);
	while ((n = read(fd, buf, BUFFER_SIZE)))
	{
		temp = str[fd];
		buf[n] = '\0';
		if (!(str[fd] = ft_strjoin(str[fd], buf)))
			return (-1);
		free(temp);
		if (ft_strchr(str[fd], '\n') != NULL)
			break ;
	}
	free(buf);
	return (get_line(str, n, line, fd));
}
