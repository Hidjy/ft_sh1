/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 19:11:44 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 19:11:46 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_strclr(char *s)
{
	size_t		i;

	if (s)
	{
		i = ft_strlen(s);
		ft_bzero(s, i);
	}
}
