/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 15:45:23 by laime             #+#    #+#             */
/*   Updated: 2014/12/31 17:51:46 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

typedef struct	s_list_elem
{
	char		*key;
	char		*data;
}				t_list_elem;

void			print_strtab(char **strtab);

t_list			*load_env(char **envp);
char			**env_to_str(t_list *env);
char			*get_data(t_list *env, char *key);
char			*add_path(t_list *env, char *bin);
int				c_cd(t_list *env, char **args);
int				c_env(t_list *env);
int				c_unsetenv(t_list **env, char **args);

#endif
