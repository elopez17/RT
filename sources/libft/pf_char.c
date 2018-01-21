/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 13:06:26 by elopez            #+#    #+#             */
/*   Updated: 2017/09/27 16:11:16 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	null_input(t_flags *flag, t_outp *op, char c)
{
	char *tmp;

	op->wlen += write(1, op->str, ft_strlen(op->str));
	ft_strdel(&(op->str));
	op->str = ft_strdup("");
	if (flag->width-- > 1)
	{
		if (flag->zero)
			op->wlen += write(1, (tmp = MAKES('0', flag->width)), flag->width);
		else if (!flag->left_adj)
			op->wlen += write(1, (tmp = MAKES(' ', flag->width)), flag->width);
		op->wlen += write(1, &c, 1);
		if (flag->left_adj)
			op->wlen += write(1, (tmp = MAKES(' ', flag->width)), flag->width);
		ft_strdel(&tmp);
		return ;
	}
	op->wlen += write(1, &c, 1);
}

void		pf_char(t_flags *flag, t_outp *op, va_list *ap)
{
	char	c;

	if (flag->l)
	{
		pf_wint_t(flag, op, ap);
		return ;
	}
	if (!(c = va_arg(*ap, int)))
	{
		null_input(flag, op, c);
		return ;
	}
	if (flag->width-- > 1)
	{
		if (flag->zero)
			op->str = ft_strmer(op->str, MAKES('0', flag->width));
		else if (!flag->left_adj)
			op->str = ft_strmer(op->str, MAKES(' ', flag->width));
		op->str = ft_strmer(op->str, MAKES(c, 1));
		if (flag->left_adj)
			op->str = ft_strmer(op->str, MAKES(' ', flag->width));
		return ;
	}
	op->str = ft_strmer(op->str, MAKES(c, 1));
}
