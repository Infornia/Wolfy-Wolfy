/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 21:39:30 by mwilk             #+#    #+#             */
/*   Updated: 2016/02/17 20:19:31 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolfy.h"

int		main(int ac, char **av)
{
	t_data	*d;

	if (!(d = malloc(sizeof(t_data))))
		tt_perr("Failed to malloc data", "", 0);
	d->file = av[1];
	if (ac == 2)
		tt_wolfy(d, av[1]);
	else
		ft_puts("Usage: ./wolf3d [MAP]");
	free(d);
	return(0);
}
