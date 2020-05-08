/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_lyt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 10:23:02 by mvaldes           #+#    #+#             */
/*   Updated: 2020/05/08 12:39:16 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			do_z_before(t_c_prms p, t_lyt lay, t_arg arg, int dgt)
{
	if (!p.is_min && p.is_0)
	{
		if (((ft_is_nbr(p.type)) || p.type == '%') &&
		(p.preci == -1 && p.width > dgt))
			lay.z_bfr = p.width - dgt;
		if (p.type == 's' && p.width > p.preci)
			lay.z_bfr = p.preci != -1 ? p.width - p.preci : p.width - dgt;
	}
	if (!(p.type == 's') && p.preci > 0 && p.preci > dgt)
		lay.z_bfr = p.preci - dgt;
	if (p.type == 'd' && p.preci != -1)
		lay.z_bfr += arg.ival < 0 && lay.z_bfr > 0 ? 1 : 0;
	if (p.type == 'i' && p.preci != -1)
		lay.z_bfr += arg.sival < 0 && lay.z_bfr > 0 ? 1 : 0;
	if (p.type == 'd' && p.preci == dgt && arg.ival < 0)
		lay.z_bfr = p.preci - (dgt - 1);
	if (p.type == 'i' && p.preci == dgt && arg.sival < 0)
		lay.z_bfr = p.preci - (dgt - 1);
	return (lay.z_bfr);
}

int			do_spc_bfr(t_c_prms p, t_lyt lay, t_arg arg, int dgt)
{
	if (!p.is_min)
	{
		if ((p.width > (lay.out_arg + dgt)))
			lay.spc_bfr = p.width - (lay.out_arg + dgt);
		if (p.type == 'd' && (arg.ival == 0 && p.preci == 0))
			lay.spc_bfr++;
		if (p.type == 'd' && p.preci == 0 && arg.ival == 0 && p.width == 0)
			lay.spc_bfr -= dgt;
		if (p.type == 'd' && p.preci == -2 && arg.ival == 0 && p.width != 0)
			lay.spc_bfr += dgt;
		if ((p.type == 's' && p.preci != -1 && p.width != 0) &&
		(dgt > p.preci && p.width > p.preci && !p.is_0))
		{
			lay.spc_bfr = p.width - p.preci;
			if (arg.sval == NULL)
			{
				if (p.width > 0 && p.preci == -2)
					lay.spc_bfr = p.width;
				else if (p.width > 6 && p.preci == -1)
					lay.spc_bfr = 6 - p.width;
			}
		}
		if (p.type == 'i')
		{
			if (arg.sival == 0 && p.preci == 0)
				lay.spc_bfr++;
			if (p.preci == 0 && arg.sival == 0 && p.width == 0)
				lay.spc_bfr -= dgt;
			if (p.preci == -2 && arg.sival == 0 && p.width != 0)
				lay.spc_bfr += dgt;
		}
		if (p.type == 'u')
		{
			if (arg.uival == 0 && p.preci == 0)
				lay.spc_bfr++;
			if (p.preci == 0 && arg.uival == 0 && p.width == 0)
				lay.spc_bfr -= dgt;
			if (p.preci == -2 && arg.uival == 0 && p.width != 0)
				lay.spc_bfr += dgt;
		}
	}
	if (p.is_min && p.width == 1 && (p.preci == 0 || p.preci == -2))
	{
		if ((p.type == 'd' && arg.ival == 0) ||
		(p.type == 'i' && arg.sival == 0) || (p.type == 'u' && arg.uival == 0))
			lay.spc_bfr += 1;
	}
	return (lay.spc_bfr);
}

int			do_spc_afr(t_c_prms prms, t_lyt lay, t_arg arg, int dgt)
{
	if (prms.width > (lay.out_arg + dgt) && prms.is_min)
	{
		if (prms.preci == -1 || (prms.preci == 0 && arg.ival != 0))
			lay.spc_afr = prms.width - (lay.out_arg + dgt);
		else
			lay.spc_afr = prms.width - (lay.out_arg + dgt);
		if (prms.type == 'd' && prms.preci == 0 && arg.ival == 0)
			lay.spc_afr += dgt;
		if (prms.type == 'd' && prms.preci == -2 && arg.ival == 0)
			lay.spc_afr += dgt;
		if (prms.type == 'i' && prms.preci == 0 && arg.sival == 0)
			lay.spc_afr += dgt;
		if (prms.type == 'i' && prms.preci == -2 && arg.sival == 0)
			lay.spc_afr += dgt;
		if (prms.type == 'u' && prms.preci == 0 && arg.uival == 0)
			lay.spc_afr += dgt;
		if (prms.type == 'u' && prms.preci == -2 && arg.uival == 0)
			lay.spc_afr += dgt;
	}
	if ((prms.type == 's' && prms.preci != -1 && prms.width != 0) &&
	(dgt > prms.preci && prms.width > prms.preci) && prms.is_min)
		lay.spc_afr = prms.width - prms.preci;
	return (lay.spc_afr);
}

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
	dgt = prms.type == '%' ? 1 : dgt;
	lay.z_bfr = do_z_before(prms, lay, arg, dgt);
	lay.out_arg = lay.z_bfr;
	lay.spc_bfr = do_spc_bfr(prms, lay, arg, dgt);
	lay.out_arg += lay.spc_bfr;
	lay.spc_afr = do_spc_afr(prms, lay, arg, dgt);
	lay.out_arg += lay.spc_afr;
	lay.out_arg = do_out_arg(prms, lay, arg, dgt);
	// printf("\n\nz_before= %d\n", lay.z_bfr);
	// printf("spc_before = %d\n", lay.spc_bfr);
	// printf("spc_after = %d\n", lay.spc_afr);
	// printf("char_output = %lld\n", lay.out_arg);
	return (lay);
}
