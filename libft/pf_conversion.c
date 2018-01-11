/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 00:06:56 by eLopez            #+#    #+#             */
/*   Updated: 2017/09/29 06:15:17 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	pf_conv_flags(const char **fmt)
{
	t_flags	flag;

	ft_bzero(&flag, sizeof(flag));
	if (*(*fmt + 1) > '0' && ++*fmt)
		return (flag);
	while (1)
	{
		if (*++*fmt == '#')
			flag.alter = 1;
		else if (**fmt == '-')
			flag.left_adj = 1;
		else if (**fmt == '0')
			flag.zero = 1;
		else if (**fmt == '+')
			flag.sign = 1;
		else if (**fmt == ' ')
			flag.space = 1;
		else
			break ;
	}
	if (flag.left_adj & flag.zero)
		flag.zero = 0;
	if (flag.sign & flag.space)
		flag.space = 0;
	return (flag);
}

void	pf_conv_width(const char **fmt, t_flags *flag, va_list *ap)
{
	while (ft_isdigit(**fmt) || **fmt == '*')
	{
		flag->width = 0;
		while (ft_isdigit(**fmt))
		{
			flag->width = flag->width * 10 + ((**fmt) - '0');
			++(*fmt);
		}
		if (**fmt == '*')
		{
			flag->width = va_arg(*ap, int);
			if (flag->width < 0)
			{
				flag->left_adj = 1;
				flag->width = -flag->width;
			}
			++(*fmt);
		}
	}
}

void	pf_conv_precision(const char **fmt, t_flags *flag, va_list *ap)
{
	if (**fmt == '.')
	{
		if (*++*fmt != '-')
			flag->prec = 1;
		else
			++(*fmt);
		if (**fmt == '*')
		{
			flag->prec_num = va_arg(*ap, int);
			if (flag->prec_num < 0)
				flag->prec = 0;
			++(*fmt);
		}
		else
			while (ft_isdigit(**fmt))
			{
				flag->prec_num = flag->prec_num * 10 + ((**fmt) - '0');
				++(*fmt);
			}
	}
}

void	pf_conv_length(const char **fmt, t_flags *flag)
{
	if (**fmt == 'h')
		flag->h = 1;
	else if (**fmt == 'l')
		flag->l = 1;
	else if (**fmt == 'j')
		flag->j = 1;
	else if (**fmt == 'z')
		flag->z = 1;
	if (flag->h || flag->l || flag->j || flag->z)
	{
		if (*++*fmt == 'h' && flag->h)
		{
			flag->hh = 1;
			flag->h = 0;
			++(*fmt);
		}
		else if (**fmt == 'l' && flag->l)
		{
			flag->ll = 1;
			flag->l = 0;
			++(*fmt);
		}
	}
}
