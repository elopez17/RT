/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_spec_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 13:42:05 by elopez            #+#    #+#             */
/*   Updated: 2017/09/27 03:28:55 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define PREC_VAL(f) (f->prec && f->prec_num > 0) ? f->prec_num : 0

static char	*itox(uintmax_t dec)
{
	char	tmp[12];
	char	*s;
	int		i;
	int		j;
	int		remain;

	i = -1;
	j = -1;
	while (dec)
	{
		remain = dec % 16;
		tmp[++i] = (remain < 10 ? 48 : 87) + remain;
		dec /= 16;
	}
	s = ft_strnew(i + 1);
	while (i >= 0)
	{
		s[++j] = tmp[i--];
	}
	return (s);
}

static void	print_prec(t_flags *flag, t_outp *op, char **s, int *len)
{
	flag->prec_num -= (*len - 2);
	op->str = ft_strmer(op->str, ft_strsub(*s, 0, 2));
	op->str = ft_strmer(op->str, MAKES('0', flag->prec_num));
	op->str = ft_strmer(op->str, ft_strsub(*s, 2, *len - 2));
	ft_strdel(s);
}

static void	print_width(t_flags *flag, t_outp *op, char **s, int *len)
{
	flag->prec_num -= *len - 2;
	flag->width = (flag->width - *len) - (PREC_VAL(flag));
	if (flag->left_adj)
	{
		op->str = ft_strmer(op->str, ft_strsub(*s, 0, 2));
		if (flag->prec && flag->prec_num > 0)
			op->str = ft_strmer(op->str, MAKES('0', flag->prec_num));
		op->str = ft_strmer(op->str, ft_strsub(*s, 2, *len - 2));
		op->str = ft_strmer(op->str, MAKES(' ', flag->width));
		return ;
	}
	if (flag->zero)
	{
		op->str = ft_strmer(op->str, ft_strsub(*s, 0, 2));
		op->str = ft_strmer(op->str, MAKES('0', flag->width));
	}
	else
		op->str = ft_strmer(op->str, MAKES(' ', flag->width));
	if (!flag->zero)
		op->str = ft_strmer(op->str, ft_strsub(*s, 0, 2));
	if (flag->prec && flag->prec_num > 0)
		op->str = ft_strmer(op->str, MAKES('0', flag->prec_num));
	op->str = ft_strmer(op->str, ft_strsub(*s, 2, *len - 2));
	ft_strdel(s);
}

void		pf_spec_p(t_flags *flag, t_outp *op, va_list *ap)
{
	uintmax_t	dec;
	int			len;
	char		*s;

	if (!(dec = va_arg(*ap, uintmax_t)))
		s = ft_strdup((flag->prec && !flag->prec_num ? "0x" : "0x0"));
	else
		s = ft_strmerge(ft_strdup("0x"), itox(dec));
	len = ft_strlen(s);
	if (flag->width > len && (!flag->prec || flag->width > flag->prec_num))
		print_width(flag, op, &s, &len);
	else if (flag->prec && flag->prec_num > len - 2)
		print_prec(flag, op, &s, &len);
	else
		op->str = ft_strmer(op->str, s);
}
