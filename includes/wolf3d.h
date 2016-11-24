/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:38:33 by mwilk             #+#    #+#             */
/*   Updated: 2016/11/22 19:18:11 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include "../libft/includes/libft.h"
# include "macro.h"
# include "struct.h"

/*
*******************INIT.C
*/

t_data			*init(char *name);

/*
*******************COLOR.C
*/

void			color_pixel(t_data *d, unsigned int col, int x, int y);
t_color			put_col(unsigned int c);
t_color			add_col(t_color c, t_color c2);
t_color			moy_col(t_color c);
t_color			scal_col(t_color c, double scal);
t_color			lim_col(t_color c);
t_color			mult_col(t_color c, t_color c2);

/*
*******************DRAW.C
*/

t_vec3			get_ray_dir(int x, int y);
void			render(t_data *d);
void			draw(t_data *d);

/*
*******************HOOKS.C
*/

int				expose_hook(t_data *d);
int				key_hook(int key, t_data *d);

/*
*******************MLX.C
*/

void			init_mlx(t_data *d);
void			destroy_mlx(t_data *d);

/*
*******************VECTOR.C
*/
t_vec3			normalize(t_vec3 v);
t_vec3			vec3_new(double x, double y, double z);
t_vec3			vec_sub(t_vec3 a, t_vec3 b);
t_vec3			vec_add(t_vec3 a, t_vec3 b);
t_vec3			vec_neg(t_vec3 a);
t_vec3			vec_mul(t_vec3 a, t_vec3 b);
double			vec_dot(t_vec3 a, t_vec3 b);
t_vec3			vec_scalar(t_vec3 v, double coef_mult);

#endif