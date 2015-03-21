/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 18:45:34 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 18:45:36 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	rm(void *content, size_t size)
{
	(void)size;
	free(content);
}

void	ft_lstdelnode(t_list **lst)
{
	if ((*lst)->next != NULL)
	{
		(*lst)->content = NULL;
		(*lst)->content = (*lst)->next->content;
		(*lst)->content_size = (*lst)->next->content_size;
		(*lst)->next = (*lst)->next->next;
	}
	else
		(*lst)->content = NULL;
}
