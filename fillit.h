/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:18:21 by mchevall          #+#    #+#             */
/*   Updated: 2016/01/19 17:10:06 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
 #define FILLIT_H
 #include "libft.h"
 #include <stdlib.h>
 #include <fcntl.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/uio.h>
 #include <unistd.h>

 #define SIZE_BUFF 547

typedef struct	s_map
{
	int		c_range;
	int		m_range;
	int		c_pos;
	int		nb_tetri;
	int		**tetrilist;
	char	**map;
	char	**solution;
}				t_map;

int				ischar(char character);
int				valid_block(char *s);
int				valid_buf(char *s);
int				valid_map(char *s);
int				ft_read(int const fd, t_map *map);
int				check_space(t_map *map);
int				range_min(t_map *map);
void			put_tetri(t_map *map);
int				update_pos(t_map *map);
void			erase_tetri(t_map *map, int i);
int				solve(t_map *map, int i);
char			**solution_cpy(t_map *map);

#endif
