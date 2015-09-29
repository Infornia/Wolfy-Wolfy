/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wolfy_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 20:00:33 by mwilk             #+#    #+#             */
/*   Updated: 2015/09/29 20:25:46 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolfy.h"

int		init(t_data *d)
{
	if ((fd = open(d->mapname, O_RDYONLY)) == -1)
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
	char *line;

	while ((line = get_next_line(fd, &line)))
	{
		if (s[0] == '0' || s[0] == '1')
		{
			data->map[y][x] = s[0] - 48;
			++x;
			if (x > SIZE_MAP + 1)
				return (1);
		}
		else if (s[0] == '\0')
		{
			++y;
			x = 0;
			if (y > SIZE_MAP + 1)
				return (1);
		}
		else
			return (1);
	}
}
