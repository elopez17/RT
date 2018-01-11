/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 13:57:46 by elopez            #+#    #+#             */
/*   Updated: 2017/08/01 13:58:42 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 50

typedef struct	s_fd
{
	char		*buf;
	int			fd;
	int			i;
	int			nl;
	int			bytes;
	struct s_fd	*next;

}				t_fd;
int				get_next_line(const int fd, char **line);
#endif
