/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 18:50:53 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 18:50:55 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list			*ft_lstnew(const void *content, size_t content_size)
{
	t_list		*lst;

	lst = (t_list*)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	if (!content)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		lst->content = (void*)malloc(content_size);
		if (!lst->content)
			return (NULL);
		lst->content_size = content_size;
		ft_memcpy(lst->content, content, content_size);
		lst->next = NULL;
	}
	return (lst);
}
