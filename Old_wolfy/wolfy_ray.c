/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolfy_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 19:55:31 by mwilk             #+#    #+#             */
/*   Updated: 2016/02/11 16:10:58 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolfy.h"

static void	DDA(t_data *d)
{
	while (d->map[d->r.mapx][d->r.mapy] < 2)
	{
		if (d->r.side_x < d->r.side_y)
		{
			d->r.side_x += d->r.delta_x;
			d->r.mapx += d->r.stepx;
			d->r.side = 0;
		}
		else
		{
			d->r.side_y += d->r.delta_y;
			d->r.mapy += d->r.stepy;
			d->r.side = 1;
		}
	}
}

static void	raydir(t_data *d)
{
	if (d->r.ray_dx < 0)
	{
		d->r.stepx = -1;
		d->r.side_x = (d->r.ray_x - d->r.mapx) * d->r.delta_x;
	}
	else
	{
		d->r.stepx = 1;
		d->r.side_x = (d->r.mapx + 1.0 - d->r.ray_x) * d->r.delta_x;
	}
	if (d->r.ray_dy < 0)
	{
		d->r.stepy = -1;
		d->r.side_y = (d->r.ray_y - d->r.mapy) * d->r.delta_y;
	}
	else
	{
		d->r.stepy = 1;
		d->r.side_y = (d->r.mapy + 1.0 - d->r.ray_y) * d->r.delta_y;
	}
}

static void	init_r(int x, t_data *d)
{
	d->r.camx = 2 * x / (double)WINX - 1;
	d->r.ray_x = d->c.posx;
	d->r.ray_y = d->c.posy;
	d->r.ray_dx = d->c.dirx + d->c.planx * d->r.camx;
	d->r.ray_dy = d->c.diry + d->c.plany * d->r.camx;
	d->r.mapx = (int)d->c.posx;
	d->r.mapy = (int)d->c.posy;
	d->r.delta_x =
		sqrt(1 + (d->r.ray_dy * d->r.ray_dy) / (d->r.ray_dx * d->r.ray_dx));
	d->r.delta_y =
		sqrt(1 + (d->r.ray_dx * d->r.ray_dx) / (d->r.ray_dy * d->r.ray_dy));
}

void		raycast(t_data *d)
{
	int		x;
	double	wd;

	x = 0;
	while (x < WINX)
	{
		init_r(x, d);
		raydir(d);
		DDA(d);
		if (d->r.side == 0)
		{
			wd = (d->r.mapx - d->r.ray_x + (1 - d->r.stepx) / 2) / d->r.ray_dx;
			d->r.wallx = d->r.ray_y + wd * d->r.ray_dy;
		}
		else
		{
			wd = (d->r.mapy - d->r.ray_y + (1 - d->r.stepy) / 2) / d->r.ray_dy;
			d->r.wallx = d->r.ray_x + wd * d->r.ray_dx;
		}
		d->r.wall_dist = fabs(wd);
		d->r.line_h = abs((int)(WINY / d->r.wall_dist));
		d->r.wallx -= floor(d->r.wallx);
		wall3d(x, d);
		x++;
	}
}
