/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolfy_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 20:24:05 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/09 18:20:25 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolfy.h"

static void		event_keyboard(t_data *d)
{
	while (SDL_PollEvent(&d->e))
	{
		if (d->e.type == SDL_QUIT)
			d->go = 0;
		else if (d->e.type == SDL_KEYDOWN)
		{
			if (d->e.key.keysym.sym)
			{
				if (d->KEB_KEY == SDLK_ESCAPE)
					d->go = 0;
				if (d->KEB_KEY == SDLK_LEFT)
					d->i.left = 1;
				if (d->KEB_KEY == SDLK_RIGHT)
					d->i.right = 1;
				if (d->KEB_KEY == SDLK_UP)
					d->i.up = 1;
				if (d->KEB_KEY == SDLK_DOWN)
					d->i.down = 1;
			}
		}
		else if (d->e.type == SDL_KEYUP)
		{
			if (d->e.key.keysym.sym)
			{
				if (d->KEB_KEY == SDLK_LEFT)
					d->i.left = 0;
				if (d->KEB_KEY == SDLK_RIGHT)
					d->i.right = 0;
				if (d->KEB_KEY == SDLK_UP)
					d->i.up = 0;
				if (d->KEB_KEY == SDLK_DOWN)
					d->i.down = 0;
			}
		}
		break;
	}
}

void	events(t_data *d)
{
	event_keyboard(d);
}
