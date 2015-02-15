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
#include <sys/wait.h>

int		execute(char *bin, char **args, t_list *env)
{
	pid_t	father;
	char	**strenv;

	father = fork();
	if (father > 0)
	{
		waitpid(father, NULL, 0);
	}
	if (father == 0)
	{
		strenv = env_to_str(env);/*ho putin con, ca fuit fada!!*/
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

int		command(char *line, t_list *env)
{
	char	*bin;
	char	**args;

	line = ft_strtrim(line);
	if (!line || !line[0])
		return (0);
	args = ft_strsplit(line, ' ');
	if (!args || !args[0] || !args[0][0])
		return (0);
	if (ft_strcmp(args[0], "exit") == 0)
	{
		ft_putendl("exit");
		exit(2);
	}
	else if (ft_strcmp(args[0], "cd") == 0)
		return (c_cd(env, args));
	else if (ft_strcmp(args[0], "env") == 0)
		return (c_env(env));
	else if (ft_strcmp(args[0], "unsetenv") == 0)
		return (c_unsetenv(&env, args));
	bin = add_path(env, args[0]);
	if (bin == NULL)
		ft_putendl("CA EXISTE PAS TA MERDE");
	else if (execute(bin, args, env) == -1)
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
	}
	return (0);
}
