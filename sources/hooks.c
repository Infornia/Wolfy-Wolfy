/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:19:54 by mwilk             #+#    #+#             */
/*   Updated: 2016/11/26 16:39:04 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				expose_hook(t_data *d)
{
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return (1);
}

int				key_hook(int key, t_data *d, int worldMap[MAP_W][MAP_H])
{
	printf("The key pressed %i\n", key);
	if (key == ESC)
		destroy_mlx(d);
	if (key == UP)
	{
		if(worldMap[(int)(d->g.posX + d->g.dirX * d->g.moveSpeed)][(int)(d->g.posY)] == 0)
		d->g.posX += d->g.dirX * d->g.moveSpeed;
		if(worldMap[(int)(d->g.posX)][(int)(d->g.posY + d->g.dirY * d->g.moveSpeed)] == 0)
		d->g.posY += d->g.dirY * d->g.moveSpeed;
	}
	//move backwards if no wall behind you
	if (key == DOWN)
	{
		if(worldMap[(int)(d->g.posX - d->g.dirX * d->g.moveSpeed)][(int)(d->g.posY)] == 0) d->g.posX -= d->g.dirX * d->g.moveSpeed;
		if(worldMap[(int)(d->g.posX)][(int)(d->g.posY - d->g.dirY * d->g.moveSpeed)] == 0) d->g.posY -= d->g.dirY * d->g.moveSpeed;
	}
	//rotate to the right
	if (key == RIGHT)
	{
	//both camera direction and camera plane must be rotated
	d->g.oldDirX = d->g.dirX;
	d->g.dirX = d->g.dirX * cos(-d->g.rotSpeed) - d->g.dirY * sin(-d->g.rotSpeed);
	d->g.dirY = d->g.oldDirX * sin(-d->g.rotSpeed) + d->g.dirY * cos(-d->g.rotSpeed);
	d->g.oldPlaneX = d->g.planeX;
	d->g.planeX = d->g.planeX * cos(-d->g.rotSpeed) - d->g.planeY * sin(-d->g.rotSpeed);
	d->g.planeY = d->g.oldPlaneX * sin(-d->g.rotSpeed) + d->g.planeY * cos(-d->g.rotSpeed);
	}
	//rotate to the left
	if (key == LEFT)
	{
	//both camera direction and camera plane must be rotated
	d->g.oldDirX = d->g.dirX;
	d->g.dirX = d->g.dirX * cos(d->g.rotSpeed) - d->g.dirY * sin(d->g.rotSpeed);
	d->g.dirY = d->g.oldDirX * sin(d->g.rotSpeed) + d->g.dirY * cos(d->g.rotSpeed);
	d->g.oldPlaneX = d->g.planeX;
	d->g.planeX = d->g.planeX * cos(d->g.rotSpeed) - d->g.planeY * sin(d->g.rotSpeed);
	d->g.planeY = d->g.oldPlaneX * sin(d->g.rotSpeed) + d->g.planeY * cos(d->g.rotSpeed);
}
	draw(d, worldMap);
	return (1);
}
