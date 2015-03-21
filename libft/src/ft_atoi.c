/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 18:37:15 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 18:37:18 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		ret;
	char	si;

	ret = 0;
	si = 1;
	while (*str == ' ' || *str == '\t' || *str == '\r'
			|| *str == '\v' || *str == '\n' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		si = (*str == '-' ? -1 : 1);
		str++;
	}
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + si * (*str - '0');
		str++;
	}
	return (ret);
}
