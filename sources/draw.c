/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:14:15 by mwilk             #+#    #+#             */
/*   Updated: 2016/11/24 17:44:39 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_vec3			get_ray_dir(int x, int y)
{
	t_vec3	dir;

	dir.x = ((2 * (x + 0.5) / X_WIN) - 1) * RATIO * FOV;
	dir.y = (1 - (2 * ((0.5 + y) / Y_WIN))) * FOV;
	dir.z = 1;
	dir = normalize(dir);
	return (dir);
}

static void		print_map(t_data *d)
{
	int x;
	int y;
	
	x = -1;
	while (++x < d->map_x)
	{
		y = -1;
		while (++y < d->map_y)
			color_pixel(d, CRED, x, y);
	}
}

void			render(t_data *d)
{
	int x;
	int y;
	
	d->cam.p = VEC3(0, 0, 0);
	d->cam.dir = VEC3(-1, 0, 0);
	
	
	x = -1;
	while(++x < X_WIN)
	{
		d->r.dir  = get_ray_dir(x, 0);
		y = -1;
		while(++y < Y_WIN)
			color_pixel(d, CBLACK, x, y);
	}
	print_map(d);
}

// void			draw(t_data *d)
// {
// 	double	dframe;
// 
// 	ft_bzero(d->dimg, d->max_size);
// 	d->lastime = clock();
// 	render(d);
// 	d->time = clock();
// 	dframe = d->time - d->lastime;
// 	printf("last %zu, now %zu, Delta %f\n", d->time, d->lastime, dframe);
// 	mlx_put_image_to_window(d->mlx, win, d->img, 0, 0);
// }

void			draw(t_data *d, int worldMap[MAP_W][MAP_H])
{	
	d->g.posX = 22;
	d->g.posY = 12;
    d->g.dirX = -1;
	d->g.dirY = 0;
    d->g.planeX = 0;
	d->g.planeY = 0.66;

    double time = 0; //time of current frame
    double oldTime = 0; //time of previous frame

      for(int x = 0; x < X_WIN; x++)
      {
        //calculate ray position and direction
        d->g.cameraX = 2 * x / X_WIN - 1; //x-coordinate in camera space
        d->g.rayPosX = d->g.posX;
    	d->g.rayPosY = d->g.posY;
        d->g.rayDirX = d->g.dirX + d->g.planeX * d->g.cameraX;
        d->g.rayDirY = d->g.dirY + d->g.planeY * d->g.cameraX;
        //which box of the map we're in
        d->g.mapX = (int)(d->g.rayPosX);
        d->g.mapY = (int)(d->g.rayPosY);

        //length of ray from current position to next x or y-side
         //length of ray from one x or y-side to next x or y-side
        d->g.deltaDistX = sqrt(1 + (d->g.rayDirY * d->g.rayDirY) / (d->g.rayDirX * d->g.rayDirX));
        d->g.deltaDistY = sqrt(1 + (d->g.rayDirX * d->g.rayDirX) / (d->g.rayDirY * d->g.rayDirY));

        int hit = 0;
        if (d->g.rayDirX < 0)
        {
          d->g.stepX = -1;
          d->g.sideDistX = (d->g.rayPosX - d->g.mapX) * d->g.deltaDistX;
        }
        else
        {
          d->g.stepX = 1;
          d->g.sideDistX = (d->g.mapX + 1.0 - d->g.rayPosX) * d->g.deltaDistX;
        }
        if (d->g.rayDirY < 0)
        {
          d->g.stepY = -1;
          d->g.sideDistY = (d->g.rayPosY - d->g.mapY) * d->g.deltaDistY;
        }
        else
        {
          d->g.stepY = 1;
          d->g.sideDistY = (d->g.mapY + 1.0 - d->g.rayPosY) * d->g.deltaDistY;
        }
        //perform DDA
        while (hit == 0)
        {
          //jump to next map square, OR in x-direction, OR in y-direction
          if (d->g.sideDistX < d->g.sideDistY)
          {
            d->g.sideDistX += d->g.deltaDistX;
            d->g.mapX += d->g.stepX;
            d->g.side = 0;
          }
          else
          {
            d->g.sideDistY += d->g.deltaDistY;
            d->g.mapY += d->g.stepY;
            d->g.side = 1;
          }
          //Check if ray has hit a wall
          if (worldMap[d->g.mapX][d->g.mapY] > 0) hit = 1;
        }
        //Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
        if (d->g.side == 0) d->g.perpWallDist = (d->g.mapX - d->g.rayPosX + (1 - d->g.stepX) / 2) / d->g.rayDirX;
        else           d->g.perpWallDist = (d->g.mapY - d->g.rayPosY + (1 - d->g.stepY) / 2) / d->g.rayDirY;

        //Calculate height of line to draw on screen
        int lineHeight = (int)(Y_WIN / d->g.perpWallDist);

        //calculate lowest and highest pixel to fill in current stripe
        int drawStart = -lineHeight / 2 + Y_WIN / 2;
        if(drawStart < 0)drawStart = 0;
        int drawEnd = lineHeight / 2 + Y_WIN / 2;
        if(drawEnd >= Y_WIN)drawEnd = Y_WIN - 1;

        //choose wall color
		unsigned int color = 0x000000;
        switch(worldMap[d->g.mapX][d->g.mapY])
        {
          case 1:  color = CRED;  break; //red
          case 2:  color = CGREEN;  break; //green
          case 3:  color = CBLUE;   break; //blue
          case 4:  color = CWHITE;  break; //white
          default: color = CPINK; break; //yellow
        }

        //give x and y d->g.d->g.sides different brightness
        if (d->g.side == 1) {color = color / 2;}

        //draw the pixels of the stripe as a vertical line
		for (int k = drawStart; k < drawEnd; k++)
			color_pixel(d, color, x, k);
			
      }
      //timing for input and FPS counter
      oldTime = time;
      time = clock();
      double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
      printf("Frame: %f\n", 1.0 / frameTime); //FPS counter
      mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	  ft_bzero(d->dimg, d->max_size);
      //speed modifiers
      d->g.moveSpeed = frameTime * 5.0; //the constant value is in squares/second
      d->g.rotSpeed = frameTime * 3.0; //the constant value is in radians/second
      //move forward if no wall in front of you
}