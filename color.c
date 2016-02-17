/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 20:08:06 by mwilk             #+#    #+#             */
/*   Updated: 2015/09/24 19:27:10 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_pixel(t_img *d, unsigned int color, int x, int y)
{
	int	i;

	i = x * d->bpp + y * d->size;
	if (i > 0 && i < d->max_size)
	{
		d->data_img[i] = color;
		d->data_img[i + 1] = (color >> 8);
		d->data_img[i + 2] = (color >> 16);
	}
}

unsigned int	create_color(int r, int g, int b)
{
	return (b + (g << 8) + (r << 16));
}
