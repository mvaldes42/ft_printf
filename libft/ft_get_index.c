/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:00:58 by mvaldes           #+#    #+#             */
/*   Updated: 2020/03/06 11:01:23 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_index(const char *s1, const char c)
{
	int i;

	i = 0;
	while (s1[i] && s1 != NULL)
	{
		if (s1[i] == c)
			return (i);
		else
			i++;
	}
	return (0);
}
