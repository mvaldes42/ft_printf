/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_lyt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 10:23:02 by mvaldes           #+#    #+#             */
/*   Updated: 2020/05/08 13:25:36 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			do_out_arg(t_c_prms prms, t_lyt lay, t_arg arg, int dgt)
{
	lay = prms.type == 's' ? out_arg_str(prms, lay, arg, dgt) : lay;
	lay.out_arg += prms.type == 'c' ? 1 : 0;
	lay.out_arg += prms.type == 'd' ? dgt : 0;
	if (prms.type == 'd' && arg.ival == 0 && (prms.preci == -2 ||
	prms.preci == 0))
		lay.out_arg -= dgt;
	lay.out_arg += prms.type == 'p' ? dgt : 0;
	lay.out_arg += prms.type == '%' ? 1 : 0;
	lay.out_arg += prms.type == 'i' ? dgt : 0;
	if (prms.type == 'i' && arg.sival == 0 && (prms.preci == -2 ||
	prms.preci == 0))
		lay.out_arg -= dgt;
	lay.out_arg += prms.type == 'u' ? dgt : 0;
	if (prms.type == 'u' && arg.uival == 0 && (prms.preci == -2 ||
	prms.preci == 0))
		lay.out_arg -= dgt;
	lay.out_arg += prms.type == 'x' ? dgt : 0;
	lay.out_arg += prms.type == 'X' ? dgt : 0;
	return (lay.out_arg);
}

int			ft_putnbr_base_digits(unsigned long nb, int count)
{
	if (nb >= 16)
		count += ft_putnbr_base_digits(nb / 16, count);
	count++;
	return (count);
}

int			count_dgt(t_c_prms prms, t_arg arg, int dgt)
{
	if (prms.type == 'p')
	{
		dgt = ft_putnbr_base_digits(arg.pval, 0) + 2;
		dgt = prms.preci == -2 && arg.pval == 0 ? 2 : dgt;
	}
	if (prms.type == 'x' || prms.type == 'X')
	{
		if (arg.uival == 0 && (prms.preci == 0 || prms.preci == -2))
			dgt = 0;
		else
		{
			if (prms.preci == -2 && arg.uival == 0 && prms.width != 0)
				dgt = 0;
			else
				dgt = ft_putnbr_base_digits(arg.uival, 0);
		}
	}
	return (dgt);
}

t_lyt		make_lyt(t_c_prms prms, t_arg arg, t_lyt lay)
{
	int	dgt;

	lay = (t_lyt) {0, 0, 0, 0, 0, lay.out_all};
	dgt = prms.type == 'd' ? ft_digit_len((long long)arg.ival) : 0;
	dgt = prms.type == 'i' ? ft_digit_len((long long)arg.sival) : dgt;
	dgt = prms.type == 'u' ? ft_digit_len((long long)arg.uival) : dgt;
	dgt = prms.type == 'c' ? 1 : dgt;
	dgt = prms.type == 's' && arg.sval != NULL ? ft_strlen(arg.sval) : dgt;
	dgt = prms.type == 's' && arg.sval == NULL ? 6 : dgt;
	if (prms.type == 'p' || prms.type == 'x' || prms.type == 'X')
		dgt = count_dgt(prms, arg, dgt);
	dgt = prms.type == '%' ? 1 : dgt;
	lay.z_bfr = do_z_before(prms, lay, arg, dgt);
	lay.out_arg = lay.z_bfr;
	lay.spc_bfr = do_spc_bfr(prms, lay, arg, dgt);
	lay.out_arg += lay.spc_bfr;
	lay.spc_afr = do_spc_afr(prms, lay, arg, dgt);
	lay.out_arg += lay.spc_afr;
	lay.out_arg = do_out_arg(prms, lay, arg, dgt);
	return (lay);
}
