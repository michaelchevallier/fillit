/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:52:20 by dgalide           #+#    #+#             */
/*   Updated: 2016/01/25 18:06:32 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

void			solve(t_map *map)
{
	int			i;

	i = 0;
	find(map, i);
	map->c_range--;
	while (i < map->nb_tetri)
	{
		map->tetrilist[i][8] = 0;
		i++;
	}
	load_map(map);
}

int				main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ft_read(fd, map);
		map->c_range = 13;
		map->solution = NULL;
		load_map(map);
		while (map->c_range + 1 != map->m_range)
			solve(map);
		print_solution(map);
	}
	return (0);
}
