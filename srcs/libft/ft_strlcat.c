/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:31:49 by mbari             #+#    #+#             */
/*   Updated: 2021/06/01 17:43:21 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ldst;
	size_t	lsrc;
	size_t	cut;
	size_t	res;

	cut = 0;
	lsrc = ft_strlen(src);
	if (!dst && !size)
		return (lsrc);
	ldst = ft_strlen(dst);
	if (size > ldst)
	{
		cut = size - ldst - 1;
		res = ldst + lsrc;
	}
	else
		res = lsrc + size;
	i = 0;
	while (i < cut && src[i])
		dst[ldst++] = src[i++];
	if (cut)
		dst[ldst] = '\0';
	return (res);
}
