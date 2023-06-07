/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:37:30 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/07 17:15:30 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cylinder	*cylinder_(t_point3 center, t_vec3 normal, t_vec2 dh, t_vars *var)
{
	t_cylinder	*cylinder;

	cylinder = rt_malloc(sizeof(t_cylinder), var);
	cylinder->height = dh.y;
	cylinder->radius = dh.x;
	cylinder->radius_sq = dh.x * dh.x;
	cylinder->normal = norm(normal);
	cylinder->base_center = center;
	cylinder->top_center = add(cylinder->base_center, \
		scl_mul(cylinder->height, cylinder->normal));
	return (cylinder);
}
/*
t_cylinder	*cylinder_(t_point3 center, t_vec3 normal, double radius, \
double height)
{
	t_cylinder	*this;

	this = (t_cylinder *)malloc((sizeof(t_cylinder)));
	if (this == NULL)
		return (NULL);
	this->normal = norm(normal);
	this->height = height;
	this->base_center = center;
	this->top_center = add(this->base_center, scl_mul(this->height, \
	this->normal));
	this->radius = radius;
	this->radius_sq = radius * radius;
	return (this);
}
*/

t_bool	intersect_ray_cylinder(t_object *object, t_ray *ray, t_hit *hit)
{
	t_bool	is_inter;

	is_inter = FALSE;
	is_inter += intersect_cylinder_base(object, ray, hit, TOP);
	is_inter += intersect_cylinder_base(object, ray, hit, BASE);
	is_inter += intersect_cylinder_surface(object, ray, hit);
	return (is_inter);
}
