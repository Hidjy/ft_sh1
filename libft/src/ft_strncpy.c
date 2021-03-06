/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 19:16:16 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 19:16:20 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	l;
	size_t	i;

	l = ft_strlen(src);
	i = 0;
	while (n > 0)
	{
		if (i > l)
			dst[i] = 0;
		else
			dst[i] = src[i];
		i++;
		n--;
	}
	return (dst);
}
