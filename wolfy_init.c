/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolfy_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 21:43:00 by mwilk             #+#    #+#             */
/*   Updated: 2016/02/17 19:46:54 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolfy.h"

void	init_mlx(t_data *d)
{
	if (!(d->mlx = mlx_init()))
		exit(tt_ps("Error: Failed to init mlx", 0));
	if (!(d->win = mlx_new_window(d->mlx, 0, 0, "Wolf3d")))
		exit(tt_ps("Error: Failed to create window", 0));
	if (!(d->img = mlx_new_image(d->mlx, WINX, WINY)))
		exit(tt_ps("Error: Failed to create img", 0));
}
