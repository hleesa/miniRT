/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:52:41 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/09 20:12:54 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_cylinder	*cylinder_(t_point3 center, t_vec3 normal, t_vec2 dh, t_vars *vars)
{
	t_cylinder	*cylinder;
	double		height;
	double		radius;

	cylinder = rt_malloc(sizeof(t_cylinder), vars);
	height = dh.y;
	radius = dh.x;
	cylinder->height = height;
	cylinder->radius = radius;
	cylinder->radius_sq = radius * radius;
	cylinder->normal = normal;
	cylinder->base_center = add(center, \
	scl_mul(cylinder->height / 2, scl_mul(-1, cylinder->normal)));
	cylinder->top_center = add(cylinder->base_center, \
		scl_mul(cylinder->height, cylinder->normal));
	return (cylinder);
}

t_bool	intersect_ray_cylinder(t_object *object, t_ray *ray, t_hit *hit)
{
	t_bool	is_inter;

	is_inter = FALSE;
	is_inter += intersect_cylinder_base(object, ray, hit, TOP);
	is_inter += intersect_cylinder_base(object, ray, hit, BASE);
	is_inter += intersect_cylinder_surface(object, ray, hit);
	return (is_inter);
}
