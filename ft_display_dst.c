/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_dst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:53:35 by mvaldes           #+#    #+#             */
/*   Updated: 2020/03/06 17:59:01 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*arg_to_str(char *dst, t_arg arg, t_c_prms prms)
{
	if ((prms.width == 0 && prms.preci != -1 && prms.is_0 == 0) ||
	(prms.width != 0 && prms.preci == -1 && prms.is_0 == 1) ||
	(prms.width != 0 && prms.preci != -1 && prms.is_0 == 1))
		arg.ival = arg.ival < 0 ? -arg.ival : arg.ival;
	dst = prms.type == 's' && arg.sval != NULL ? ft_strdup(arg.sval) : dst;
	dst = prms.type == 'p' ? NULL : dst;
	dst = prms.type == 'd' ? ft_itoa(arg.ival) : dst;
	dst = prms.type == 'i' ? ft_itoa(arg.sival) : dst;
	dst = prms.type == 'u' ? ft_itoa(arg.uival) : dst;
	dst = prms.type == 'x' ? ft_itoa(arg.uival) : dst;
	dst = prms.type == 'X' ? ft_itoa(arg.uival) : dst;
	return (dst);
}

t_lyt	do_display_ptr(t_arg arg, t_lyt lay, char *base)
{
	ft_putstr("0x");
	ft_putnbr_base(arg.pval, base, lay.out_arg - 2);
	return (lay);
}

t_lyt	do_display_hex(t_arg arg, t_lyt lay, t_c_prms prms, char *base)
{
	if (arg.uival == 0 && (prms.preci == 0 || prms.preci == -2))
		return (lay);
	else
	{
		if (prms.preci == -2 && arg.uival == 0 && prms.width != 0)
			return (lay);
		else
			ft_putnbr_base(arg.uival, base, lay.out_arg);
	}
	return (lay);
}

t_lyt	do_display_dst(t_arg arg, t_lyt lay, t_c_prms prms)
{
	char	*dst;
	char	*tmp;

	dst = NULL;
	dst = arg_to_str(dst, arg, prms);
	tmp = dst;
	if ((prms.type == 's') || (prms.type == 'd' && (!(arg.ival == 0 &&
	(prms.preci == 0 || prms.preci == -2)))) || (prms.type == 'i' && (!(arg.sival == 0 &&
	(prms.preci == 0 || prms.preci == -2)))))
	{
		if (prms.type == 's' && arg.sval == NULL)
			dst = ft_strdup("(null)");
		while (dst != NULL && dst[0] != '\0' && lay.out_arg > lay.spc_afr)
		{
			ft_putchar(*dst++);
			lay.out_arg--;
		}
	}
	free(tmp);
	return (lay);
}
