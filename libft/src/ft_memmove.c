/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 19:06:07 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 19:06:14 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*strdst;
	const unsigned char		*strsrc;

	strdst = (unsigned char*)dst;
	strsrc = (const unsigned char*)src;
	if (!len)
		return (dst);
	if (strsrc < strdst)
	{
		strdst += len;
		strsrc += len;
		while (len--)
			*--strdst = *--strsrc;
	}
	else
		while (len--)
			*strdst++ = *strsrc++;
	return (dst);
}
