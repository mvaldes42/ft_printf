/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 10:58:48 by mvaldes           #+#    #+#             */
/*   Updated: 2020/03/06 11:11:20 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_index(const char *s1, const char *set)
{
	int i;

	i = 0;
	while (s1[i] && s1 != NULL)
	{
		if (!ft_is_on_set(set, s1[i]))
		{
			i++;
		}
		else
			return (i);
	}
	return (0);
}
