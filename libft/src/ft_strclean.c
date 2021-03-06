/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 19:11:35 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 19:11:37 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned int		ft_sp(char c)
{
	return (c == ' ' || c == '\t');
}

static int				ctn(char *str)
{
	int		cnt;

	cnt = 0;
	while (*str)
	{
		if (!ft_sp(*str))
			cnt++, str++;
		else if (ft_sp(*str) && !ft_sp(*(str + 1)))
			cnt++, str++;
		else if (ft_sp(*str))
			str++;
	}
	cnt++;
	return (cnt);
}

char					*ft_strclean(char *str)
{
	char	*tmp;
	char	*ret;
	char	*tmp_ret;

	ret = (char*)malloc(sizeof(char) * ctn(str));
	tmp = str;
	tmp_ret = ret;
	while (*tmp)
	{
		if (!ft_sp(*tmp))
			*tmp_ret++ = *tmp++;
		else if (ft_sp(*tmp) && !ft_sp(*(tmp + 1)))
		{
			*tmp_ret = ' ';
			tmp++;
			tmp_ret++;
		}
		else if (ft_sp(*tmp))
			tmp++;
	}
	*tmp_ret = 0;
	ret = ft_strtrim(ret);
	return (ret);
}
