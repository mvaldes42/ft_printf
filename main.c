/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:28:56 by mvaldes           #+#    #+#             */
/*   Updated: 2020/05/08 12:43:07 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				main(void)
{

	//static char	a01;
	// static unsigned char a02;
	// static short a03;
	// static unsigned short a04;
	// static int a05;
	// static unsigned int a06;
	// static long a07;
	// static unsigned long a08;
	// static long long a09;
	// static unsigned long long a10;
	// static char *a11;
	// static void *a12;

	printf("ret = %d\n", printf("%*i", -4, 94827));
    printf("ret = %d\n", ft_printf("%*i", -4, 94827));
}
