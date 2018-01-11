/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_spec_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 13:33:29 by elopez            #+#    #+#             */
/*   Updated: 2017/10/19 15:05:57 by elopez           ###   ########.fr       */
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

static void			print_width(t_flags *flag, t_outp *op, char **s, int *ret)
{
	char	*new_s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_s = ft_strnew(flag->width);
	while ((flag->prec && *ret < flag->prec_num) ||\
			(flag->zero && *ret < flag->width))
	{
		new_s[i++] = '0';
		++(*ret);
	}
	while ((*s)[j] != '\0')
		new_s[i++] = (*s)[j++];
	if (flag->left_adj)
		op->str = ft_strmer(op->str, new_s);
	if (*ret < flag->width)
		op->str = ft_strmer(op->str, MAKES(' ', flag->width - *ret));
	if (!flag->left_adj)
		op->str = ft_strmer(op->str, new_s);
	ft_strdel(s);
}

void				pf_spec_u(t_flags *flag, t_outp *op, va_list *ap)
{
	uintmax_t	val;
	char		*s;
	int			ret;

	flag->zero = (flag->prec == 1) ? 0 : flag->zero;
	val = len_arg(flag, ap);
	s = (!val && !HASLENGTH(flag) && (flag->prec && !flag->prec_num) &&\
			!HASFLAG(flag)) ? ft_strdup("") : ft_uimttoa(val);
	ret = ft_strlen(s);
	if (flag->width > ret && (flag->width > flag->prec_num || !flag->prec))
		print_width(flag, op, &s, &ret);
	else if (flag->prec && flag->prec_num > ret)
	{
		op->str = ft_strmer(op->str, MAKES('0', flag->prec_num - ret));
		op->str = ft_strmer(op->str, s);
	}
	else
		op->str = ft_strmer(op->str, s);
}
