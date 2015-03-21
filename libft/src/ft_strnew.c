/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 19:16:38 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 19:16:41 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strnew(size_t size)
{
	char		*str;

	str = (char*)malloc(sizeof(char) * (size));
	if (!str)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
