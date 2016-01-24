/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 13:57:02 by dgalide           #+#    #+#             */
/*   Updated: 2016/01/24 18:42:18 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char			**buff_to_tab(char *str)
{
	int			i;
	int			j;
	char		**tab;

	i = 0;
	j = 0;
	tab = ft_maketab(5, 4);
	while (i < 4)
	{
		tab[i] = ft_strsub(str, j, 4);
		j += 5;
		i += 1;
	}
	tab[i] = NULL;
	return (tab);
}

int	xychr(char **tab, int *x, int *y, char c)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	ft_putchar(c);
	while (i < 4)
	{
		while (j < 4)
		{
			if (tab[i][j] == c)
			{
				*x = i;
				*y = j;
				return 1;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return 0;
}

int	map_xy_chr(t_map *map, int *x, int *y, char c)
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
				return 1;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return 0;
}

void				relativ_pos(char **piece, t_map *map, int nb)
{
	int i;
	int	j;
	int	k;
	int	l;
	int	m;

	l = 0;
	xychr(piece, &m, &k, '#');
	i = m;
	j = k;
	while (i < 4)
	{
		while (j < 4)
		{
			if (piece[i][j] == '#')
			{
				map->tetrilist[nb][l] = i - m;
				map->tetrilist[nb][l + 1] = j - k;
				l += 2;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void			print_lst(t_map *map)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < map->nb_tetri)
	{
		while (j < 9)
		{
			ft_putnbr(map->tetrilist[i][j]);
			ft_putchar(',');
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
}

int				**malloc_list(int nb_tetri)
{
	int			**tetrilist;
	int			i;

	i = 0;
	tetrilist = (int **)malloc(sizeof(int *) * nb_tetri);
	while (i < nb_tetri)
	{
		tetrilist[i] = (int *)malloc(sizeof(int) * 9);
		ft_bzero(tetrilist[i], 9);
		i++;
	}
	return (tetrilist);
}

void			load_map(t_map *map)
{
	int			i;

	i = 0;
	map->m_range = range_min(map->nb_tetri);
	map->c_pos = (int *)malloc(sizeof(int) * 2);
	ft_bzero(map->c_pos, 2);
	map->map = ft_maketab(map->c_range, map->c_range);
	map->placed_tetri = 0;
	while (i < map->c_range)
	{
		ft_memset(map->map[i], '.', map->c_range);
		i++;
	}
}

void			ft_read(int const fd, t_map *map)
{
	char 		buff[SIZE_BUFF];
	char		**tmp;
	int			ret;
	int			i;
	int			j;
	int			k;

	j = 0;
	k = 0;
	ret = read(fd, buff, SIZE_BUFF);
	check(buff, ret);
	i = ((ret + 1) / 21);
	map->tetrilist = malloc_list(i);
	while (k < i)
	{
		tmp = buff_to_tab(ft_strsub(buff, j, 20));
		if (ft_neighbor(tmp) == 0)
			ft_error();
	    relativ_pos(tmp, map, k);
		j += 21;
		k++;
	}
	map->nb_tetri = i;
}

int				main(int argc, char **argv)
{
	int		fd;
	int		solve_result;
	int		i;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	solve_result = -1;
	i = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ft_read(fd, map);
		map->c_range = 13;
		load_map(map);
		print_lst(map);
		map->solution = NULL;
		while (map->c_range + 1 != map->m_range)
		{
			i = 0;
			solve_result = solve(map);
			map->c_range--;
			while (i < map->nb_tetri)
			{
				map->tetrilist[i][8] = 0;
				i++;
			}
			load_map(map);
		}
		printf("Solution print:\n\n");
		print_solution(map);
		ft_putchar('\n');
		printf("Taille_map;%d\n", map->s_range);
	}
	return (0);
}
