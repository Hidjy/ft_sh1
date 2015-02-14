/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 17:45:17 by laime             #+#    #+#             */
/*   Updated: 2015/02/11 17:45:18 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "minishell.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int		execute(char *bin, char **args, char **strenv)
{
	pid_t	father;

	father = fork();
	if (father > 0)
	{
		waitpid(father, NULL, 0);
	}
	if (father == 0)
	{
		execve(bin, args, strenv);
	}
	return (1);
}

void	print_strtab(char **strtab)
{
	char	**tmp;

	tmp = strtab;
	while (tmp != NULL && *tmp != 0)
	{
		ft_putendl(*tmp);
		tmp++;
	}
}

void	env_print(t_list *env)
{
	t_list			*tmp;
	t_list_elem		*elem;
	int				i;

	tmp = env;
	i = 0;
	while (tmp != NULL)
	{
		elem = tmp->content;
		ft_putnbr(i);
		ft_putstr(": ");
		ft_putstr(elem->key);
		ft_putstr("=");
		ft_putendl(elem->data);
		tmp = tmp->next;
		i++;
	}
}

int		command(char *line, t_list *env)
{
	char	*command;
	char	*bin;
	char	**args;
	char	**strenv;

	if (ft_strchr(line, ' ') == NULL)
		command = ft_strdup(line);
	else
		command = ft_strsub(line, 0, ft_strchr(line, ' ') - line);
	args = ft_strsplit(line, ' ');
	strenv = env_to_str(env);
	//env_print(env);
	//print_strtab(strenv);
	bin = add_path(env, command);
	bin = command;
	if (execute(bin, args, strenv) == -1)
		ft_putendl("AAAAAAAAAAAH ERROR !!!!!");
	return (0);
}

int		main(int argc, char **argv, char **envp)
{
	char	*line;
	t_list	*env;

	(void)argc;
	(void)argv;
	env = load_env(envp);
	while (666)
	{
		ft_putstr("$> ");
		get_next_line(0, &line);
		command(line, env);
		ft_putchar('\n');
	}
	return (0);
}
