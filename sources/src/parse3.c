/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:32:37 by oabdalha          #+#    #+#             */
/*   Updated: 2018/01/20 21:20:41 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#define LEN u.cube.len

static int g_flag = 0;

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

	g_flag = 0;
	while (get_next_line(rt->fd, &line) > 0)
	{
		if (ft_strstr(line, "origin") && ++g_flag)
			u.cube.pos = getxyz(line);
		else if (ft_strstr(line, "color") && ++g_flag)
			u.cube.clr = getcolor(line);
		else if (ft_strstr(line, "length") && ++g_flag)
			u.cube.len = ft_atod(ft_strchr(line, '(') + 1);
		else if (ft_strrchr(line, '}') && ++g_flag)
		{
			ft_strdel(&line);
			break ;
		}
		else
			rt_error(2);
		ft_strdel(&line);
	}
	(g_flag != 4) ? rt_error(2) : 0;
	u.cube.min = vdiff(u.cube.pos, (t_vect){LEN, LEN, LEN});
	u.cube.max = vadd(u.cube.pos, (t_vect){LEN, LEN, LEN});
	return (u);
}
