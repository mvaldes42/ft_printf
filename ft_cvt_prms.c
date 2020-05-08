/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cvt_prms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 10:54:02 by mvaldes           #+#    #+#             */
/*   Updated: 2020/05/08 12:42:29 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		free_params(t_prms prms)
{
	free(prms.flags);
	free(prms.width);
	free(prms.preci);
	free(prms.size);
}

t_c_prms	cvt_asterix(t_c_prms c_prms, t_prms prms, va_list arg_p)
{
	if (prms.width[0] == '*')
	{
		c_prms.width = va_arg(arg_p, int);
		if (c_prms.width < 0)
		{
			c_prms.width = c_prms.width * -1;
			c_prms.is_min = 1;
		}
	}
	if (prms.preci[0] == '*')
	{
		c_prms.preci = va_arg(arg_p, int);
		c_prms.preci = c_prms.preci >= 0 ? c_prms.preci : -1;
	}
	return (c_prms);
}

t_c_prms	cvt_prms(t_prms prms, va_list arg_p)
{
	t_c_prms c_prms;

	c_prms = (t_c_prms) {0, 0, atoi(prms.width), atoi(prms.preci),
	ft_strdup(prms.size), prms.type};
	c_prms.is_min = ft_is_on_set(prms.flags, '-') ? 1 : 0;
	c_prms.is_0 = ft_is_on_set(prms.flags, '0') ? 1 : 0;
	c_prms = cvt_asterix(c_prms, prms, arg_p);
	if (prms.preci_is_0 == 1)
		c_prms.preci = 0;
	else
	{
		c_prms.preci = prms.preci[0] == '0' && ft_is_nbr(prms.type) ? 1 :
		c_prms.preci;
		c_prms.preci = prms.preci[0] == '0' && !ft_is_nbr(prms.type) &&
		prms.preci_is_0 == 1 ? 0 : c_prms.preci;
		c_prms.preci = prms.preci[0] == '-' ? -2 : c_prms.preci;
		c_prms.preci = prms.preci[0] == '\0' ? -1 : c_prms.preci;
	}
	free_params(prms);
	return (c_prms);
}

t_arg		cvt_arg(t_c_prms prms, va_list arg_p)
{
	t_arg arg;

	arg = (t_arg) {0, NULL, 0, 0, 0, 0};
	arg.cval = prms.type == 'c' ? va_arg(arg_p, int) : '\0';
	arg.sval = prms.type == 's' ? ft_strdup(va_arg(arg_p, char*)) : NULL;
	arg.pval = prms.type == 'p' ? va_arg(arg_p, unsigned long) : '\0';
	arg.ival = prms.type == 'd' ? va_arg(arg_p, int) : '\0';
	arg.sival = prms.type == 'i' ? va_arg(arg_p, signed int) : '\0';
	arg.uival = (prms.type == 'u' || prms.type == 'x' ||
	prms.type == 'X') ? va_arg(arg_p, unsigned int) : '\0';
	return (arg);
}
