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

void	execute(char *bin, char *args[], char *strenv[])
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
}

int		command(char *line)
{
	char	*command;
	char	**args;

	if (ft_strchr(line, ' ') == NULL)
		command = ft_strdup(line);
	else
		command = ft_strsub(line, 0, ft_strchr(line, ' ') - line);
	args = ft_strsplit(line, ' ');
	execute(command, args, NULL);
	return (0);
}

int		main()
{
	char	*line;
	t_list	*env;
	char	**strenv;

	(void)strenv;
	(void)env;
	while (666)
	{
		ft_putstr("$> ");
		get_next_line(0, &line);
		command(line);
		ft_putendl("");
	}
	return (0);
}
