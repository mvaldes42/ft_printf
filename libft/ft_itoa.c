/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:21:09 by mvaldes           #+#    #+#             */
/*   Updated: 2020/05/01 13:08:03 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		digit_len(long n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(long long n)
{
	char		*result;
	long long	i;
	long long	nb;

	nb = n;
	i = digit_len(nb);
	if (!(result = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	result[i--] = '\0';
	if (nb == 0 && i == 1)
		return (NULL);
	if (nb == 0)
		result[i++] = '0';
	if (nb < 0)
	{
		result[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		result[i] = '0' + (nb % 10);
		nb = nb / 10;
		i--;
	}
	return (result);
}
