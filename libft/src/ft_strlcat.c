/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 19:14:53 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 19:14:57 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		nsv;
	size_t		buff;
	size_t		size2;

	nsv = size;
	size2 = ft_strlen(src);
	buff = ft_strlen(dst) + size2;
	while (*dst && size)
	{
		dst++;
		size--;
	}
	if (size == 0)
		return (nsv + size2);
	while (*src && size-- > 1)
		*dst++ = *src++;
	*dst = 0;
	return (buff);
}
