/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:32:37 by oabdalha          #+#    #+#             */
/*   Updated: 2018/01/25 05:55:19 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#define OBJINFO(obj,f1,f2,rgb)({obj->normal=f1;obj->clr=rgb;obj->inter=f2;})

static int g_flag = 0;

void		getobject(int type, t_union u, t_rt *rt)
{
	t_obj	*obj;

	obj = (t_obj*)malloc(sizeof(t_obj));
	obj->type = type;
	obj->u = u;
	if (type == 1)
		OBJINFO(obj, &sphere_norm, &findintersphere, u.sphere.clr);
	else if (type == 2)
		OBJINFO(obj, &plane_norm, &findinterplane, u.plane.clr);
	else if (type == 3)
		OBJINFO(obj, &cone_norm, &findintercone, u.cone.clr);
	else if (type == 4)
		OBJINFO(obj, &cylinder_norm, &findintercylinder, u.cylinder.clr);
	else if (type == 5)
		OBJINFO(obj, &cube_norm, &findintercube, u.cube.clr);
	obj->reflect = (type == 2 || type == 1) ? 0 : 1;
	obj->ior = (type == 1) ? 1.50 : 1.0;
	obj->refract = (type == 1) ? 1 : 0;
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
	(g_flag != 3) ? rt_error(2) : 0;
	rt->cam.dir = vdiff(rt->cam.pos, rt->cam.look_at);
	rt->cam.dir = normalize(invert(rt->cam.dir));
	rt->cam.right = vcross(rt->cam.dir.x == 0.0 && rt->cam.dir.z == 0.0 ?
			(t_vect){1, 0, 0} : (t_vect){0, 1, 0}, rt->cam.dir);
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
