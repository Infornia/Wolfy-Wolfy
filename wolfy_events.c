/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolfy_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 21:11:20 by mwilk             #+#    #+#             */
/*   Updated: 2016/04/01 05:32:31 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolfy.h"

int		expose_hook(t_data *d)
{
	mlx_do_sync(d->mlx);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
//	ft_bzero(d->dimg, d->dimg_size);
	return(0);
}
int		key_hook(int key, t_data *d)
{
	printf("The key: %i\n", key);
	if (key == ESC)
		wolfydel(d);
	else if (key == KEY1)
		d->draw = 0;
	else if (key == KEY2)
		d->draw = 1;
	return(0);
}

int		mouse_hook(int button, int x, int y, t_data *d)
{
	(void)d;
	printf("Button pressed: %i\t X: %i\t Y: %i\n", button, x, y);
	return(0);
}

int		mouse_hook_move(int x, int y, t_data *d)
{
	(void)d;
	printf("Move x: %i\t y: %i\n", x, y);
	if (d->draw == 1)
		color_pixel(d, RGB(255, 0, 0), x, y);
	expose_hook(d);
	return(0);
}
