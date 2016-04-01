/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolfy_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 20:25:29 by mwilk             #+#    #+#             */
/*   Updated: 2016/04/01 05:31:07 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolfy.h"

void	draw(t_data *d)
{
	raycast(d);
}

void	color_pixel(t_data *d, unsigned int color, int x, int y)
{
	int	i;

	i = x * d->bpp / 8 + y * d->size_line;
	printf("The i : %i\n", i);
	if (i > 0 && i < d->dimg_size)
	{
		d->dimg[i] = color & 0x000000ff;
		d->dimg[i + 1] = (color >> 8) & 0x000000ff;
		d->dimg[i + 2] = (color >> 16) & 0x000000ff;
		printf("The coloring bit: %i, %i, %i\n", color, color >> 8, color >> 16);
		printf("The coloring : %i, %i, %i\n", (int)d->dimg[i], (int)d->dimg[i+1], (int)d->dimg[i+2]);
	}
}
