/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_wint_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 00:04:22 by eLopez            #+#    #+#             */
/*   Updated: 2017/09/27 03:25:52 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int	wintlen(wint_t wi)
{
	if (wi < (MB_CUR_MAX == 1 ? 0xff : 0x7f))
		return (1);
	else if (wi <= 0x7ff)
		return (2);
	else if (wi <= 0xffff)
		return (3);
	else
		return (4);
}

static void			print_width(wint_t cval, t_flags *flag, t_outp *op, int len)
{
	char	*tmp;

	if (flag->zero)
		op->wlen += write(1, (tmp = MAKES('0', len)), len);
	else if (!flag->left_adj)
		op->wlen += write(1, (tmp = MAKES(' ', len)), len);
	op->wlen += ft_putwint(cval);
	if (flag->left_adj)
		op->wlen += write(1, (tmp = MAKES(' ', len)), len);
	ft_strdel(&tmp);
}

void				pf_wint_t(t_flags *flag, t_outp *op, va_list *ap)
{
	wint_t c;

	op->wlen += write(1, op->str, ft_strlen(op->str));
	ft_strdel(&(op->str));
	op->str = ft_strdup("");
	c = va_arg(*ap, wint_t);
	if (flag->width > wintlen(c))
	{
		print_width(c, flag, op, flag->width - wintlen(c));
		return ;
	}
	op->wlen += ft_putwint(c);
}
