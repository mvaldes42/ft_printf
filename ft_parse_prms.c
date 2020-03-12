/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_prms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:06:06 by mvaldes           #+#    #+#             */
/*   Updated: 2020/03/06 11:05:19 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_prms		parse_flags(const char *str, t_prms prms, int i, int j)
{
	while (str[j] == '0' || str[j] == '-')
		prms.flags[i++] = str[j++];
	prms.flags[i] = '\0';
	prms.j = j;
	prms.i = 0;
	return (prms);
}

t_prms		parse_width(const char *str, t_prms prms, int i, int j)
{
	while ((str[j] >= '0' && str[j] <= '9') || str[j] == '*')
		prms.width[i++] = str[j++];
	prms.width[i] = '\0';
	prms.j = j;
	prms.i = 0;
	return (prms);
}

t_prms		parse_preci(const char *str, t_prms prms, int i, int j)
{
	if (str[j] == '.')
	{
		j++;
		if (str[j] == '-')
		{
			prms.preci[0] = '-';
			i++;
			while (ft_is_preci(str[j++]))
				continue;
		}
		else if (!ft_is_preci(str[j]))
		{
			prms.preci[0] = '-';
			i++;
			prms.j = j;
		}
		else
			prms = is_preci_0(str, prms, i, j);
	}
	else
		prms.preci[0] = '\0';
	prms.i = 0;
	return (prms);
}

t_prms		parse_size(const char *str, t_prms prms, int i, int j)
{
	while (str[j] == 'l' || str[j] == 'h')
		prms.size[i++] = str[j++];
	prms.size[i] = '\0';
	prms.j = j;
	prms.i = 0;
	return (prms);
}

t_prms		parse_prms(const char *str)
{
	t_prms		prms;

	prms = (t_prms) {ft_strdup(str), ft_strdup(str), ft_strdup(str),
	0, ft_strdup(str), '\0', 0, 0};
	prms = parse_flags(str, prms, prms.i, prms.j);
	prms = parse_width(str, prms, prms.i, prms.j);
	prms = parse_preci(str, prms, prms.i, prms.j);
	prms = parse_size(str, prms, prms.i, prms.j);
	if (ft_is_type(str[prms.j]))
		prms.type = str[prms.j];
	return (prms);
}
