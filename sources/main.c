/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:59:10 by mwilk             #+#    #+#             */
/*   Updated: 2016/11/22 18:02:04 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		print_usage(void)
{
	tt_pl("Usage: ./wolf3d [scene]");
}

int				main(int ac, char **av)
{
	t_data	*d;

	d = NULL;
	(void)av;
	if (ac == 2)
	{
		d = (t_data *)init(av[1]);
		draw(d);
		mlx_expose_hook(d->win, expose_hook, d);
		mlx_hook(d->win, 2, 1, key_hook, d);
		mlx_loop(d->mlx);
	}
	else
		print_usage();
	return (0);
}
