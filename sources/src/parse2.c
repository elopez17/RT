/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:32:37 by elopez            #+#    #+#             */
/*   Updated: 2018/01/22 00:03:49 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static int g_flag = 0;

t_rgb	getcolor(const char *line)
{
	t_rgb	color;

	color = (t_rgb){0, 0, 0};
	if ((line = ft_strrchr(line, '(')) == NULL)
		rt_error(2);
	color.red = ft_atoi(++line);
	if ((line = ft_strchr(line, ',')) == NULL)
		rt_error(2);
	color.green = ft_atoi(++line);
	if ((line = ft_strchr(line, ',')) == NULL)
		rt_error(2);
	color.blue = ft_atoi(++line);
	return (color);
}

t_union	getsphere(t_rt *rt)
{
	char	*line;
	t_union	u;

	g_flag = 0;
	while (get_next_line(rt->fd, &line) > 0)
	{
		if (ft_strstr(line, "origin") && ++g_flag)
			u.sphere.pos = getxyz(line);
		else if (ft_strstr(line, "color") && ++g_flag)
			u.sphere.clr = getcolor(line);
		else if (ft_strstr(line, "radius") && ++g_flag)
			u.sphere.radius = ft_atod(ft_strchr(line, '(') + 1);
		else if (ft_strrchr(line, '}') && ++g_flag)
		{
			ft_strdel(&line);
			break ;
		}
		else
			rt_error(2);
		ft_strdel(&line);
	}
	if (g_flag != 4)
		rt_error(2);
	return (u);
}

t_union	getplane(t_rt *rt)
{
	char	*line;
	t_union	u;

	g_flag = 0;
	while (get_next_line(rt->fd, &line) > 0)
	{
		if (ft_strstr(line, "origin") && ++g_flag)
			u.plane.norm = normalize(getxyz(line));
		else if (ft_strstr(line, "color") && ++g_flag)
			u.plane.clr = getcolor(line);
		else if (ft_strstr(line, "distance") && ++g_flag)
			u.plane.dist = ft_atod(ft_strchr(line, '(') + 1);
		else if (ft_strrchr(line, '}') && ++g_flag)
		{
			ft_strdel(&line);
			break ;
		}
		else
			rt_error(2);
		ft_strdel(&line);
	}
	if (g_flag != 4)
		rt_error(2);
	return (u);
}

t_union	getcylinder(t_rt *rt)
{
	char	*line;
	t_union	u;

	g_flag = 0;
	while (get_next_line(rt->fd, &line) > 0)
	{
		if (ft_strstr(line, "origin") && ++g_flag)
			u.cylinder.pos = getxyz(line);
		else if (ft_strstr(line, "direction") && ++g_flag)
			u.cylinder.dir = normalize(getxyz(line));
		else if (ft_strstr(line, "color") && ++g_flag)
			u.cylinder.clr = getcolor(line);
		else if (ft_strstr(line, "radius") && ++g_flag)
			u.cylinder.radius = ft_atod(ft_strchr(line, '(') + 1);
		else if (ft_strrchr(line, '}') && ++g_flag)
		{
			ft_strdel(&line);
			break ;
		}
		else
			rt_error(2);
		ft_strdel(&line);
	}
	(g_flag != 5) ? rt_error(2) : 0;
	return (u);
}

t_union	getcone(t_rt *rt)
{
	char	*line;
	t_union u;

	g_flag = 0;
	while (get_next_line(rt->fd, &line) > 0)
	{
		if (ft_strstr(line, "origin") && ++g_flag)
			u.cone.pos = getxyz(line);
		else if (ft_strstr(line, "direction") && ++g_flag)
			u.cone.dir = normalize(getxyz(line));
		else if (ft_strstr(line, "color") && ++g_flag)
			u.cone.clr = getcolor(line);
		else if (ft_strstr(line, "angle") && ++g_flag)
			u.cone.a = (M_PI / 180) * ft_atod(ft_strchr(line, '(') + 1);
		else if (ft_strrchr(line, '}') && ++g_flag)
		{
			ft_strdel(&line);
			break ;
		}
		else
			rt_error(2);
		ft_strdel(&line);
	}
	(g_flag != 5) ? rt_error(2) : 0;
	return (u);
}
