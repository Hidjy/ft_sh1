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

t_list			*load_env(char **envp);
char			**env_to_str(t_list *env);

#endif
