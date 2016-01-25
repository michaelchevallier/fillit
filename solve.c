/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 18:04:24 by mchevall          #+#    #+#             */
/*   Updated: 2016/01/25 17:34:49 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			loop(t_map *map, int i, int j, int k)
{
	put_tetri(map, i, j, k);
	if (map->placed_tetri == map->nb_tetri)
	{
		map->rvalue = 1;
		solution_cpy(map);
		map->s_range = map->c_range;
		return ;
	}
	else if (map->rvalue != 1)
	{
		find(map, (i + 1));
		erase_tetri(map, i);
	}
}

void			find(t_map *map, int i)
{
	int		j;
	int		k;

	k = 0;
	j = 0;
	if (map->rvalue != 1)
	{
		while (j < map->c_range)
		{
			while (k < map->c_range)
			{
				if (check_space(map, map->tetrilist[i], j, k) == 1)
					loop(map, i, j, k);
				k++;
			}
			j++;
			k = 0;
		}
	}
}
