/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 16:30:17 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/19 16:22:11 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

inline double	pickinter(double inter0, double inter1)
{
	if (inter0 >= 0.00000001)
		return (inter0);
	return ((inter1 >= 0.00000001) ? inter1 : -1);
}

double	findinterplane(t_ray ray, t_plane plane)
{
	double	a;
	double	b;

	a = vdot(ray.dir, plane.norm);
	if (a == 0)
		return (-1);
	b = vdot(plane.norm, vdiff(ray.origin, vmult(plane.norm, plane.dist)));
	return (-b / a);
}

inline t_vect	sphere_norm(t_sphere sphere, t_vect point)
{
	return (normalize(vdiff(point, sphere.pos)));
}

double	findintersphere(t_ray ray, t_sphere sphere)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	root[2];

	a = pow(ray.dir.x, 2) + pow(ray.dir.y, 2) + pow(ray.dir.z, 2);
	b = (2 * (ray.origin.x - sphere.pos.x) * ray.dir.x) +
		(2 * (ray.origin.y - sphere.pos.y) * ray.dir.y) +
		(2 * (ray.origin.z - sphere.pos.z) * ray.dir.z);
	c = pow(ray.origin.x - sphere.pos.x, 2) +
		pow(ray.origin.y - sphere.pos.y, 2) +
		pow(ray.origin.z - sphere.pos.z, 2) - (sphere.radius * sphere.radius);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1);
	root[0] = ((-b - sqrt(discriminant)) / (2 * a));
	root[1] = ((-b + sqrt(discriminant)) / (2 * a));
	return (pickinter(root[0], root[1]));
}

double	findintercube(t_ray ray, t_cube cube)
{
	double	tmp;
    double	tmin = (cube.min.x - ray.origin.x) / ray.dir.x; 
    double	tmax = (cube.max.x - ray.origin.x) / ray.dir.x; 
    double	tymin = (cube.min.y - ray.origin.y) / ray.dir.y; 
    double	tymax = (cube.max.y - ray.origin.y) / ray.dir.y; 
    double	tzmin = (cube.min.z - ray.origin.z) / ray.dir.z; 
    double	tzmax = (cube.max.z - ray.origin.z) / ray.dir.z; 

    if (tmin > tmax)
	{
		tmp = tmin;
		tmin = tmax;
		tmax = tmp;
	}
    if (tymin > tymax)
	{
		tmp = tymin;
		tymin = tymax;
		tymax = tmp;
	}
    if ((tmin > tymax) || (tymin > tmax)) 
        return (-1); 
    if (tymin > tmin) 
        tmin = tymin; 
    if (tymax < tmax) 
        tmax = tymax; 
    if (tzmin > tzmax)
	{
		tmp = tzmin;
		tzmin = tzmax;
		tzmax = tmp;
	}
    if ((tmin > tzmax) || (tzmin > tmax)) 
        return (-1); 
    if (tzmin > tmin) 
        tmin = tzmin; 
    if (tzmax < tmax) 
        tmax = tzmax; 
    return (pickinter(tmin, tmax));
}

double	*findintersects(t_ray ray, t_rt *rt)
{
	double	*intersects;
	int		i;
	t_obj	*objects;

	i = -1;
	objects = rt->obj;
	intersects = (double*)malloc(sizeof(double) * rt->nodes);
	while (++i < rt->nodes)
	{
		(i != 0) ? objects = objects->next : 0;
		if (objects->type == 1)
			intersects[i] = findintersphere(ray, objects->u.sphere);
		else if (objects->type == 2)
			intersects[i] = findinterplane(ray, objects->u.plane);
		else if (objects->type == 3)
			intersects[i] = findintercone(ray, objects->u.cone);
		else if (objects->type == 4)
			intersects[i] = findintercylinder(ray, objects->u.cylinder);
		else if (objects->type == 5)
			intersects[i] = findintercube(ray, objects->u.cube);
	}
	return (intersects);
}
