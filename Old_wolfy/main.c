/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 21:39:30 by mwilk             #+#    #+#             */
/*   Updated: 2016/02/12 19:37:07 by mwilk            ###   ########.fr       */
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
		wolfy_main(d);
	else
		ft_puts("Usage: ./wolf3d [MAP]");
	free(d);
	return(0);
}
