/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 18:50:38 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 18:50:41 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new_list;
	t_list		*start;
	t_list		*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = (*f)(lst);
	new_list = ft_lstnew(tmp->content, tmp->content_size);
	if (!new_list)
		return (NULL);
	start = new_list;
	while (lst->next)
	{
		tmp = f(lst->next);
		ft_lstadd(&new_list->next, ft_lstnew(tmp->content, tmp->content_size));
		if (!new_list)
			return (NULL);
		lst = lst->next;
		new_list = new_list->next;
	}
	return (start);
}
