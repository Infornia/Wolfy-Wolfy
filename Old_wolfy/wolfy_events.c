/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolfy_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 21:11:20 by mwilk             #+#    #+#             */
/*   Updated: 2016/02/11 22:10:06 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolfy.h"

void		expose_hook(t_data *d)
{
	mlx_do_sync(d->mlx);
	mlx_put_image_to_window(d->mlx, d->win, d->screen.img, 0, 0);
}
void		key_hook(int key, t_data *d)
{
	printf("%i\n", key);
	if (key == ESC)
		wolfydel(d);
}

void		mouse_hook(int button, int x, int y, t_data *d)
{
	if (button == 1)
	{
		d->click_x = x;
		d->click_y = y;
	}
}
