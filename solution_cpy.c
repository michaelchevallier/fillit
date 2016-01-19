/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_cpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 16:25:52 by mchevall          #+#    #+#             */
/*   Updated: 2016/01/19 17:35:07 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**solution_cpy(t_map *map)
{
	char	**solution;
	int		i;

	i = 0;
	if (map->solution)
	{
		while (map->solution[i])
		{
			ft_strdel(map->solution);
			i++;
		}
	}
	i = 0;
	solution = (char **)ft_memalloc(sizeof(char *) * map->c_range + 1);
	solution[map->c_range] = NULL;
	while (i < map->c_range)
	{
		solution[i] = ft_strdup(map->map[i]);
		i++;
	}
	return(solution);
}

#include <stdio.h>

int main()
{
	t_map *map;
	int i;

	map->c_range = 5;
	map->nb_tetri = 7;
	i = 0;
	map->solution = NULL;
	map->map = (char **)ft_memalloc(sizeof(char *) * map->c_range + 1);
	map->map[map->c_range] = NULL;

	while (i < map->c_range)
	{
		map->map[i] = ft_strdup("a");
		i++;
	}
	i = 0;
	while (i < map->c_range)
	{
		map->solution = solution_cpy(map);
		printf("%s\n", map->solution[i]);
		i++;
	}
	range_min(map);
	printf("%d\n", map->m_range);
}
