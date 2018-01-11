/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_wchar_t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 13:39:32 by elopez            #+#    #+#             */
/*   Updated: 2017/10/19 15:42:24 by elopez           ###   ########.fr       */
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

static void			print_width(t_flags *flag, wchar_t *s, int slen)
{
	char	*tmp;
	int		len;

	len = flag->width - slen;
	if (flag->zero)
		write(1, (tmp = MAKES('0', len)), len);
	else if (!flag->left_adj)
		write(1, (tmp = MAKES(' ', len)), len);
	while (slen >= wintlen(*s) && *s)
		slen -= ft_putwint(*s++);
	if (flag->left_adj)
		write(1, (tmp = MAKES(' ', len)), len);
	ft_strdel(&tmp);
}

void				pf_wchar_t(t_flags *flag, t_outp *op, va_list *ap)
{
	wchar_t	*s;
	int		len;

	op->wlen += write(1, op->str, ft_strlen(op->str));
	ft_strdel(&(op->str));
	op->str = ft_strdup("");
	if (!(s = va_arg(*ap, wchar_t*)))
	{
		op->wlen += write(1, "(null)", 6);
		return ;
	}
	if (flag->prec_num < (len = ft_wcharlen(s)) && flag->prec)
	{
		len = flag->prec_num - (flag->prec_num % wintlen(*s));
		flag->prec_num = len;
	}
	op->wlen += flag->width > len ? flag->width : len;
	if (flag->width > len)
		print_width(flag, s, len);
	else if (flag->prec && flag->prec_num == len)
		while (flag->prec_num && *s)
			flag->prec_num -= ft_putwint(*s++);
	else
		while (len && *s)
			len -= ft_putwint(*s++);
}
