/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:22:46 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:22:49 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ray_(t_point3 origin, t_vec3 dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = norm(dir);
	return (ray);
}

t_point3	ray_at(double t, t_ray *ray)
{
	t_point3	point;

	point = add(ray->origin, scl_mul(t, ray->dir));
	return (point);
}

t_ray	primary_ray(t_camera *camera, t_vec2 pixel_pos)
{
	t_ray			ray;
	const t_vec3	ai = scl_mul(pixel_pos.x, camera->ai);
	const t_vec3	bj = scl_mul(pixel_pos.y, camera->bj);

	ray.origin = add(add(camera->lower_left_corner, ai), bj);
	ray.dir = norm(sub(ray.origin, camera->origin));
	return (ray);
}

t_color3	trace_ray(t_scene *scene)
{
	t_color3	color;

	color = color3_(0, 0, 0);
	scene->hit = hit_(INFINITY);
	if (hit_objects(scene->objects, &scene->ray, &scene->hit))
		color = phong_lighting(scene);
	return (color);
}
