/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 17:37:48 by mchevall          #+#    #+#             */
/*   Updated: 2016/01/19 17:38:22 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

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
