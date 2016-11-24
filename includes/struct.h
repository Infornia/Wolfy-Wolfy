/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 15:51:38 by mwilk             #+#    #+#             */
/*   Updated: 2016/11/22 20:36:02 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct			s_data		t_data; 
typedef struct			s_ray		t_ray;

typedef struct			s_color
{
	unsigned int		r;
	unsigned int		g;
	unsigned int		b;
}						t_color;

typedef struct			s_vec3
{
	double				x;
	double				y;
	double				z;
}						t_vec3;

struct					s_ray
{
	t_vec3				o;
	t_vec3				dir;
};

typedef struct			s_cam
{
	t_vec3				p;
	t_vec3				dir;
	t_vec3				upleft;
	double				w;
	double				h;
	double				f;
	double				fov;

}						t_cam;

struct					s_data
{
	t_cam				cam;
	t_ray				r;
	t_color				c;
	int					**map;
	void				*mlx;
	void				*win;
	void				*img;
	char				*dimg;
	int					bpp;
	int					size;
	int					endian;
	int					fd;
	unsigned int		max_size;
	int					map_x;
	int					map_y;

	size_t				lastime;
	size_t				time;
};
























