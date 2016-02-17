/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolfy_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 21:11:20 by mwilk             #+#    #+#             */
/*   Updated: 2016/02/17 20:22:33 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolfy.h"

int		expose_hook(t_data *d)
{
	mlx_do_sync(d->mlx);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return(0);
}
int		key_hook(int key, t_data *d)
{
	printf("%i\n", key);
	if (key == ESC)
		wolfydel(d);
	return(0);
}

int		mouse_hook(int button, int x, int y, t_data *d)
{
	printf("%s, %i, %i, %i", d->file, button, x, y);
	return(0);
}

int		mouse_hook_move(int x, int y, t_data *d)
{
	printf("%s, %i, %i", d->file, x, y);
	return(0);
}
