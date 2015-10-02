/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 18:11:04 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/02 18:22:14 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolfy.h"

int		main(int ac, char **av)
{
	t_data	d;

	(void)ac;
	d.map_name = av[1];
	init(&d);
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* pWindow = NULL;
	pWindow = SDL_CreateWindow("COUCOU", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

	SDL_Delay(3000);
	SDL_DestroyWindow(pWindow);
	SDL_Quit();
	return(0);
}
