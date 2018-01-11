/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:32:37 by elopez            #+#    #+#             */
/*   Updated: 2017/01/08 13:37:50 by oabdalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_obj		getobject(int type, t_union u)
{
	t_obj	obj;

	obj.type = type;
	obj.u = u;
	obj.next = NULL;
	return (obj);
}

t_vect		getxyz(const char *line)
{
	t_vect	vect;

	vect = (t_vect){0, 0, 0};
	if ((line = ft_strrchr(line, '(')) == NULL)
		rtv1_error(2);
	vect.x = ft_atod(++line);
	if ((line = ft_strchr(line, ',')) == NULL)
		rtv1_error(2);
	vect.y = ft_atod(++line);
	if ((line = ft_strchr(line, ',')) == NULL)
		rtv1_error(2);
	vect.z = ft_atod(++line);
	return (vect);
}

void		getcam(t_rtv1 *rt)
{
	char	*line;

	while (get_next_line(rt->fd, &line) > 0)
	{
		if (ft_strstr(line, "origin"))
			rt->cam.pos = getxyz(line);
		else if (ft_strstr(line, "direction"))
			rt->cam.look_at = getxyz(line);
		else if (ft_strrchr(line, '}'))
		{
			ft_strdel(&line);
			break ;
		}
		else
			rtv1_error(2);
		ft_strdel(&line);
	}
	rt->cam.dir = vdiff(rt->cam.pos, rt->cam.look_at);
	rt->cam.dir = normalize(invert(rt->cam.dir));
	rt->cam.right = vcross((t_vect){0, 1, 0}, rt->cam.dir);
	rt->cam.right = normalize(rt->cam.right);
	rt->cam.down = vcross(rt->cam.right, rt->cam.dir);
}

static int	non_object(t_rtv1 *rt, char **line)
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
	return (0);
}

void		parsefile(t_rtv1 *rt)
{
	char	*line;
	t_obj	*obj;

	while (get_next_line(rt->fd, &line) > 0)
	{
		if (non_object(rt, &line))
			continue ;
		obj = (t_obj*)ft_memalloc(sizeof(t_obj));
		if (ft_strstr(line, "sphere"))
			*obj = getobject(1, getsphere(rt));
		else if (ft_strstr(line, "plane"))
			*obj = getobject(2, getplane(rt));
		else if (ft_strstr(line, "cone"))
			*obj = getobject(3, getcone(rt));
		else if (ft_strstr(line, "cylinder"))
			*obj = getobject(4, getcylinder(rt));
		else
			rtv1_error(2);
		ft_strdel(&line);
		obj->next = (rt->obj != NULL) ? rt->obj : NULL;
		rt->obj = obj;
		++rt->nodes;
	}
}
