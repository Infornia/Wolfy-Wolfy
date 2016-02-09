/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolfy_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 16:53:19 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/08 21:23:24 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "wolfy.h"

int			clean_up(t_data *d, int ret)
{
	if (d->rend)
		SDL_DestroyRenderer(d->rend);
	if (d->win)
		SDL_DestroyWindow(d->win);
	SDL_Quit();
	return (ret);
}

static void	init_val(t_data *d)
{
	d->go = 1;
}

static int	init_SDL(t_data *d)
{
	(void)d;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return(put_error("Error: Failed to init SDL"));
	if (!(d->win = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED, WIN_X, WIN_Y, SDL_WINDOW_SHOWN)))
		return (put_error("Error: Failed to create window"));
	if (!(d->rend = SDL_CreateRenderer(d->win, -1, SDL_RENDERER_ACCELERATED)))
		return (put_error("Error: Failed to create renderer"));
	return (0);
}

int		init(t_data *d)
{
	init_val(d);
	init_map(d);
	init_SDL(d);
	return (0);
}

