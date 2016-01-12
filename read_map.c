/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:18:34 by mchevall          #+#    #+#             */
/*   Updated: 2016/01/12 17:51:35 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_map(const char *path)
{
	int		fd;
	int		ret;
	char	buf[22];
	int		valid;

	valid = 0;
	ret = 1;
	fd = clean_open(path, O_RDONLY);
	while (ret != 0)
	{
		ret = clean_read(fd, buf, 21);
		if ((valid_map(buf) == 0) || valid > 26)
		{
			ft_putstr("error");
			exit(EXIT_FAILURE);
		}
		valid++;
	}
	return (valid);
}
