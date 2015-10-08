/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 18:11:04 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/08 21:36:11 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolfy.h"

int		main(int ac, char **av)
{
	t_data	d;

	if (ac == 2)
	{
	d.map_name = av[1];
		if (init(&d))
			return (clean_up(&d, -1));
		while (d.go)
		{
			ft_puts("Bonjour");
			while (SDL_PollEvent(&d.e))
			{
				if (d.e.type == SDL_QUIT)
					d.go = 0;
				events(&d);
			}
			draw();
			SDL_Delay(16);
		}
		return (clean_up(&d, 0));
	}
	else
		ft_puts("Usage: ./wolf3d [MAP]");
	return(0);
}
