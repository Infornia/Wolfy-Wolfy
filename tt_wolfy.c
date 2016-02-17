/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt_wolfy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 20:04:39 by mwilk             #+#    #+#             */
/*   Updated: 2016/02/17 20:21:40 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolfy.h"

static void		wolfynit(t_data *d)
{
//	init_mlx(d);
//	init_val(d);
//	init_map(d);
	d->go = 1;
}

void		wolfydel(t_data *d)
{
	mlx_destroy_image(d->mlx, d->img);
	mlx_destroy_window(d->mlx, d->win);
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
