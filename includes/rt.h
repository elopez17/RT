/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 00:06:40 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/18 17:42:52 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <ft_printf.h>
# include <get_next_line.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <pthread.h>
# define THREADS 4
# define MAX(a, b) (a > b ? a : b)
# define MIN(a, b) (a < b ? a : b)
# define PI 3.14159265
# define KEY1 83
# define KEY2 84
# define KEY3 85
# define KEY4 86
# define KEY5 87
# define KEY6 88
# define KEY7 89
# define KEY8 91
# define KEY9 92
# define KEYMIN 78
# define KEYPLUS 69
# define KEYUP 126
# define KEYDOWN 125
# define KEYLEFT 123
# define KEYRIGHT 124
# define KEYESC 53
# define KEYR 15
# define KEYG 5
# define KEYB 11
# define KEYE 14
# define KEYF 3
# define KEYV 9
# define KEYS 1
# define KEYD 2
# define KEYX 7
# define KEYC 8
# define KEYN 45
# define KEYM 46

extern pthread_mutex_t lock;

typedef struct	s_dimensions
{
	int		width;
	int		height;
}				t_dim;

typedef struct	s_xy
{
	double	x;
	double	y;
}				t_xy;

typedef struct	s_quad
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	rslt[2];
}				t_quad;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vect;

typedef struct	s_distance
{
	t_vect	dist;
	double	dist_mag;
}				t_dist;

typedef struct	s_rgb
{
	int		red;
	int		green;
	int		blue;
}				t_rgb;

typedef struct	s_ray
{
	t_vect	origin;
	t_vect	dir;
}				t_ray;

typedef struct	s_cube
{
	t_vect	pos;
	double  len;
	t_vect	min;
	t_vect	max;
	t_rgb	clr;
}				t_cube;

typedef struct	s_sphere
{
	t_vect	pos;
	double	radius;
	t_rgb	clr;
}				t_sphere;

typedef struct	s_plane
{
	t_vect	norm;
	double	dist;
	t_rgb	clr;
}				t_plane;

typedef struct	s_cone
{
	t_vect	pos;
	t_vect	dir;
	double	a;
	t_rgb	clr;
}				t_cone;

typedef struct	s_cylinder
{
	t_vect	pos;
	t_vect	dir;
	double	radius;
	t_rgb	clr;
}				t_cylinder;

typedef struct	s_camera
{
	t_vect	pos;
	t_vect	dir;
	t_vect	right;
	t_vect	down;
	t_vect	look_at;
}				t_cam;

typedef union	u_union
{
	t_sphere	sphere;
	t_plane		plane;
	t_cone		cone;
	t_cylinder	cylinder;
	t_cube		cube;
}				t_union;

typedef struct	s_objects
{
	int					type;
	t_union				u;
	t_vect				norm;
	int					shine;
	double				spec;
	double				diff;
	double				m;
	struct s_objects	*next;
}				t_obj;

typedef struct	s_rt
{
	void	*mlx;
	void	*win;
	void	*win2;
	t_dim	w;
	void	*img;
	int		bpp;
	int		len;
	int		endian;
	char	*addr;
	int		fd;
	t_cam	cam;
	t_obj	*obj;
	t_vect	*light;
	int		nlights;
	int		nodes;
	double	bright;
	t_obj	*current;
	int		toggle;
	int		ystart;
	int		ymax;
}				t_rt;

void			multithread(t_rt *rt);
void			controls(t_rt *rt);
void			draw(t_rt *rt);
void			putpixel(t_rt *rt, int x, int y, t_rgb color);
int				key_hook(int key, t_rt **rt);
int				mousepress(int key, int x, int y, t_rt **rt);
void			move_obj(int key, t_obj **object, int toggle);
int				close_hook(t_rt **rt);
int				expose_hook(t_rt **rt);
t_vect			normalize(t_vect v);
t_vect			invert(t_vect v);
double			vdot(t_vect v1, t_vect v2);
double			norm_vect(t_vect v);
double			vsqr(t_vect v);
double			vlen(t_vect v);
t_vect			vcross(t_vect v1, t_vect v2);
t_vect			vadd(t_vect v1, t_vect v2);
t_vect			vmult(t_vect v, double scalar);
t_vect			vdiv(t_vect v, double denominator);
t_vect			vdiff(t_vect v1, t_vect v2);
void			setxy(t_rt *rt, t_ray *ray, t_xy *pixel);
int				winningobject(double *intersects, int nodes);
double			findinterplane(t_ray ray, t_plane plane);
double			findintersphere(t_ray ray, t_sphere sphere);
double			findintercone(t_ray ray, t_cone cone);
double			findintercylinder(t_ray ray, t_cylinder cylinder);
double			pickinter(double inter0, double inter1);
t_vect			cube_norm(t_cube cube, t_vect point);
t_vect			sphere_norm(t_sphere sphere, t_vect point);
t_vect			cone_norm(t_cone cone, t_vect point);
t_vect			cylinder_norm(t_cylinder cylinder, t_vect point);
void			*scene(void *rt);
double			brightness(t_rgb color);
t_rgb			colorscalar(t_rgb color, double scalar);
t_rgb			coloradd(t_rgb clr1, t_rgb clr2);
t_rgb			colormult(t_rgb clr1, t_rgb clr2);
t_rgb			coloravg(t_rgb clr1, t_rgb clr2);
void			rt_error(int code);
void			parsefile(t_rt *rt);
t_vect			getxyz(const char *line);
t_rgb			getcolor(const char *line);
t_rgb			addlight(t_rt *rt, t_ray *intersect, t_obj *obj, t_vect light);
t_rgb			lighting(t_obj *obj, t_ray *intersect, t_vect light,
		int shadow);
t_rgb			lighting2(t_obj *obj, t_ray *intersect, t_vect light,
		int shadow);
void			getcam(t_rt *rt);
void			getlight(t_rt *rt);
t_union			getcube(t_rt *rt);
t_union			getsphere(t_rt *rt);
t_union			getplane(t_rt *rt);
t_union			getcone(t_rt *rt);
t_union			getcylinder(t_rt *rt);
void			getobject(int type, t_union u, t_rt *rt);
double			*findintersects(t_ray ray, t_rt *rt);

#endif
