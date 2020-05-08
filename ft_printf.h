/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:13:44 by mvaldes           #+#    #+#             */
/*   Updated: 2020/05/08 16:12:01 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct	s_s_prms
{
	int		start;
	int		end;
	size_t	len;
	char	*sub_str;
}				t_s_prms;

/*
** %[flags][width][.precision][size]type
*/

typedef struct	s_prms
{
	char	*flags;
	char	*width;
	char	*preci;
	int		preci_is_0;
	char	*size;
	char	type;
	int		i;
	int		j;
}				t_prms;

typedef struct	s_c_prms
{
	int		is_min;
	int		is_0;
	int		width;
	int		preci;
	char	*size;
	char	type;
}				t_c_prms;

typedef struct	s_arg
{
	char			cval;
	char			*sval;
	unsigned long	pval;
	int				ival;
	signed int		sival;
	unsigned int	uival;
}				t_arg;

typedef struct	s_layt
{
	int			z_bfr;
	int			spc_bfr;
	int			spc_afr;
	int			is_neg;
	long long	out_arg;
	long long	out_all;
}				t_lyt;

int				ft_get_nbr(t_arg arg, t_c_prms prms);
t_prms			is_preci_0(const char *str, t_prms prms, int i, int j);
t_lyt			out_arg_str(t_c_prms prms, t_lyt lyt, t_arg arg, int dgt);

char			*find_prms(const char *str, char c);
t_prms			parse_prms(const char *str);
t_c_prms		cvt_prms(t_prms prms, va_list arg_p);
t_arg			cvt_arg(t_c_prms prms, va_list arg_p);

int				do_z_before(t_c_prms p, t_lyt lay, t_arg arg, int dgt);
int				do_spc_bfr_nbr(t_c_prms p, t_lyt lay, t_arg arg, int dgt);
int				do_spc_bfr(t_c_prms p, t_lyt lay, t_arg arg, int dgt);
int				do_spc_afr(t_c_prms prms, t_lyt lay, t_arg arg, int dgt);

t_lyt			make_lyt(t_c_prms prms, t_arg arg, t_lyt lay);

t_lyt			do_display(t_lyt lay, t_arg arg, t_c_prms prms);
t_lyt			do_display_dst(t_arg arg, t_lyt lay, t_c_prms prms);
t_lyt			do_display_ptr(t_arg arg, t_lyt lay, char *base);
t_lyt			do_display_hex(t_arg arg, t_lyt lay, t_c_prms prms, char *base);

int				ft_printf(const char *format, ...);

#endif
