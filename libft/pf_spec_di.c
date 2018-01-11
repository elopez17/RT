/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_spec_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 13:33:29 by elopez            #+#    #+#             */
/*   Updated: 2017/09/29 11:05:27 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t	len_arg(t_flags *flag, va_list *ap)
{
	if (flag->l)
		return (va_arg(*ap, long));
	if (flag->hh)
		return ((signed char)va_arg(*ap, int));
	if (flag->h)
		return ((short)va_arg(*ap, int));
	if (flag->ll)
		return (va_arg(*ap, long long));
	if (flag->j)
		return (va_arg(*ap, intmax_t));
	if (flag->z)
		return (va_arg(*ap, ssize_t));
	return (va_arg(*ap, int));
}

static void		add_zeros(t_flags *flag, char **s, int *slen)
{
	char	*str;
	int		sign;
	int		zeros;

	str = ft_strnew(0);
	zeros = 0;
	if ((sign = ((*s)[0] != '+' && (*s)[0] != ' ' && (*s)[0] != '-') ? 0 : 1))
		str = ft_strmer(str, ft_strsub(*s, 0, 1));
	if (flag->prec && flag->prec_num > *slen - sign)
		zeros = flag->prec_num - (*slen - sign);
	if (flag->zero && flag->width > *slen + zeros)
		zeros += (flag->width - (*slen + zeros));
	str = ft_strmer(str, MAKES('0', zeros));
	str = ft_strmer(str, ft_strsub(*s, sign, *slen - sign));
	ft_strdel(s);
	*s = str;
	*slen += zeros;
}

void			pf_spec_di(t_flags *flag, t_outp *op, va_list *ap)
{
	intmax_t	val;
	char		*s;
	int			slen;

	flag->zero = (flag->prec == 1) ? 0 : flag->zero;
	val = len_arg(flag, ap);
	s = (!val && !HASLENGTH(flag) && (flag->prec && !flag->prec_num) &&\
			!HASFLAG(flag)) ? ft_strdup("") : ft_imttoa(val);
	if ((flag->space || flag->sign) && val >= 0)
		s = ft_strmer(ft_strdup((flag->space) ? " " : "+"), s);
	slen = ft_strlen(s);
	if (flag->prec || flag->zero)
		add_zeros(flag, &s, &slen);
	if (flag->width > slen)
	{
		if (flag->left_adj)
			s = ft_strmer(s, MAKES(' ', flag->width - slen));
		else
			s = ft_strmer(MAKES(' ', flag->width - slen), s);
	}
	op->str = ft_strmer(op->str, s);
}
