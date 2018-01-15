/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:32:37 by elopez            #+#    #+#             */
/*   Updated: 2018/01/14 20:17:46 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

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

	while (get_next_line(rt->fd, &line) > 0)
	{
		if (ft_strstr(line, "origin"))
			u.sphere.pos = getxyz(line);
		else if (ft_strstr(line, "color"))
			u.sphere.clr = getcolor(line);
		else if (ft_strstr(line, "radius"))
			u.sphere.radius = ft_atod(ft_strchr(line, '(') + 1);
		else if (ft_strrchr(line, '}'))
		{
			ft_strdel(&line);
			break ;
		}
		else
			rt_error(2);
		ft_strdel(&line);
	}
	return (u);
}

t_union	getplane(t_rt *rt)
{
	char	*line;
	t_union	u;

	while (get_next_line(rt->fd, &line) > 0)
	{
		if (ft_strstr(line, "origin"))
			u.plane.norm = getxyz(line);
		else if (ft_strstr(line, "color"))
			u.plane.clr = getcolor(line);
		else if (ft_strstr(line, "distance"))
			u.plane.dist = ft_atod(ft_strchr(line, '(') + 1);
		else if (ft_strrchr(line, '}'))
		{
			ft_strdel(&line);
			break ;
		}
		else
			rt_error(2);
		ft_strdel(&line);
	}
	u.plane.reflect = 1;
	u.plane.refract = 0;
	return (u);
}

t_union	getcylinder(t_rt *rt)
{
	char	*line;
	t_union	u;

	while (get_next_line(rt->fd, &line) > 0)
	{
		if (ft_strstr(line, "origin"))
			u.cylinder.pos = getxyz(line);
		else if (ft_strstr(line, "direction"))
			u.cylinder.dir = getxyz(line);
		else if (ft_strstr(line, "color"))
			u.cylinder.clr = getcolor(line);
		else if (ft_strstr(line, "radius"))
			u.cylinder.radius = ft_atod(ft_strchr(line, '(') + 1);
		else if (ft_strrchr(line, '}'))
		{
			ft_strdel(&line);
			break ;
		}
		else
			rt_error(2);
		ft_strdel(&line);
	}
	return (u);
}

t_union	getcone(t_rt *rt)
{
	char	*line;
	t_union u;

	while (get_next_line(rt->fd, &line) > 0)
	{
		if (ft_strstr(line, "origin"))
			u.cone.pos = getxyz(line);
		else if (ft_strstr(line, "direction"))
			u.cone.dir = normalize(getxyz(line));
		else if (ft_strstr(line, "color"))
			u.cone.clr = getcolor(line);
		else if (ft_strstr(line, "angle"))
			u.cone.a = (M_PI / 180) * ft_atod(ft_strchr(line, '(') + 1);
		else if (ft_strrchr(line, '}'))
		{
			ft_strdel(&line);
			break ;
		}
		else
			rt_error(2);
		ft_strdel(&line);
	}
	return (u);
}
