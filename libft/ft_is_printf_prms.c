/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_printf_prms.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:39:24 by mvaldes           #+#    #+#             */
/*   Updated: 2020/03/06 11:12:41 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_preci(char c)
{
	if ((c >= '0' && c <= '9') || c == '*')
		return (1);
	else
		return (0);
}

int		ft_is_type(char p)
{
	if (p == 'c' || p == 's' || p == 'p' || p == 'd' || p == 'i' || p == 'u' ||
	p == 'x' || p == 'X' || p == '%' || p == 'n' || p == 'f' || p == 'g' ||
	p == 'e')
		return (1);
	return (0);
}

int		ft_is_nbr(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	else
		return (0);
}

int		ft_is_nbr_dgt(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
