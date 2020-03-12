/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:18:56 by mvaldes           #+#    #+#             */
/*   Updated: 2020/03/02 16:34:08 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strremove(char *str, const char *to_remove)
{
	int i;
	int j;
	int found;

	found = 0;
	i = -1;
	while (i++ < (int)ft_strlen(str))
	{
		found = 1;
		j = 0;
		while (j < (int)ft_strlen(to_remove))
		{
			if (str[i + j] != to_remove[j])
				found = 0;
			j++;
		}
		if (found == 1)
		{
			j = i - 1;
			while (j++ <= (int)ft_strlen(str) - (int)ft_strlen(to_remove))
				str[j] = str[j + (int)ft_strlen(to_remove)];
			break ;
		}
	}
}
