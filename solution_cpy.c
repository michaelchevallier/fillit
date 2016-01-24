/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_cpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 16:25:52 by mchevall          #+#    #+#             */
/*   Updated: 2016/01/24 20:08:15 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solution_cpy(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!map->solution)
		map->solution = ft_maketab(map->c_range, map->c_range);
	while (i < map->c_range)
	{
		while (j < map->c_range)
		{
			map->solution[i][j] = map->map[i][j];
			j++;
		}
		j = 0;
		i++;
	}
}
