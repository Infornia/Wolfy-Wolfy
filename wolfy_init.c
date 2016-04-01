/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolfy_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 21:43:00 by mwilk             #+#    #+#             */
/*   Updated: 2016/04/01 23:52:58 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolfy.h"

void	init_mlx(t_data *d)
{
	if (!(d->mlx = mlx_init()))
		exit(tt_ps("Error: Failed to init mlx", -1));
	if (!(d->win = mlx_new_window(d->mlx, WINX, WINY, "Wolf3d")))
		exit(tt_ps("Error: Failed to create window", -2));
	if (!(d->img = mlx_new_image(d->mlx, WINX, WINY)))
		exit(tt_ps("Error: Failed to create img", -3));
	if (!(d->dimg = mlx_get_data_addr(d->img, &d->bpp, &d->size_line, &d->endian)))
		exit(tt_ps("Error: Failed to get img data", -4));
}

void	init_val(t_data *d)
{
	d->dimg_size = WINX * WINY * 4;
	d->map_size = 1;
}

int		init_map(t_data *d)
{
	int		fd;
	int		i;
	int		j;
	int		ret;
	char	*line;

	line = NULL;
	j = -1;
	if ((fd = open(d->file, O_RDONLY)) == -1)
		exit(tt_ps("Error: Failed to open file", -5));
	while ((ret = get_next_line(fd, &line)) > 0 && ++j < d->map_size)
	{
		if (!j && (d->map_size = ret))
			d->map = tt_malloc_intab(ret, ret);
		i = -1;
		while (++i < d->map_size && line[i])
			d->map[j][i] = line[i] - '0';
		ft_strclr(&line[0]);
	}
	tt_printintab(d->map, d->map_size, d->map_size);
	close(fd);
	return (1);
}
