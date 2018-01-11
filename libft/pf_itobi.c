/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itobi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 14:24:19 by eLopez            #+#    #+#             */
/*   Updated: 2017/09/28 11:03:11 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pf_itobi(t_flags *flag, t_outp *op, va_list *ap)
{
	uintmax_t	val;
	uintmax_t	mask;
	char		*s;

	s = ft_strnew(0);
	mask = 0xf000000000000000;
	val = va_arg(*ap, uintmax_t);
	while (!(mask & val) && mask)
		mask >>= 4;
	mask &= 0x8888888888888888;
	while (mask)
	{
		if (mask & val)
			s = ft_strmer(s, ft_strdup("1"));
		else
			s = ft_strmer(s, ft_strdup("0"));
		if (flag->alter && (mask & 0x1111111111111110))
			s = ft_strmer(s, ft_strdup("-"));
		mask >>= 1;
	}
	if (val == 0)
		s = ft_strmer(s, ft_strdup("0"));
	op->str = ft_strmer(op->str, s);
}
