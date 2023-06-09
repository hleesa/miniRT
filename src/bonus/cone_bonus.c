/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:21:24 by salee2            #+#    #+#             */
/*   Updated: 2023/06/09 20:42:35 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_cone	*cone_(t_point3 center, t_vec3 normal, t_vec2 dh, t_vars *vars)
{
	t_cone	*cone;
	double	height;
	double	radius;

	cone = rt_malloc(sizeof(t_cone), vars);
	height = dh.y;
	radius = dh.x;
	cone->height = height;
	cone->radius = radius;
	cone->radius_sq = radius * radius;
	cone->normal = norm(normal);
	cone->base_center = center;
	cone->tip_center = add(cone->base_center, scl_mul(height, cone->normal));
	cone->h_dir = sub(cone->base_center, cone->tip_center);
	cone->h_normal = norm(cone->h_dir);
	return (cone);
}

t_bool	intersect_ray_cone(t_object *object, t_ray *ray, t_hit *hit)
{
	t_bool	is_inter;

	is_inter = FALSE;
	is_inter += intersect_cone_surface(object, ray, hit);
	is_inter += intersect_cone_base(object, ray, hit);
	return (is_inter);
}
