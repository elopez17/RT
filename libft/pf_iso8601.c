/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_iso8601.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:50:50 by eLopez            #+#    #+#             */
/*   Updated: 2017/09/27 17:04:02 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_iso8601(t_flags *flag, t_outp *op, va_list *ap)
{
	int		date;
	int		i;
	char	*s;

	if (flag)
		;
	i = 0;
	s = ft_strnew(0);
	while (++i <= 3)
	{
		date = va_arg(*ap, int);
		if (date < 10)
			s = ft_strmer(s, ft_strdup("0"));
		s = ft_strmer(s, ft_itoa(date));
		if (i <= 2)
			s = ft_strmer(s, ft_strdup("-"));
	}
	op->str = ft_strmer(op->str, s);
}
