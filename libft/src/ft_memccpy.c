/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 18:57:10 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 18:57:19 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*strdst;
	const unsigned char	*strsrc;
	unsigned char		car;

	strdst = (unsigned char*)dst;
	strsrc = (const unsigned char*)src;
	car = (unsigned char)c;
	while (n--)
	{
		if ((*strdst++ = *strsrc++) == car)
			return (strdst);
	}
	return (NULL);
}
