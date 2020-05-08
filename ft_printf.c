/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:26:04 by mvaldes           #+#    #+#             */
/*   Updated: 2020/05/08 15:28:47 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		free_c_params(t_c_prms c_prms, t_arg arg)
{
	free(c_prms.size);
	if (arg.sval != NULL)
		free(arg.sval);
}

t_lyt		do_printf_arg(va_list arg_ptr, t_lyt lay,
			t_s_prms sub_prms)
{
	t_c_prms	c_prms;
	t_arg		arg;

	c_prms = cvt_prms(parse_prms(sub_prms.sub_str), arg_ptr);
	arg = cvt_arg(c_prms, arg_ptr);
	lay = do_display(make_lyt(c_prms, arg, lay), arg, c_prms);
	free_c_params(c_prms, arg);
	return (lay);
}

int			ft_printf(const char *format, ...)
{
	va_list		arg_ptr;
	char		*dst;
	t_lyt		lay;
	t_s_prms	sub_prms;

	va_start(arg_ptr, format);
	dst = ft_strdup(format);
	ft_bzero(&lay, sizeof(lay));
	while (*dst)
	{
		if (*dst == '%' && dst++ != '\0')
		{
			sub_prms = find_prms(dst, *dst);
			lay = do_printf_arg(arg_ptr, lay, find_prms(dst, *dst));
			ft_strremove(dst, sub_prms.sub_str);
			free(sub_prms.sub_str);
		}
		if (*dst != '%' && *dst != '\0')
		{
			lay.out_all++;
			ft_putchar(*dst++);
		}
	}
	va_end(arg_ptr);
	return (lay.out_all);
}
