/* ************************************************************************ */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 18:04:24 by mchevall          #+#    #+#             */
/*   Updated: 2016/01/24 20:46:30 by dgalide          ###   ########.fr       */
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

int			find(t_map *map, int i, int rvalue)
{
	int		j;
	int		k;

	ft_putchar('\n');
	ft_printtab(map->map);
	if (map->placed_tetri == map->nb_tetri)
	{
		ft_putchar('A');
		solution_cpy(map);
		return (0);
	}
	if (i < 0 || i == map->nb_tetri)
	{
		ft_putchar('B');
		i = 0;
	}
	if (map->tetrilist[i][8] == 1)
	{
		ft_putchar('C');
		return (find(map, (i + 1), rvalue));
	}
	else
	{
		printf("tetri num %d\n", i);
		ft_putchar('D');
		while (check_space(map, map->tetrilist[i]) == 0)
		{
			ft_putchar('E');
			if (update_pos(map) == 0)
			{
				ft_putchar('F');
				printf("\nmap->last = %d ||| return erase = %d\n" ,map->last, erase_tetri(map, (map->last)));
				map->last--;
				return(find(map, i, rvalue));
			}
		}
		ft_putchar('G');
		put_tetri(map, i);
		map->last = i;
		return (find(map, (i + 1), rvalue));
	}
	return (0);
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
