/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 18:56:49 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 18:56:53 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_malloc(size_t n)
{
	void	*ret;

	if (!(ret = malloc(n)))
	{
		ft_putstr_fd("Malloc error: Program quited.", 2);
		exit (2);
	}
	return (ret);
}
