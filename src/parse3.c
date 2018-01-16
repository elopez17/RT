/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:32:37 by oabdalha          #+#    #+#             */
/*   Updated: 2018/01/14 20:17:46 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	getlight(t_rt *rt)
{
	char	*line;
	int		i;

	i = -1;
	while (get_next_line(rt->fd, &line) > 0 && i < rt->nlights)
	{
		if (rt->nlights == 0)
		{
			rt->nlights = ft_atoi(ft_strchr(line, '(') + 1);
			rt->light = (t_vect*)malloc(sizeof(t_vect) * rt->nlights);
			ft_strdel(&line);
			continue ;
		}
		if (ft_strrchr(line, '}'))
		{
			ft_strdel(&line);
			break ;
		}
		rt->light[++i] = getxyz(line);
		ft_strdel(&line);
	}
}
