/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolfy_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 19:55:31 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/09 20:09:12 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolfy.h"

static void	rayside(t_wolf *w)
{
	while (w->map[w->r.mapx][w->r.mapy] < 2)
	{
		if (w->r.side_x < w->r.side_y)
		{
			w->r.side_x += w->r.delta_x;
			w->r.mapx += w->r.stepx;
			w->r.side = 0;
		}
		else
		{
			w->r.side_y += w->r.delta_y;
			w->r.mapy += w->r.stepy;
			w->r.side = 1;
		}
	}
}

static void	raydir(t_wolf *w)
{
	if (w->r.ray_dx < 0)
	{
		w->r.stepx = -1;
		w->r.side_x = (w->r.ray_x - w->r.mapx) * w->r.delta_x;
	}
	else
	{
		w->r.stepx = 1;
		w->r.side_x = (w->r.mapx + 1.0 - w->r.ray_x) * w->r.delta_x;
	}
	if (w->r.ray_dy < 0)
	{
		w->r.stepy = -1;
		w->r.side_y = (w->r.ray_y - w->r.mapy) * w->r.delta_y;
	}
	else
	{
		w->r.stepy = 1;
		w->r.side_y = (w->r.mapy + 1.0 - w->r.ray_y) * w->r.delta_y;
	}
}

static void	init_r(int x, t_wolf *w)
{
	w->r.camx = 2 * x / (double)WIN_X - 1;
	w->r.ray_x = w->c.posx;
	w->r.ray_y = w->c.posy;
	w->r.ray_dx = w->c.dirx + w->c.planx * w->r.camx;
	w->r.ray_dy = w->c.diry + w->c.plany * w->r.camx;
	w->r.mapx = (int)w->c.posx;
	w->r.mapy = (int)w->c.posy;
	w->r.delta_x =
		sqrt(1 + (w->r.ray_dy * w->r.ray_dy) / (w->r.ray_dx * w->r.ray_dx));
	w->r.delta_y =
		sqrt(1 + (w->r.ray_dx * w->r.ray_dx) / (w->r.ray_dy * w->r.ray_dy));
}

void		raycast(t_wolf *w)
{
	int		x;
	double	wd;

	x = 0;
	while (x < WIN_X)
	{
		init_r(x, w);
		raydir(w);
		rayside(w);
		if (w->r.side == 0)
		{
			wd = (w->r.mapx - w->r.ray_x + (1 - w->r.stepx) / 2) / w->r.ray_dx;
			w->r.wallx = w->r.ray_y + wd * w->r.ray_dy;
		}
		else
		{
			wd = (w->r.mapy - w->r.ray_y + (1 - w->r.stepy) / 2) / w->r.ray_dy;
			w->r.wallx = w->r.ray_x + wd * w->r.ray_dx;
		}
		w->r.wall_dist = fabs(wd);
		w->r.line_h = abs((int)(WIN_Y / w->r.wall_dist));
		w->r.wallx -= floor(w->r.wallx);
		draw(x, w);
		x++;
	}
}
