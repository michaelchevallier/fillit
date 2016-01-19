/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:48:05 by mchevall          #+#    #+#             */
/*   Updated: 2016/01/19 16:06:49 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		range_min(t_map map)
{
	int		i;

	i = 0;
	while (i * i <= map.nb_tetri)
		i++;
	if (i * i == map.nb_tetri)
	{
		map.m_range = i;
		return(1);
	}
	else
	{
		map.m_range = i + 1;
		return (0);
	}
}
