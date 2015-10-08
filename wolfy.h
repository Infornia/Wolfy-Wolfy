/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolfy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 20:18:39 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/08 21:23:48 by mwilk            ###   ########.fr       */
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

typedef struct	s_data
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	SDL_Event		e;

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

void	draw();

#endif
