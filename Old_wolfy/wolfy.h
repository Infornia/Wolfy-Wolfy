/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolfy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 20:18:39 by mwilk             #+#    #+#             */
/*   Updated: 2016/02/11 22:14:49 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLFY_H
# define WOLFY_H

#include "libft.h"
#include "mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

/*
**Parameters
*/
#define WINX		640
#define WINY		480

/*
**Colors
*/
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE 		0x0000FF
# define QUOISE		0x74BDF9
# define GREEN 		0x00FF00
# define PINK 		0xFF00FF
# define WHITE 		0xFFFFFF
# define GRAY 		0x0F0F0F
# define BLACK 		0x000000
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
# define ABS(x)		((x) < 0 ? -(x) : (x))

/*
**keys
*/
# define ESC		53
# define UP			126
# define DOWN		125
# define LEFT		123
# define RIGHT		124
# define TAB		48
# define SHIFT		257
# define ZOOM_IN	24
# define ZOOM_OUT	27
# define IT_UP		30
# define IT_DOWN	33
# define OPT_UP		39
# define OPT_DOWN	41
# define RESET		29
# define KEY1		18
# define KEY2		19
# define NUM1		83
# define NUM2		84
# define NUM3		85
# define NUM4		86
# define NUM5		87
# define NUM6		88
# define KEYR		15
# define ZOOM_IN_M	5
# define ZOOM_OUT_M	4

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
  void        *mlx;
  void        *win;
  void        *img;
  char        *datimg;
	char			  *map_name;

	t_input			i;
	t_ray			r;
	t_cam			c;
	int				map[MAP_SIZE][MAP_SIZE];

	int				go;
}			t_data;

/*
** get_map.c
*/

int				init_map(t_data *d);
int				get_map(t_data *d, int fd, int x, int y);

/*
** wolfy_main.c
*/

void			wolfy_main(t_data *d, char *file);

/*
** wolfy_init.c
*/

void			init_mlx(t_data *d);


/*
** wolfy_hook.c
*/

void			expose_hook(t_data *d);
void			mouse_hook(t_data *d);
void			key_hook(int key, t_data *d);


/*
** wolfy_draw.c
*/

void	draw(t_data *d);


/*
** wolfy_ray.c
*/

void	raycast(t_data *d);

/*
** wolfy_wall3d.c
*/

void		wall3d(int x, t_data *d);
#endif
