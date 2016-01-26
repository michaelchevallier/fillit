/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:15:48 by dgalide           #+#    #+#             */
/*   Updated: 2016/01/25 19:14:04 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_space(t_map *map, int *lst, int x, int y)
{
	int	a;
	int	b;
	int	i;
	int l;

	i = 0;
	l = 0;
	while (i < 8)
	{
		a = lst[i];
		b = lst[i + 1];
		if (((((x + a) < map->c_range) && ((x + a) > -1)) &&
					((((y + b) < map->c_range)) &&
					((y + b) > -1))) && map->map[(x + a)][(y + b)] == '.')
			l++;
		i += 2;
	}
	return ((l == 4) ? 1 : 0);
}

void		put_tetri(t_map *map, int i, int x, int y)
{
	int		a;
	int		b;

	a = map->tetrilist[i][0];
	b = map->tetrilist[i][1];
	map->map[x + a][y + b] = (char)(i + 65);
	a = map->tetrilist[i][2];
	b = map->tetrilist[i][3];
	map->map[x + a][y + b] = (char)(i + 65);
	a = map->tetrilist[i][4];
	b = map->tetrilist[i][5];
	map->map[x + a][y + b] = (char)(i + 65);
	a = map->tetrilist[i][6];
	b = map->tetrilist[i][7];
	map->map[x + a][y + b] = (char)(i + 65);
	map->tetrilist[i][8] = 1;
	map->placed_tetri++;
}

void		erase_tetri(t_map *map, int i)
{
	int		x;
	int		y;
	int		a;
	int		b;

	if (map->rvalue != 1)
	{
		map_xy_chr(map, &x, &y, (i + 65));
		a = map->tetrilist[i][0];
		b = map->tetrilist[i][1];
		map->map[x + a][y + b] = '.';
		a = map->tetrilist[i][2];
		b = map->tetrilist[i][3];
		map->map[x + a][y + b] = '.';
		a = map->tetrilist[i][4];
		b = map->tetrilist[i][5];
		map->map[x + a][y + b] = '.';
		a = map->tetrilist[i][6];
		b = map->tetrilist[i][7];
		map->map[x + a][y + b] = '.';
		map->tetrilist[i][8] = 0;
		map->placed_tetri--;
		map->c_pos[0] = x;
		map->c_pos[1] = y;
	}
}
