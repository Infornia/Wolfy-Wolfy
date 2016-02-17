/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wolfy_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 20:00:33 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/02 19:32:08 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolfy.h"

int		init_map(t_data *d)
{
	int	fd;

	if ((fd = open(d->map_name, O_RDONLY)) == -1)
	{
		ft_puts("I can't open map");
		return (0);
	}
	if (get_map(d, fd, 0, 0) == 1)
	{
		ft_puts("Your map is in wrong format");
		return (0);
	}
	close(fd);
	return (0);
}

int		get_map(t_data *d, int fd, int x, int y)
{
	char *s;

	while (get_next_line(fd, &s))
	{
		while (s[x])
		{
			d->map[y][x] = s[x] - 48;
			++x;
			if (x > MAP_SIZE + 1)
				return (1);
		}
		if (!s[x])
		{
			++y;
			x = 0;
			if (y > MAP_SIZE + 1)
				return (1);
		}
		else
			return (1);
		ft_strdel(&s);
	}
	return (0);
}
