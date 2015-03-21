/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 18:40:24 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 18:40:26 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		size(int i)
{
	size_t		sz;

	sz = 0;
	while (i /= 10)
		sz++;
	return (sz + 1);
}

char			*ft_itoa(int n)
{
	size_t		sz;
	char		*dst;
	char		*ret;

	sz = size(n);
	dst = (char*)malloc(sizeof(char) * sz + (n < 0 ? 1 : 0) + 1);
	if (!dst)
		return (NULL);
	ret = dst;
	if (n == -2147483648)
		return (ft_strcpy(dst, "-2147483648"));
	if (n < 0)
	{
		*dst++ = '-';
		n = -n;
	}
	dst += sz - 1;
	*(dst + 1) = 0;
	while (sz--)
	{
		*dst-- = (char)(n % 10 + '0');
		n /= 10;
	}
	return (ret);
}
