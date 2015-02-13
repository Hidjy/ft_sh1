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

#include "libft/libft.h"

t_list	*load_env(char **envp)
{
	t_list		*env;
	t_list_elem	elem;
	char		*key;
	char		*data;
	char		*tmp;
	char		*chr;

	env = NULL;
	tmp = envp;
	while (envp != NULL)
	{
		chr = ft_strchr(*tmp, '=');
		elem.key = ft_strsub(*tmp, 0, chr - *tmp);
		elem.data = ft_strsub(chr + 1);
		env = ft_lstadd(&env, ft_lstnew(elem, sizeof(t_list_elem)))
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
	strenv = (char **)malloc(sizeof(char *) * ft_lstlen(env));
	i = 0;
	while (tmp != NULL)
	{
		elem = tmp->data;
		strenv[i] = (char *)malloc(ft_strlen(elem->key)
			+ ft_strlen(elem->data) + 2);
		ft_kebab(strenv + i, elem->key, "=", elem->data, NULL)
		tmp = tmp->next;
	}
	return (strenv);
}

char	*get_env(t_list *env, char *key)
{

}

char	*add_path(char **paths, char *command)
{

}
