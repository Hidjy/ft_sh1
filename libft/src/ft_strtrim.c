/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 19:17:40 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 19:17:59 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned int		ft_sp(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char					*ft_strtrim(char *s)
{
	char				*dst;
	char				*tmp;
	t_cpl				c;

	tmp = s;
	if (!s)
		return (NULL);
	c.i = 0;
	while (ft_sp(*s++))
		c.i++;
	s -= c.i + 1;
	c.e = ft_strlen(s) - 1;
	if (!*s || c.e == c.i - 1)
	{
		free(tmp);
		return (dst = ft_strnew(1));
	}
	if (c.i != (c.e + 1))
		while (ft_sp(s[c.e]))
			c.e--;
	dst = ft_strsub(s, c.i, (c.e - c.i + 1));
	free(tmp);
	return (dst);
}
