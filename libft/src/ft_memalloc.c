/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 18:57:01 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 18:57:04 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			*ft_memalloc(size_t size)
{
	void		*ptr;

	ptr = (void*)malloc(sizeof(void) * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size);
	return ((void*)ptr);
}
