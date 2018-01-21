/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:40:34 by elopez            #+#    #+#             */
/*   Updated: 2017/09/27 14:00:06 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_analyze(va_list *ap, const char *fmt)
{
	int		ret;
	t_flags	flag;
	t_outp	op;

	ret = 0;
	op.str = ft_strcsub(fmt, '%');
	op.wlen = 0;
	while ((fmt = ft_strchr(fmt, '%')))
	{
		flag = pf_conv_flags(&fmt);
		pf_conv_width(&fmt, &flag, ap);
		pf_conv_precision(&fmt, &flag, ap);
		pf_conv_length(&fmt, &flag);
		if ((pf_conv_spec(&fmt, &flag, &op, ap)) == -2)
			break ;
		if (op.wlen > 0)
			ret += op.wlen;
		op.str = ft_strmer(op.str, ft_strcsub(++fmt, '%'));
	}
	ret += write(1, op.str, ft_strlen(op.str));
	ft_strdel(&(op.str));
	return (ret);
}

int			ft_printf(const char *fmt, ...)
{
	int		len;
	va_list	*ap;

	len = 0;
	ap = (va_list*)malloc(sizeof(va_list));
	if (fmt)
	{
		va_start(*ap, fmt);
		len = pf_analyze(ap, fmt);
		va_end(*ap);
	}
	ft_memdel((void**)&ap);
	return (len);
}
