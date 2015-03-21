/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 19:14:11 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 19:14:13 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strjoin(const char *s1, const char *s2)
{
	char		*dst;
	char		*ret;

	if (!s1 && s2)
		return (ft_strdup((char *)s2));
	else if (s1 && !s2)
		return (ft_strdup((char *)s1));
	else if (!s1)
		return (NULL);
	dst = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	ret = dst;
	while (*s1)
		*dst++ = *s1++;
	while (*s2)
		*dst++ = *s2++;
	*dst = 0;
	return (ret);
}
