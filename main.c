/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 18:11:04 by mwilk             #+#    #+#             */
/*   Updated: 2015/09/29 20:19:39 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolfy.h"

int		main(void)
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* pWindow = NULL;
	pWindow = SDL_CreateWindow("COUCOU", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

	SDL_Delay(3000);
	SDL_DestroyWindow(pWindow);
	SDL_Quit();
	return(0);
}
