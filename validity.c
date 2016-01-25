/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 18:43:32 by dgalide           #+#    #+#             */
/*   Updated: 2016/01/25 18:23:58 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ischar(char character)
{
	if (character == '.' || character == '#' || character == '\n')
		return (1);
	return (0);
}

int				check_1(char *buff, int ret)
{
	int			j;
	int			k;
	int			l;
	int			i;

	i = ((ret + 1) / 21);
	j = 4;
	k = 0;
	while (k < i)
	{
		l = 0;
		while (l < 5)
		{
			if (j < (ret - 1) && buff[j] != '\n')
				return (0);
			if (l != 3)
				j += 5;
			else
				j += 1;
			l++;
		}
		k++;
	}
	return (1);
}

void			check(char *str, int ret)
{
	if (((ret + 1) % 21) != 0)
		ft_error();
	if (check_1(str, ret) == 0)
		ft_error();
}

int				ft_neighbor_utils(char **piece, int i, int j, int *k)
{
	int	l;

	l = 0;
	*k = *k + 1;
	if ((j + 1) < 4 && piece[i][j + 1] == '#')
		l++;
	if ((j - 1) > -1 && piece[i][j - 1] == '#')
		l++;
	if ((i + 1) < 4 && piece[i + 1][j] == '#')
		l++;
	if ((i - 1) > -1 && piece[i - 1][j] == '#')
		l++;
	return (l);
}

int				ft_neighbor(char **piece)
{
	int			i;
	int			j;
	int			l;
	int			k;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (ischar(piece[i][j]) == 0)
				return (0);
			if (piece[i][j] == '#')
				l += ft_neighbor_utils(piece, i, j, &k);
			j++;
		}
		i++;
		j = 0;
	}
	return (((l == 6 || l == 8) && k == 4) ? 1 : 0);
}
