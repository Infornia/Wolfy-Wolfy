/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolfy_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 20:25:29 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/09 18:52:43 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolfy.h"

static void		delay(unsigned int frameLimit)
{
	unsigned int	ticks;

	ticks = SDL_GetTicks();
	if (frameLimit < ticks)
		return ;
	if (frameLimit > ticks + 16)
		SDL_Delay(16);
	else
		SDL_Delay(frameLimit - ticks);
}

void	draw(t_data *d)
{
	SDL_SetRenderDrawColor(d->rend, 50, 100, 255, 128);
	SDL_RenderClear(d->rend);
	SDL_RenderPresent(d->rend);

	delay(1);
}
