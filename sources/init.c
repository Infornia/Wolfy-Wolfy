/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:16:34 by mwilk             #+#    #+#             */
/*   Updated: 2016/11/24 14:55:22 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

// static void		create_map(int **map, int fd, int x, int y)
// {
// 	char	buff[x];
// 	int		r;
// 	int		i;
// 	
// 	if (!(map = malloc(sizeof(int *) * (y + 1))))
// 		exit(tt_ps("map alloc error\n"));
// 	map[y] = NULL;
// 	while ((r = read(fd, buff, BUFF_SIZE)) && (i = -1))
// 	{
// 		printf("buff: %s\n", buff);
// 		while (++i < r)
// 		{
// 			if (buff[i] == ',')
// 				continue;
// 			if (buff[i] == '\n' && ++j)
// 				size_line = -2;
// 		}
// 	}
// }
// 
// void		init_map(t_data *d, char *name)
// {
// 	int		size_line;
// 	int		r;
// 	int		i;
// 	char	buff[BUFF_SIZE];
// 	
// 	if ((d->fd = open(name, O_RDONLY)) == -1)
// 		exit(tt_ps("Failed to open file\n"));
// 	d->map_x = 0;
// 	d->map_y = 0;
// 	size_line = -1;
// 	while ((r = read(d->fd, buff, BUFF_SIZE)) && (i = -1))
// 	{
// 		printf("buff: %s\n", buff);
// 		while (++i < r)
// 		{
// 			if (buff[i] == ',')
// 				continue;
// 			if (buff[i] == '\n' && ++d->map_y)
// 				size_line = -2;
// 			if (size_line != -2)
// 				d->map_x++;
// 		}
// 	}
// 	printf("LOL %d, %d\n", --d->map_x, d->map_y);
// 	close(d->fd);
// 	if ((d->fd = open(name, O_RDONLY)) == -1)
// 		exit(tt_ps("Failed to open file\n"));
// 	d->map = create_map(d->fd, d->map_x + 1, d->map_y + 1);
// 	close(d->fd);
// }

t_data			*init(char *name)
{
	t_data		*d;

	d = tt_malloc(sizeof(t_data));
	init_mlx(d);
	// init_map(d, name);
	return (d);
}