/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:49:32 by dgalide           #+#    #+#             */
/*   Updated: 2016/01/26 13:51:16 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void			relativ_pos(char **piece, t_map *map, int nb)
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
	map->rvalue = 0;
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
	char		buff[SIZE_BUFF];
	char		**tmp;
	int			ret;
	int			j;
	int			k;

	j = 0;
	k = 0;
	ret = read(fd, buff, SIZE_BUFF);
	if (ret == -1)
		ft_error();
	check(buff, ret);
	map->tetrilist = malloc_list(((ret + 1) / 21));
	while (k < ((ret + 1) / 21))
	{
		tmp = buff_to_tab(ft_strsub(buff, j, 20));
		if (ft_neighbor(tmp) == 0)
			ft_error();
		relativ_pos(tmp, map, k);
		j += 21;
		k++;
	}
	map->nb_tetri = ((ret + 1) / 21);
}
