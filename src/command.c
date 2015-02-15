/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 17:45:17 by laime             #+#    #+#             */
/*   Updated: 2015/02/11 17:45:18 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <unistd.h>

int		c_cd(t_list *env, char **args)
{
	char	*path;
	char	*home;

	home = get_data(env, "HOME");
	if (home != NULL)
	{
		if (args != NULL && args[1] != 0 && args[1][0] == '~')
			path = ft_strjoin(home, args[1] + 1);
		else if (args != NULL && args[1] != 0)
			path = ft_strdup(args[1]);
		else
			path = ft_strdup(home);
	}
	else
	{
		if (args != NULL && args[1] != 0)
			path = ft_strdup(args[1]);
		else
		{
			ft_putendl("YAPA DE HOME");
			return (0);
		}
	}

	if (chdir(path) != 0)
	{
		ft_putstr("cd: no such directory: ");
		ft_putendl(path);
	}
	return (0);
}

int		c_env(t_list *env)
{
	t_list			*tmp;
	t_list_elem		*elem;

	tmp = env;
	while (tmp != NULL)
	{
		elem = tmp->content;
		ft_putstr(elem->key);
		ft_putstr("=");
		ft_putendl(elem->data);
		tmp = tmp->next;
	}
	return (0);
}

int		c_setenv(t_list *env, char **args)
{
	t_list			*tmp;
	t_list_elem		*elem;
	t_list_elem		new;

	tmp = env;
	if (!args[1] || !args[1][0])
		return (0);
	while (tmp != NULL)
	{
		elem = tmp->content;
		if (!ft_strcmp(elem->key, args[1]))
		{
			elem->data = args[2];
			return(0);
		}
		tmp = tmp->next;
	}
	new.key = args[1];
	new.data = args[2];
	ft_lstaddlast(&env, ft_lstnew(&new, sizeof(t_list_elem)));
	return (0);
}

int		c_unsetenv(t_list **env, char **args)
{
	t_list			**tmp;
	t_list			*last;
	t_list_elem		*elem;

	tmp = env;
	last = NULL;
	if (!args[1] || !args[1][0])
		return (0);
	while (tmp != NULL)
	{
		elem = (*tmp)->content;
		if (!ft_strcmp(elem->key, args[1]))
		{
			if (!(*tmp)->next)
				last->next = NULL;
			else
				ft_lstdelnode(tmp);
			return (0);
		}
		last = *tmp;
		*tmp = (*tmp)->next;
	}
	return (0);
}
