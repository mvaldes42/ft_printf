/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_prms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 10:14:59 by mvaldes           #+#    #+#             */
/*   Updated: 2020/05/08 15:13:10 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_s_prms	find_prms(const char *str, char c)
{
	t_s_prms	str_params;

	ft_bzero(&str_params, sizeof(str_params));
	str_params.end = ft_find_index(str, "cspdiuxX%");
	str_params.start = ft_get_index(str, c);
	str_params.len = str_params.end - str_params.start;
	str_params.sub_str = ft_substr(str, str_params.start, str_params.len + 1);
	return (str_params);
}
