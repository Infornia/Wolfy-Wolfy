/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt_wolfy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 20:04:39 by mwilk             #+#    #+#             */
/*   Updated: 2016/04/01 22:46:19 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolfy.h"

static void		wolfynit(t_data *d)
{
	init_mlx(d);
	printf("mlx initiated:\tbpp: %i\tsize_line: %i\tendian: %i\n",
			d->bpp, d->size_line, d->endian);
	init_val(d);
	printf("val\n");
	init_map(d);
	printf("map\n");
	d->go = 1;
}

void		wolfydel(t_data *d)
{
	mlx_destroy_image(d->mlx, d->img);
	mlx_destroy_window(d->mlx, d->win);
	exit(0);
}

void		tt_wolfy(t_data *d, char *file)
{
	d->file = file;
	wolfynit(d);
	mlx_hook(d->win, 2, 1, key_hook, d);
	mlx_hook(d->win, 4, 4, mouse_hook, d);
	mlx_hook(d->win, 6, 16, mouse_hook_move, d);
	mlx_expose_hook(d->win, expose_hook, d);
	mlx_loop(d->mlx);
}
