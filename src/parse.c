/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:32:37 by oabdalha          #+#    #+#             */
/*   Updated: 2018/01/20 01:08:06 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static int g_flag = 0;

void		getobject(int type, t_union u, t_rt *rt)
{
	t_obj	*obj;

	obj = (t_obj*)malloc(sizeof(t_obj));
	obj->type = type;
	obj->u = u;
	obj->shine = (type == 2) ? 0 : 1;
	obj->spec = 0.3;
	obj->diff = 0.6;
	obj->m = 4;
	obj->next = rt->obj;
	rt->obj = obj;
}

t_vect		getxyz(const char *line)
{
	t_vect	vect;

	vect = (t_vect){0, 0, 0};
	if ((line = ft_strrchr(line, '(')) == NULL)
		rt_error(2);
	vect.x = ft_atod(++line);
	if ((line = ft_strchr(line, ',')) == NULL)
		rt_error(2);
	vect.y = ft_atod(++line);
	if ((line = ft_strchr(line, ',')) == NULL)
		rt_error(2);
	vect.z = ft_atod(++line);
	return (vect);
}

void		getcam(t_rt *rt)
{
	char	*line;

	g_flag = 0;
	while (get_next_line(rt->fd, &line) > 0)
	{
		if (ft_strstr(line, "origin") && ++g_flag)
			rt->cam.pos = getxyz(line);
		else if (ft_strstr(line, "direction") && ++g_flag)
			rt->cam.look_at = getxyz(line);
		else if (ft_strrchr(line, '}') && ++g_flag)
		{
			ft_strdel(&line);
			break ;
		}
		else
			rt_error(2);
		ft_strdel(&line);
	}
	if (g_flag != 3)
		rt_error(2);
	rt->cam.dir = vdiff(rt->cam.pos, rt->cam.look_at);
	rt->cam.dir = normalize(invert(rt->cam.dir));
	rt->cam.right = vcross((t_vect){0, 1, 0}, rt->cam.dir);
	rt->cam.right = normalize(rt->cam.right);
	rt->cam.down = vcross(rt->cam.right, rt->cam.dir);
}

static int	non_object(t_rt *rt, char **line)
{
	if (ft_strstr(*line, "scene") || ft_strchr(*line, '}'))
	{
		ft_strdel(line);
		return (1);
	}
	else if (ft_strstr(*line, "camera"))
	{
		getcam(rt);
		ft_strdel(line);
		return (1);
	}
	else if (ft_strstr(*line, "light"))
	{
		getlight(rt);
		ft_strdel(line);
		return (1);
	}
	return (0);
}

void		parsefile(t_rt *rt)
{
	char	*line;
	int		flag;

	flag = 0;
	while (get_next_line(rt->fd, &line) > 0)
	{
		if (non_object(rt, &line) && ++flag)
			continue ;
		if (ft_strstr(line, "sphere"))
			getobject(1, getsphere(rt), rt);
		else if (ft_strstr(line, "plane"))
			getobject(2, getplane(rt), rt);
		else if (ft_strstr(line, "cone"))
			getobject(3, getcone(rt), rt);
		else if (ft_strstr(line, "cylinder"))
			getobject(4, getcylinder(rt), rt);
		else if (ft_strstr(line, "cube"))
			getobject(5, getcube(rt), rt);
		else
			rt_error(2);
		ft_strdel(&line);
		++rt->nodes;
	}
	if (flag != 4)
		rt_error(2);
}
