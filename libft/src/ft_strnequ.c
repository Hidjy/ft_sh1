/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 19:16:25 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 19:16:33 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (s1 && s2)
	{
		while (n--)
		{
			if (*s1 != *s2)
				return (0);
			s1++;
			s2++;
		}
		return (1);
	}
	return (0);
}
