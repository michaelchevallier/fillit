/* ************************************************************************ */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 18:04:24 by mchevall          #+#    #+#             */
/*   Updated: 2016/01/25 16:42:31 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

int			check_behind(t_map *map, int i)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (j < i)
	{
		if (map->tetrilist[j][8] == 0)
			return (j);
		j++;
	}
	return (-1);
}

void			find(t_map *map, int i)
{
	int		j;
	int		k;
	static long long int dodo;

	k = 0;
	j = 0;
	//printf("rvalue = %d\n", map->rvalue);
	if (map->rvalue != 1)
	{
		while (j < map->c_range)
		{
			while (k < map->c_range)
			{
				if (check_space(map, map->tetrilist[i], j, k) == 1)
				{
					put_tetri(map, i, j, k);
					dodo++;
					if (dodo == 100000000)
					{
					ft_putchar('\n');
					ft_printtab(map->map);
					ft_putchar('\n');
					dodo = 0;
					}
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
				k++;
			}
			j++;
			k = 0;
		}
	}
}

void		solve(t_map *map)
{
	find(map, 0);
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
