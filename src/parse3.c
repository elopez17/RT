/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:32:37 by oabdalha          #+#    #+#             */
/*   Updated: 2018/01/16 00:24:50 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	getlight(t_rt *rt)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(rt->fd, &line) > 0)
	{
		if (rt->nlights == 0)
		{
			if ((rt->nlights = ft_atoi(ft_strchr(line, '(') + 1)) <= 0)
				rt_error(2);
			rt->light = (t_vect*)malloc(sizeof(t_vect) * rt->nlights);
			ft_strdel(&line);
			continue ;
		}
		if (ft_strrchr(line, '}'))
		{
			ft_strdel(&line);
			break ;
		}
		if (i < rt->nlights)
			rt->light[i++] = getxyz(line);
		ft_strdel(&line);
	}
	if (i != rt->nlights)
		rt_error(2);
}

t_union	getcube(t_rt *rt)
{
	char	*line;
	t_union	u;

	while (get_next_line(rt->fd, &line) > 0)
	{
		if (ft_strstr(line, "origin"))
			u.cube.pos = getxyz(line);
		else if (ft_strstr(line, "color"))
			u.cube.clr = getcolor(line);
		else if (ft_strrchr(line, '}'))
		{
			ft_strdel(&line);
			break ;
		}
		else
			rt_error(2);
		ft_strdel(&line);
	}
	u.cube.min = (t_vect){u.cube.pos.x - 1, u.cube.pos.y - 1, u.cube.pos.z - 1};
	u.cube.max = (t_vect){u.cube.pos.x + 1, u.cube.pos.y + 1, u.cube.pos.z + 1};
	return (u);
}
