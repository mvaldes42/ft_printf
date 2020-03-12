/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_preci_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:46:17 by mvaldes           #+#    #+#             */
/*   Updated: 2020/03/06 11:05:21 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_prms		is_preci_0(const char *str, t_prms prms, int i, int j)
{
	if (str[j] == '0')
	{
		j++;
		if (ft_is_nbr_dgt(str[j]))
		{
			while (ft_is_nbr_dgt(str[j]))
				prms.preci[i++] = str[j++];
		}
		else
		{
			prms.preci[0] = '0';
			prms.preci_is_0 = 1;
			i++;
		}
	}
	else
	{
		while (ft_is_preci(str[j]))
			prms.preci[i++] = str[j++];
	}
	prms.preci[i] = '\0';
	prms.j = j;
	return (prms);
}
