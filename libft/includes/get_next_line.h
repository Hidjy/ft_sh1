/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 15:33:37 by laime             #+#    #+#             */
/*   Updated: 2015/03/21 15:33:39 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 8

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int				get_next_line(int fd, char **line);

typedef struct	s_gnl
{
	t_list		*lst;
	char		*pos;
}				t_gnl;

#endif
