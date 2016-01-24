#include "fillit.h"
#include <stdio.h>

int			update_pos(t_map *map)
{
	int		x;
	int		y;

	x = map->c_pos[0];
	y = map->c_pos[1] + 1;
	while (x < map->c_range)
	{
		while (y < map->c_range)
		{
			if (map->map[x][y] == '.')
			{
				map->c_pos[0] = x;
				map->c_pos[1] = y;
				return (1);
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}

int			check_space(t_map *map, int *lst)
{
	int	x;
	int	y;
	int	a;
	int	b;
	int	l;

	x = map->c_pos[0];
	y = map->c_pos[1];
	a = lst[0];
	b = lst[1];
	l = 0;
	if (((((x + a) < map->c_range) && ((x + a) > -1)) && ((((y + b) < map->c_range)) && ((y + b) > -1))) && map->map[(x + a)][(y + b)] == '.')
		l++;
	a = lst[2];
	b = lst[3];
	if (((((x + a) < map->c_range) && ((x + a) > -1)) && ((((y + b) < map->c_range)) && ((y + b) > -1))) && map->map[(x + a)][(y + b)] == '.')
		l++;
	a = lst[4];
	b = lst[5];
	if (((((x + a) < map->c_range) && ((x + a) > -1)) && ((((y + b) < map->c_range)) && ((y + b) > -1))) && map->map[(x + a)][(y + b)] == '.')
		l++;
	a = lst[6];
	b = lst[7];
	if (((((x + a) < map->c_range) && ((x + a) > -1)) && ((((y + b) < map->c_range)) && ((y + b) > -1))) && map->map[(x + a)][(y + b)] == '.')
		l++;
	return ((l == 4)? 1: 0); 
}

void		put_tetri(t_map *map, int i)
{
	int		x;
	int		y;
	int		a;
	int		b;

	x = map->c_pos[0];
	y = map->c_pos[1];
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

int		erase_tetri(t_map *map, int i)
{
	int		x;
	int		y;
	int		a;
	int		b;
	static int z;

	z++;
	if (z == 10)
		ft_error();

	if (i > -1 && i < map->nb_tetri)
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
		return (1);
	}
	return 0;
}
