/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_lyt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 13:26:40 by mvaldes           #+#    #+#             */
/*   Updated: 2020/05/08 13:27:47 by mvaldes          ###   ########.fr       */
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
	if (p.preci != -1)
	{
		if (p.type == 'd')
			lay.z_bfr += arg.ival < 0 && lay.z_bfr > 0 ? 1 : 0;
		if (p.type == 'i')
			lay.z_bfr += arg.sival < 0 && lay.z_bfr > 0 ? 1 : 0;
	}
	if (p.preci == dgt)
		if ((p.type == 'd' && arg.ival < 0) || (p.type == 'i' && arg.sival < 0))
			lay.z_bfr = p.preci - (dgt - 1);
	return (lay.z_bfr);
}

int			do_spc_bfr_nbr(t_c_prms p, t_lyt lay, t_arg arg, int dgt)
{
	if ((p.type == 'd') && (arg.ival == 0 && p.preci == 0))
		lay.spc_bfr++;
	if ((p.type == 'd') && (p.preci == 0 && arg.ival == 0 && p.width == 0))
		lay.spc_bfr -= dgt;
	if ((p.type == 'd') && (p.preci == -2 && arg.ival == 0 && p.width != 0))
		lay.spc_bfr += dgt;
	if ((p.type == 'i') && (arg.sival == 0 && p.preci == 0))
		lay.spc_bfr++;
	if ((p.type == 'i') && (p.preci == 0 && arg.sival == 0 && p.width == 0))
		lay.spc_bfr -= dgt;
	if ((p.type == 'i') && (p.preci == -2 && arg.sival == 0 && p.width != 0))
		lay.spc_bfr += dgt;
	if ((p.type == 'u') && (arg.uival == 0 && p.preci == 0))
		lay.spc_bfr++;
	if ((p.type == 'u') && (p.preci == 0 && arg.uival == 0 && p.width == 0))
		lay.spc_bfr -= dgt;
	if ((p.type == 'u') && (p.preci == -2 && arg.uival == 0 && p.width != 0))
		lay.spc_bfr += dgt;
	return (lay.spc_bfr);
}

int			do_spc_bfr(t_c_prms p, t_lyt lay, t_arg arg, int dgt)
{
	if (!p.is_min)
	{
		if ((p.width > (lay.out_arg + dgt)))
			lay.spc_bfr = p.width - (lay.out_arg + dgt);
		lay.spc_bfr = do_spc_bfr_nbr(p, lay, arg, dgt);
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
	}
	if (p.is_min && p.width == 1 && (p.preci == 0 || p.preci == -2))
	{
		if ((p.type == 'd' && arg.ival == 0) || (p.type == 'i' &&
		arg.sival == 0) || (p.type == 'u' && arg.uival == 0))
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
