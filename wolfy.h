/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolfy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 20:18:39 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/02 18:26:28 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLFY_H
# define WOLFY_H

#include "../../.brew/include/SDL2/SDL.h"
#include "libft.h"
#include <fcntl.h>

#define MAP_SIZE 24

typedef struct	s_data
{
	int		map[MAP_SIZE][MAP_SIZE];
	char	*map_name;
}			t_data;

/*
** get_map.c
*/

int		init(t_data *d);
int		get_map(t_data *d, int fd, int x, int y);

#endif
