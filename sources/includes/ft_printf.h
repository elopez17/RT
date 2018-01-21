/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 00:06:40 by eLopez            #+#    #+#             */
/*   Updated: 2017/09/29 11:33:46 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <libft.h>
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>
# define TOTAL_SPECS 19
# define HASFLAG(f) (f->alter || f->zero || f->sign || f->space)
# define HASLENGTH(f) (f->l || f->ll || f->j || f->z || f->h || f->hh)
# define WIDTH_PREC(f) (f->width || (f->prec && f->prec_num))
# define MAKES(c, len) ft_memset(ft_strnew(len), c, len)

typedef struct	s_flags
{
	int				width;
	int				prec_num;
	unsigned int	prec : 1;
	unsigned int	alter : 1;
	unsigned int	zero : 1;
	unsigned int	left_adj : 1;
	unsigned int	sign : 1;
	unsigned int	space : 1;
	unsigned int	h : 1;
	unsigned int	hh : 1;
	unsigned int	l : 1;
	unsigned int	ll : 1;
	unsigned int	j : 1;
	unsigned int	z : 1;
}				t_flags;

typedef struct	s_output
{
	char	*str;
	int		wlen;
}				t_outp;

typedef struct	s_convspec
{
	char	c;
	void	(*f)(t_flags *, t_outp *, va_list *);
}				t_convspec;

typedef struct	s_color
{
	char	c;
	char	*str;
}				t_color;

/*
**	Entry point. main function
*/
int				ft_printf(const char *fmt, ...);

/*
**	parse conversion info functions
*/
t_flags			pf_conv_flags(const char **fmt);
void			pf_conv_width(const char **fmt, t_flags *flag, va_list *ap);
void			pf_conv_precision(const char **fmt, t_flags *flag, \
		va_list *ap);
void			pf_conv_length(const char **fmt, t_flags *flag);
int				pf_conv_spec(const char **fmt, t_flags *flag, t_outp *op,\
		va_list *ap);

/*
**	conversion specifier functions
*/
void			pf_percent(t_flags *flag, t_outp *op, va_list *ap);
void			pf_spec_u(t_flags *flag, t_outp *op, va_list *ap);
void			pf_spec_di(t_flags *flag, t_outp *op, va_list *ap);
void			pf_spec_o(t_flags *flag, t_outp *op, va_list *ap);
void			pf_spec_x(t_flags *flag, t_outp *op, va_list *ap);
void			pf_spec_xup(t_flags *flag, t_outp *op, va_list *ap);
void			pf_spec_p(t_flags *flag, t_outp *op, va_list *ap);
void			pf_str(t_flags *flag, t_outp *op, va_list *ap);
void			pf_char(t_flags *flag, t_outp *op, va_list *ap);
void			pf_wchar_t(t_flags *flag, t_outp *op, va_list *ap);
void			pf_wint_t(t_flags *flag, t_outp *op, va_list *ap);
void			pf_spec_f(t_flags *flag, t_outp *op, va_list *ap);
int				pf_color(const char **fmt, t_outp *op);
void			pf_itobi(t_flags *flag, t_outp *op, va_list *ap);
void			pf_iso8601(t_flags *flag, t_outp *op, va_list *ap);

#endif
