/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 17:45:17 by laime             #+#    #+#             */
/*   Updated: 2015/02/11 17:45:18 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

t_list	*load_env(char **envp)
{
	t_list		*env;
	t_list_elem	elem;
	char		**tmp;
	char		*chr;

	env = NULL;
	tmp = envp;
	while (tmp != NULL && *tmp != 0)
	{
		chr = ft_strchr(*tmp, '=');
		elem.key = ft_strsub(*tmp, 0, chr - *tmp);
		elem.data = ft_strdup(chr + 1);
		ft_lstaddlast(&env, ft_lstnew(&elem, sizeof(t_list_elem)));
		tmp++;
	}
	return (env);
}

char	**env_to_str(t_list *env)
{
	t_list			*tmp;
	t_list_elem		*elem;
	char			**strenv;
	int				i;

	tmp = env;
	strenv = (char **)malloc(sizeof(char *) * (ft_lstlen(env) + 1));
	i = 0;
	while (tmp != NULL)
	{
		elem = tmp->content;
		strenv[i] = ft_strnew(ft_strlen(elem->key) + ft_strlen(elem->data) + 1);
		ft_kebab(strenv[i], elem->key, "=", elem->data, NULL);
		tmp = tmp->next;
		i++;
	}
	strenv[i] = NULL;
	return (strenv);
}

char	*get_data(t_list *env, char *key)
{
	t_list			*tmp;
	t_list_elem		*elem;

	tmp = env;
	while (tmp != NULL)
	{
		elem = tmp->content;
		if (ft_strcmp(elem->key, key) == 0)
			return(elem->data);
		tmp = tmp->next;
	}
	return (NULL);
}

char	*add_path(t_list *env, char *bin)
{
	char	*path;
	char	**paths;

	path = get_data(env, "PATH");
	if (path == NULL)
		return (bin);
	paths = ft_strsplit(path, ':');
	//print_strtab(paths);
	return (bin);
}
