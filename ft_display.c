/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 10:26:44 by mvaldes           #+#    #+#             */
/*   Updated: 2020/03/06 17:47:58 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_lyt	do_display_prt_1(t_lyt lay, t_arg arg, t_c_prms prms)
{
	if (prms.type == 'c' && arg.cval == '\0' && prms.is_min == 1)
		write(1, "\0", 1);
	while (lay.spc_bfr-- > 0 && lay.out_arg-- > 0)
		ft_putchar(' ');
	return (lay);
}

t_lyt	do_display_prt_2(t_lyt lay, t_arg arg)
{
	while (lay.z_bfr-- > 0 && lay.out_arg-- > 0)
		ft_putchar('0');
	if (arg.cval != '\0')
		write(1, &arg.cval, 1);
	return (lay);
}

t_lyt	do_display_prt_3(t_lyt lay, t_arg arg, t_c_prms prms)
{
	char *hex;
	char *hex_up;

	hex = "0123456789abcdef";
	hex_up = "0123456789ABCDEF";
	lay = prms.type == 'p' ? do_display_ptr(arg, lay, hex) : lay;
	lay = prms.type == 'x' ? do_display_hex(arg, lay, prms, hex) : lay;
	lay = prms.type == 'X' ? do_display_hex(arg, lay, prms, hex_up) : lay;
	if (prms.type == '%')
		ft_putchar('%');
	while (lay.spc_afr-- > 0 && lay.out_arg-- > 0)
		ft_putchar(' ');
	if (prms.type == 'c' && arg.cval == '\0' && prms.is_min == 0)
		write(1, "\0", 1);
	return (lay);
}

t_arg	val_is_neg(t_arg arg, t_c_prms prms)
{
	if ((prms.type == 'd' && arg.ival < 0) && ((prms.width == 0 &&
	prms.preci != -1 && prms.is_0 == 0) || (prms.width != 0 &&
	prms.preci == -1 && prms.is_0 == 1) || (prms.width != 0 &&
	prms.preci != -1)))
	{
		ft_putchar('-');
		arg.ival = -arg.ival;
	}
	if ((prms.type == 'i' && arg.sival < 0) && ((prms.width == 0 &&
	prms.preci != -1 && prms.is_0 == 0) || (prms.width != 0 &&
	prms.preci == -1 && prms.is_0 == 1) || (prms.width != 0 &&
	prms.preci != -1)))
	{
		ft_putchar('-');
		arg.sival = -arg.sival;
	}
	return (arg);
}

t_lyt	do_display(t_lyt lay, t_arg arg, t_c_prms prms)
{
	int		char_tmp;

	char_tmp = lay.out_arg;
	lay.out_all += lay.out_arg > 0 ? lay.out_arg : 0;
	lay = do_display_prt_1(lay, arg, prms);
	arg = val_is_neg(arg, prms);
	lay = do_display_prt_2(lay, arg);
	lay = do_display_dst(arg, lay, prms);
	lay = do_display_prt_3(lay, arg, prms);
	lay.out_arg = char_tmp;
	return (lay);
}
