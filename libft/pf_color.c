/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 14:24:19 by eLopez            #+#    #+#             */
/*   Updated: 2017/10/19 15:15:54 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_color	g_color[] =
{
	{'B', "\x1b[34;01m"},
	{'G', "\x1b[32;01m"},
	{'N', "\x1b[0m"},
	{'P', "\x1b[35;01m"},
	{'R', "\x1b[31;01m"},
	{'T', "\x1b[36;01m"},
	{'W', "\x1b[37;01m"},
	{'Y', "\x1b[33;01m"},
	{'b', "\x1b[34m"},
	{'g', "\x1b[32m"},
	{'n', "\x1b[0m"},
	{'p', "\x1b[35m"},
	{'r', "\x1b[31m"},
	{'t', "\x1b[36m"},
	{'w', "\x1b[37m"},
	{'y', "\x1b[33m"}
};

int		pf_color(const char **fmt, t_outp *op)
{
	int		i;
	char	c;

	c = *(*fmt + 1);
	if (c >= 'a')
		i = c > 'p' ? 11 : 7;
	else
		i = c > 'P' ? 3 : -1;
	while (++i < 16)
	{
		if (*(*fmt + 1) == g_color[i].c)
		{
			op->str = ft_strmer(op->str, ft_strdup(g_color[i].str));
			*fmt = (*fmt + 3);
			return (0);
		}
	}
	return (-1);
}
