/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_cpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 16:25:52 by mchevall          #+#    #+#             */
/*   Updated: 2016/01/19 17:49:43 by mchevall         ###   ########.fr       */
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
