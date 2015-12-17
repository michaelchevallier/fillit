/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:29:49 by mchevall          #+#    #+#             */
/*   Updated: 2015/12/17 21:06:22 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			valid_buf_format(char *s)
{
	int		i;
	int		nbc;
	int		nbn;

	i = 0;
	nbc = 0;
	nbn = 0;
	while (i < 21)
	{
		if ((ischar(s[i]) == 0 && s[i] != '\0') || nbc > 4 || nbn > 5)
			return (0);
		if (((i + 1) % 5) == 0 && s[i] != '\n')
			return (0);
		if (s[20] != '\n' && s[20] != '\0')
			return (0);
		if (s[i] == '#')
			nbc++;
		if (s[i] == '\n')
			nbn++;
		i++;
	}
	if (nbc != 4 || (nbn != 5 && !(nbn == 4 && s[20] == '\0')))
		return (0);
	return (1);
}

int			valid_block_format(char *s)
{
	int		i;
	int		valid;

	i = 0;
	valid = 0;
	while (i < 19)
	{
		if (s[i] == '#')
		{
			if (i == 0 && (s[i + 5] == '#' || s[i + 1] == '#'))
					valid++;
			if (i > 0 && i < 5 && (s[i - 1] == '#' || s[i + 1] == '#' ||
					s[i + 5] == '#'))
					valid++;
			if (i > 4 && i < 14 && (s[i - 1] == '#' || s[i + 1] == '#' ||
					s[i + 5] == '#' || s[i - 5] == '#'))
				valid++;
			if (i > 14 && (s[i - 1] == '#' || s[i + 1] == '#' ||
						s[i - 5] == '#'))
				valid++;
		}
	i++;
	}
	return ((valid == 4) ? 1 : 0);
}

int			main(void)
{
	char tab[21] = {'#','#','#','.', '\n','#', '.', '.', '.', '\n','.','.','.','.', '\n','.', '.', '.','.', '\n','\n'};

	ft_putnbr(valid_block_format(tab) + valid_buf_format(tab)) ;
	return (0);
}
