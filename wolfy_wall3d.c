/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolfy_wall3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/10 17:09:24 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/14 19:49:37 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolfy.h"

static void		draw_top(int x, t_data *d)
{
	SDL_SetRenderDrawColor(d->rend, 0, 0, 0, 255);
	while (d->r.top > 0 && d->r.y < WIN_Y)
	{
		SDL_RenderDrawPoint(d->rend, x, d->r.y);
		d->r.y++;
		d->r.top--;
	}
}

static void		draw_wall(int x, int line_tmp, t_data *d)
{
	Uint32	color;
	int		tx;
	double	ty;
	Uint32	rgb[3];

	while (d->r.line_h > 0 && d->r.y < WIN_Y)
	{
		color = getpixel(tx, ty, d);
		make_color(color, rgb, 0, d);
		SDL_SetRenderDrawColor(d->rend, rgb[0], rgb[1],
				rgb[2], 255);
		SDL_RenderDrawPoint(d->rend, x, d->r.y);
		d->r.line_h--;
		d->r.y++;
	}
}

static void		draw_bot(int x, t_data *d)
{
	while (d->r.y < WIN_Y)
	{
		SDL_RenderDrawPoint(d->rend, x, d->r.y);
		d->r.y++;
	}
}

void			wall3d(int x, t_data *d)
{
	int		line_tmp;

//	d->s.zbuf[x] = d->r.wall_dist;
	line_tmp = d->r.line_h;
	d->r.top = (WIN_X / 2) - (d->r.line_h / 2); //- d->m.look
	d->r.y = 0;
	draw_top(x, d);
	if (d->r.top < 0)
		d->r.line_h += d->r.top;
	draw_wall(x, line_tmp, d);
	draw_bot(x, d);
}
