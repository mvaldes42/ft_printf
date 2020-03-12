/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_out_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 10:38:00 by mvaldes           #+#    #+#             */
/*   Updated: 2020/03/06 10:54:23 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_lyt	out_arg_str(t_c_prms prms, t_lyt lyt, t_arg arg, int dgt)
{
	if (prms.preci < (int)ft_strlen(arg.sval) && prms.preci != -1 &&
	arg.sval != NULL)
		lyt.out_arg += prms.preci;
	else if (prms.is_0 && prms.width < dgt)
		lyt.out_arg = dgt;
	else if (arg.sval != NULL)
		lyt.out_arg += ft_strlen(arg.sval);
	else
	{
		if (prms.preci == -1 || prms.preci >= 6)
			lyt.out_arg += 6;
		else if (prms.preci < 6)
		{
			if (prms.width > prms.preci)
				lyt.out_arg = prms.width;
			else
				lyt.out_arg = prms.preci;
		}
	}
	return (lyt);
}
