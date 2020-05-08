/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:28:56 by mvaldes           #+#    #+#             */
/*   Updated: 2020/05/08 15:27:37 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				main(void)
{
	printf("ret = %d\n", printf("%d hello", 10));
	printf("ret = %d\n", ft_printf("%d hello", 10));

	// printf("\n\nz_before= %d\n", lay.z_bfr);
	// printf("spc_before = %d\n", lay.spc_bfr);
	// printf("spc_after = %d\n", lay.spc_afr);
	// printf("char_output = %lld\n", lay.out_arg);

	// printf("\nflag is - = %s\n", c_prms.is_min ? "true" : "false");
	// printf("flag is 0 = %s\n", c_prms.is_0 ? "true" : "false");
	// printf("width = %d\n", c_prms.width);
	// printf("precision = %d\n", c_prms.preci);
	// printf("size = %s\n", c_prms.size == '\0' ? c_prms.size : "NULL");
	// printf("type = %c\n", c_prms.type);
}
