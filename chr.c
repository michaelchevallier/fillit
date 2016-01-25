/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:50:14 by dgalide           #+#    #+#             */
/*   Updated: 2016/01/25 17:51:45 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				xychr(char **tab, int *x, int *y, char c)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (tab[i][j] == c)
			{
				*x = i;
				*y = j;
				return (1);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int				map_xy_chr(t_map *map, int *x, int *y, char c)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->c_range)
	{
		while (j < map->c_range)
		{
			if (map->map[i][j] == c)
			{
				*x = i;
				*y = j;
				return (1);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
