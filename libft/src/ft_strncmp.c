/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 19:15:46 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 19:16:09 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (n--)
	{
		if (!*str1 && !*str2)
			return (0);
		if (*str1 != *str2)
			return ((*str1 - *str2) < 0 ? -1 : 1);
		str1++;
		str2++;
	}
	return (0);
}
