/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 15:47:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/14 19:49:29 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolfy.h"

int			put_error(char *s)
{
	ft_putendl_fd(s, 2);
	return (-1);
}

Uint32		getpixel(int x, int y, t_data *d)
{
	(void)x;
	(void)y;
	if (d->r.side == 0 && d->map[d->r.mapx][d->r.mapy] == 1)
		return (0xFF000FF);
	if (d->r.side == 1 && d->map[d->r.mapx][d->r.mapy] == 1)
		return (0xFF0FF00);
	if (d->map[d->r.mapx][d->r.mapy] == 3)
		return (0xFFF0000);
	if (d->map[d->r.mapx][d->r.mapy] > 3)
		return (0xFF00000);
	return (0xFF00000);
}

void		make_color(Uint32 color, Uint32 *rgb, int k, t_data *d)
{
	if (d->r.side == 0 && d->r.ray_dx < 0 && k == 0)
		color = (color >> 1) & 8355711;
	else if (d->r.side == 1 && d->r.ray_dy > 0 && k == 0)
		color = (color >> 1) & 8355711;
	rgb[0] = (color & 0x00ff0000) >> 16;
	rgb[1] = (color & 0x0000ff00) >> 8;
	rgb[2] = (color & 0x000000ff);
}
