/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 19:15:32 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 19:15:34 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char				*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*ret;
	size_t			l;
	unsigned int	i;

	if (s && f)
	{
		i = 0;
		l = ft_strlen(s);
		ret = (char*)malloc(sizeof(char) * (l + 1));
		if (!ret)
			return (NULL);
		while (i < l)
		{
			ret[i] = (*f)(i, *s++);
			i++;
		}
		ret[i] = 0;
		return (ret);
	}
	return (NULL);
}
