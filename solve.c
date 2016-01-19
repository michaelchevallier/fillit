/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 18:04:24 by mchevall          #+#    #+#             */
/*   Updated: 2016/01/19 16:32:42 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solve(t_map *map, int i)
{
	if (i > map->nb_tetri)
		return (1);
	if (map->tetrilist[i][8] == 0)
	{
		/*if (check_space(map))
		  {
		  put_tetri(map);
		  map.tetrilist[i][8] = 1;
		  map.c_pos = update_pos(map);
		  }
		  else if (map.c_pos > map.c_range * map.c_range)
		  {*/
		while (!check_space(map))
		{
			map->c_pos++;
			if(map->c_pos > map->c_range * map->c_range)
			{
				erase_tetri(map, i - 1);
				map->tetrilist[i - 1][8] = 0;
				solve(map, i);
			}
		}
		put_tetri(map);
		map->tetrilist[i][8] = 1;
		map->c_pos = update_pos(map);
		//}
		solve(map, i + 1);
	}
	else
		solve(map, i + 1);
	return (1);
}
