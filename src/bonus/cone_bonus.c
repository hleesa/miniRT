/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:21:24 by salee2            #+#    #+#             */
/*   Updated: 2023/06/09 20:12:36 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_cone	*cone_(t_point3 center, t_vec3 normal, t_vec2 dh, t_vars *vars)
{
	t_cone	*this;
	double	height;
	double	radius;

	this = rt_malloc(sizeof(t_cone), vars);
	height = dh.y;
	radius = dh.x;
	this->height = height;
	this->radius = radius;
	this->radius_sq = radius * radius;
	this->normal = norm(normal);
	this->base_center = add(center, \
	scl_mul(this->height / 2, scl_mul(-1, this->normal)));
	this->tip_center = add(this->base_center, scl_mul(height, this->normal));
	this->h_dir = sub(this->base_center, this->tip_center);
	this->h_normal = norm(this->h_dir);
	return (this);
}

t_bool	intersect_ray_cone(t_object *object, t_ray *ray, t_hit *hit)
{
	t_bool	is_inter;

	is_inter = FALSE;
	is_inter += intersect_cone_surface(object, ray, hit);
	is_inter += intersect_cone_base(object, ray, hit);
	return (is_inter);
}
