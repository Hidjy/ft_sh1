/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kebab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 18:40:49 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 18:40:52 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

void		ft_kebab(char *buff, const char *first, ...)
{
	int			i;
	int			j;
	const char	*next;
	va_list		lst;

	va_start(lst, first);
	next = first;
	i = 0;
	while (next != NULL)
	{
		j = 0;
		while (next[j] != 0)
		{
			buff[i] = next[j];
			i++;
			j++;
		}
		next = va_arg(lst, char*);
	}
	va_end(lst);
	buff[i] = 0;
}
