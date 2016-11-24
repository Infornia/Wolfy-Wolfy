/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:14:15 by mwilk             #+#    #+#             */
/*   Updated: 2016/11/22 19:09:14 by mwilk            ###   ########.fr       */
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

void			draw(t_data *d)
{
	double	dframe;

	ft_bzero(d->dimg, d->max_size);
	d->lastime = clock();
	render(d);
	d->time = clock();
	dframe = d->time - d->lastime;
	printf("last %zu, now %zu, Delta %f\n", d->time, d->lastime, dframe);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	// printf("x %f, y %f, z %f\n", d->r.o.x, d->r.o.y, d->r.o.z);
	// mlx_do_sync(d->mlx);
}
