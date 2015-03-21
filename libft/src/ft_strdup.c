/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 19:13:43 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 19:13:45 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*dst;

	dst = (char*)malloc(ft_strlen(s1) * sizeof(char) + sizeof(char));
	if (!dst)
		return (NULL);
	return (ft_strcpy(dst, s1));
}
