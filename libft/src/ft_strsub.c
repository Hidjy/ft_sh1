/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 19:17:30 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 19:17:56 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char		*dst;
	char		*ret;

	if (!len)
		return ("");
	if (!s || !*s)
		return (NULL);
	dst = (char*)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	ret = dst;
	while (len--)
		*dst++ = s[start++];
	*dst = 0;
	return (ret);
}
