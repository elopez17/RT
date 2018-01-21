/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 13:09:09 by elopez            #+#    #+#             */
/*   Updated: 2017/08/01 13:11:01 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>

static t_fd	*find_data(t_fd **list, int fd)
{
	t_fd	*temp;

	temp = *list;
	while (temp != NULL)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	temp = (t_fd *)malloc(sizeof(t_fd));
	temp->buf = ft_strnew(BUFF_SIZE);
	temp->fd = fd;
	temp->i = BUFF_SIZE;
	temp->bytes = BUFF_SIZE;
	temp->nl = 0;
	if (*list)
		temp->next = (*list);
	else
		temp->next = NULL;
	*list = temp;
	return (*list);
}

static void	del_link(t_fd **list, int fd, char **str)
{
	t_fd	*temp;
	t_fd	*ptr;

	ptr = *list;
	ft_strdel(str);
	if (ptr->fd == fd)
	{
		*list = ptr->next;
		ft_strdel(&(ptr->buf));
		ft_memdel((void **)&ptr);
		return ;
	}
	while (ptr)
	{
		temp = ptr->next;
		if (temp->fd == fd)
			break ;
		ptr = ptr->next;
	}
	ptr->next = temp->next;
	ft_strdel(&(temp->buf));
	ft_memdel((void **)&temp);
}

static int	read_gets(t_fd **data, char **tmp)
{
	int	i;

	if ((*data)->i == BUFF_SIZE)
	{
		(*data)->i = 0;
		if (((*data)->bytes = read((*data)->fd, (*data)->buf, BUFF_SIZE)) < 0)
			return (-1);
	}
	i = 0;
	while (((*data)->i + i) < (*data)->bytes)
	{
		if ((*data)->buf[(*data)->i + i] == '\n')
		{
			(*data)->nl = 1;
			++i;
			break ;
		}
		++i;
	}
	(*data)->i += i;
	(*data)->bytes = (i == 0) ? 0 : (*data)->bytes;
	*tmp = ft_strsub((*data)->buf, (*data)->i - i, i - (*data)->nl);
	return ((*data)->bytes);
}

static int	make_line(t_fd **data, char **str, char **tmp, char **line)
{
	*str = ft_strncat(*str, *tmp, ft_strlen(*tmp));
	ft_strdel(tmp);
	if ((*data)->nl == 1 || ((*data)->bytes < BUFF_SIZE &&
	(*data)->bytes > 0 && (*data)->bytes == (*data)->i))
	{
		*line = *str;
		(*data)->nl = 0;
		return (1);
	}
	if ((*data)->bytes == 0 && ft_strlen(*str) > 0)
	{
		*line = *str;
		return (1);
	}
	*tmp = ft_strdup(*str);
	ft_strdel(str);
	*str = ft_strnew(BUFF_SIZE + ft_strlen(*tmp));
	*str = ft_strncat(*str, *tmp, ft_strlen(*tmp));
	ft_strdel(tmp);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_fd	*list;
	t_fd		*data;
	char		*str;
	char		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	data = find_data(&list, fd);
	str = ft_strnew(BUFF_SIZE);
	while (data->bytes > 0)
	{
		if ((read_gets(&data, &tmp)) < 0)
		{
			del_link(&list, fd, &str);
			return (-1);
		}
		if ((make_line(&data, &str, &tmp, line)) == 1)
			return (1);
	}
	del_link(&list, fd, &str);
	return (0);
}
