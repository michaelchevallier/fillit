/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:18:21 by mchevall          #+#    #+#             */
/*   Updated: 2016/01/12 18:41:23 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <unistd.h>

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
int				read_map(const char *path);
int				check_space(t_map map);
void			put_tetri(t_map map);
int				update_pos(t_map map);
void			erase_tetri(t_map map, int i);

#endif
