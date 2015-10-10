/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolfy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 20:18:39 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/10 17:07:43 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLFY_H
# define WOLFY_H

#include "../../.brew/include/SDL2/SDL.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

#define MAP_SIZE	24
#define WIN_X		640
#define WIN_Y		480

#define KEB_KEY		e.key.keysym.sym

typedef struct	s_ray
{
	double		camx;
	double	ray_x;
	double	ray_y;
	double	ray_dx;
	double	ray_dy;
	int		mapx;
	int		mapy;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	wall_dist;
	int		stepx;
	int		stepy;
	int		side;
	int		line_h;
	int		y;
	double	wallx;
	int		top;
	double	fog;
}				t_ray;

typedef struct	s_cam
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planx;
	double	plany;
}				t_cam;

typedef struct	s_input
{
	int			jump;
	int			attack;
	int			left;
	int			right;
	int			up;
	int			down;
}				t_input;

typedef struct	s_data
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	SDL_Event		e;

	t_input			i;
	t_ray			r;
	t_cam			c;
	int				map[MAP_SIZE][MAP_SIZE];
	char			*map_name;

	int				go;
}			t_data;

/*
** get_map.c
*/

int		init_map(t_data *d);
int		get_map(t_data *d, int fd, int x, int y);

/*
** wolfy_utils.c
*/

int		put_error(char *s);


/*
** wolfy_init.c
*/

int		init(t_data *d);
int		clean_up(t_data *d, int ret);


/*
** wolfy_event.c
*/

void	events(t_data *d);


/*
** wolfy_draw.c
*/

void	draw(t_data *d);


/*
** wolfy_ray.c
*/

void	raycast(t_data *d);

#endif
