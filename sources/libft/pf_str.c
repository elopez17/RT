/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 13:33:29 by elopez            #+#    #+#             */
/*   Updated: 2017/09/27 03:24:47 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_width(t_flags *flag, t_outp *op, char *s, int slen)
{
	int len;

	len = flag->width - slen;
	if (flag->zero)
		op->str = ft_strmer(op->str, MAKES('0', len));
	else if (!flag->left_adj)
		op->str = ft_strmer(op->str, MAKES(' ', len));
	op->str = ft_strmer(op->str, ft_strsub(s, 0, slen));
	if (flag->left_adj)
		op->str = ft_strmer(op->str, MAKES(' ', len));
}

void		pf_str(t_flags *flag, t_outp *op, va_list *ap)
{
	char	*s;
	int		len;

	if (flag->prec_num < 0)
		flag->prec = 0;
	if (flag->l)
	{
		pf_wchar_t(flag, op, ap);
		return ;
	}
	if (!(s = va_arg(*ap, char*)))
		s = ft_strdup("(null)");
	else
		s = ft_strdup(s);
	len = ft_strlen(s);
	if (flag->prec && flag->prec_num < len)
		len = flag->prec_num;
	if (flag->width > len)
	{
		print_width(flag, op, s, len);
		ft_strdel(&s);
		return ;
	}
	op->str = ft_strmer(op->str, ft_strsub(s, 0, len));
	ft_strdel(&s);
}
