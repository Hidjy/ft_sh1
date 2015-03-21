/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsimpledel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 18:51:17 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 18:51:20 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsimpledel(t_list **alst)
{
	if (*alst)
	{
		ft_lstsimpledel(&(*alst)->next);
		ft_lstsimpledelone(alst);
	}
}
