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

int		cd(char **args, t_list *env)
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
	if (ft_strcmp(command, "exit") == 0)
		exit(0);
	else if (ft_strcmp(command, "cd") == 0)
		return (cd(args, env));
	bin = add_path(env, command);
	if (bin == NULL)
		ft_putendl("CA EXISTE PAS TA MERDE");
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
		//ft_putchar('\n');
	}
	return (0);
}
