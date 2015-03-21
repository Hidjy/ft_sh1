/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 19:15:10 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 19:15:27 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strmap(const char *s, char (*f)(char))
{
	char		*ret;
	char		*str;

	if (s && f)
	{
		str = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (!str)
			return (NULL);
		ret = str;
		while (*s && f && s)
		{
			*str = (*f)(*s);
			str++;
			s++;
		}
		*str = 0;
		return (ret);
	}
	return (NULL);
}
