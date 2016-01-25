/* ************************************************************************ */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 18:04:24 by mchevall          #+#    #+#             */
/*   Updated: 2016/01/25 15:25:18 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

int			find(t_map *map, int i, int rvalue)
{
	int	j;
	static int nb_passage;

	nb_passage++;
	printf("\n nb passage: %d\n",nb_passage);

	printf("\n map crange: %d\n",map->c_range);
	ft_printtab(map->map);
	ft_putchar('\n');
	j = 0;
	if (map->placed_tetri == map->nb_tetri)
	{
		solution_cpy(map);
		map->s_range = map->c_range;

		ft_printtab(map->map);
		return (rvalue);
	}
	if (map->tetrilist[i][8] == 0)
	{
		if (check_space(map, map->tetrilist[i]) == 1)
		{
			put_tetri(map, i);
			update_pos(map);
			while (map->tetrilist[j][8] == 1 && j < map->nb_tetri - 1)
				j++;
			return (find(map, j, rvalue));
		}
		else
		{
			while (update_pos(map) != 0)
			{
				if (check_space(map, map->tetrilist[i]) == 1)
				{
					put_tetri(map, i);
					return (find(map, (i + 1), rvalue));
				}
			}
			erase_tetri(map, (i - 1));
			update_pos(map);
			return(find(map, i, rvalue));
		}
	}
	else
		return(find(map, i + 1, rvalue));
	return (rvalue);
}

int			solve(t_map *map)
{
	int	rvalue;

	rvalue = 0;
	find(map, 0, rvalue);
	return (rvalue);
}

void		print_solution(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map->s_range)
	{
		while (j < map->s_range)
		{
			ft_putchar(map->solution[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}
