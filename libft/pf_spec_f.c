/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_spec_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 13:12:30 by elopez            #+#    #+#             */
/*   Updated: 2017/09/27 03:27:48 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	add_prefix(t_flags *flag, char **result)
{
	if (flag->sign)
		*result = ft_strmerge(ft_strdup("+"), *result);
	else if (flag->space)
		*result = ft_strmerge(ft_strdup(" "), *result);
}

static void	set_decimal(t_flags *flag, char **result)
{
	char *temp;

	if (flag->prec && flag->prec_num < 6)
	{
		flag->prec_num -= 6;
		temp = ft_strsub(*result, 0, ft_strlen(*result) + flag->prec_num);
		ft_strdel(result);
		*result = temp;
	}
	if (flag->alter == 0 && *(*result + ft_strlen(*result) - 1) == '.')
		*(*result + ft_strlen(*result) - 1) = '\0';
}

static void	print_width(t_flags *flag, t_outp *op, char **result)
{
	flag->width -= ft_strlen(*result);
	if (flag->left_adj == 0)
	{
		if (flag->zero)
			*result = ft_strmerge(MAKES('0', flag->width), *result);
		else
			*result = ft_strmerge(MAKES(' ', flag->width), *result);
	}
	else
		*result = ft_strmerge(*result, MAKES(' ', flag->width));
	op->str = ft_strmer(op->str, *result);
}

void		pf_spec_f(t_flags *flag, t_outp *op, va_list *ap)
{
	double	val;
	double	dec_part;
	char	*int_part;
	char	*dec_s;
	char	*result;

	val = va_arg(*ap, double);
	int_part = ft_lltoa((long long)val);
	if (*int_part == '0' && val < 0.0)
		int_part = ft_strmerge(ft_strdup("-"), int_part);
	dec_part = (val - (long long)val) * 1000000.0;
	dec_part *= (dec_part < 0.0) ? -1 : 1;
	result = ft_strmerge(int_part, ft_strdup("."));
	if (ft_strlen(dec_s = ft_lltoa((long long)(dec_part + 0.5))) < 6)
		while (ft_strlen(dec_s) != 6)
			dec_s = ft_strmerge(ft_strdup("0"), dec_s);
	result = ft_strmerge(result, dec_s);
	if (result[0] != '-' && (flag->sign | flag->space))
		add_prefix(flag, &result);
	set_decimal(flag, &result);
	if (flag->width > (int)ft_strlen(result))
		print_width(flag, op, &result);
	else
		op->str = ft_strmer(op->str, result);
}
