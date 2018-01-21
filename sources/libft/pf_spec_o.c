/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_spec_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 13:42:05 by elopez            #+#    #+#             */
/*   Updated: 2017/10/19 15:17:52 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	len_arg(t_flags *flag, va_list *ap)
{
	if (flag->l)
		return (va_arg(*ap, unsigned long));
	if (flag->hh)
		return ((unsigned char)va_arg(*ap, unsigned int));
	if (flag->h)
		return ((unsigned short)va_arg(*ap, unsigned int));
	if (flag->ll)
		return (va_arg(*ap, unsigned long long));
	if (flag->j)
		return (va_arg(*ap, uintmax_t));
	if (flag->z)
		return (va_arg(*ap, size_t));
	return (va_arg(*ap, unsigned int));
}

static char			*itoo(uintmax_t dec)
{
	char	*tmp;
	char	*s;
	int		i;
	int		j;
	int		remain;

	i = -1;
	j = -1;
	tmp = ft_strnew(20);
	remain = 0;
	while (dec)
	{
		remain = dec % 8;
		tmp[++i] = 48 + remain;
		dec /= 8;
	}
	s = ft_strnew(i + 1);
	while (i >= 0)
		s[++j] = tmp[i--];
	ft_strdel(&tmp);
	return (s);
}

static char			*add_zeros(t_flags *flag, int *len)
{
	char	*str;
	int		zeros;

	zeros = 0;
	if (flag->prec && flag->prec_num > *len + flag->alter)
	{
		zeros = flag->prec_num - (*len + flag->alter);
		*len += zeros;
	}
	*len += (flag->alter ? 1 : 0);
	if (flag->zero)
	{
		flag->width -= *len;
		if (flag->width > zeros)
		{
			zeros = flag->width;
			*len += zeros;
		}
	}
	ft_memset((str = ft_strnew(zeros)), '0', zeros);
	flag->alter ? str = ft_strmer(ft_strdup("0"), str) : NULL;
	return (str);
}

static void			print_width(t_flags *flag, t_outp *op, char *s, int *ret)
{
	flag->width -= *ret;
	if (flag->left_adj)
	{
		op->str = ft_strmer(op->str, s);
		if (flag->width > 0)
			op->str = ft_strmer(op->str, MAKES(' ', flag->width));
		return ;
	}
	if (flag->width > 0)
		op->str = ft_strmer(op->str, MAKES(' ', flag->width));
	op->str = ft_strmer(op->str, s);
}

void				pf_spec_o(t_flags *flag, t_outp *op, va_list *ap)
{
	uintmax_t	dec;
	int			len;
	char		*s;

	dec = 0;
	if ((dec = len_arg(flag, ap)))
		s = itoo(dec);
	else
		s = ft_strdup(((flag->prec && !flag->prec_num) || flag->alter ?\
					"" : "0"));
	if ((len = ft_strlen(s)) || flag->alter)
		s = ft_strmer(add_zeros(flag, &len), s);
	if (flag->width > len)
		print_width(flag, op, s, &len);
	else
		op->str = ft_strmer(op->str, s);
}
