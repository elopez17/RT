/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 13:33:29 by elopez            #+#    #+#             */
/*   Updated: 2017/09/27 03:41:22 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_percent(t_flags *flag, t_outp *op, va_list *ap)
{
	int	len;

	if (flag->width > 1 && ap)
	{
		len = flag->width - 1;
		if (flag->zero)
			op->str = ft_strmer(op->str, MAKES('0', len));
		else if (!flag->left_adj)
			op->str = ft_strmer(op->str, MAKES(' ', len));
		op->str = ft_strmer(op->str, ft_strdup("%"));
		if (flag->left_adj)
			op->str = ft_strmer(op->str, MAKES(' ', len));
		return ;
	}
	op->str = ft_strmer(op->str, ft_strdup("%"));
}
