/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:53:48 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/08 21:53:48 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_ray	ray_(t_point3 origin, t_vec3 dir)
{
	t_ray	this;

	this.origin = origin;
	this.dir = norm(dir);
	return (this);
}

t_vec3	ray_at(double t, t_ray *ray)
{
	t_vec3	this;

	this = add(ray->origin, scl_mul(t, ray->dir));
	return (this);
}

t_ray	primary_ray(t_camera *cam, t_vec2 pixel_pos)
{
	t_ray			this;
	const t_vec3	ai = scl_mul(pixel_pos.x, cam->ai);
	const t_vec3	bj = scl_mul(pixel_pos.y, cam->bj);

	this.origin = add(add(cam->lower_left_corner, ai), bj);
	this.dir = norm(sub(this.origin, cam->origin));
	return (this);
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
