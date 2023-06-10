/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:36:44 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/10 14:09:21 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_checkers	*checkers_(t_point3 point, t_vec3 normal, t_vars *vars)
{
	t_checkers	*checkers;

	checkers = rt_malloc(sizeof(t_checkers), vars);
	checkers->point = point;
	checkers->normal = normal;
	return (checkers);
}

t_bool	intersect_ray_checkers(t_object *object, t_ray *ray, t_hit *hit)
{
	double				root;
	const t_checkers	*checkers = object->element;
	const t_vec3		p0l0 = sub(checkers->point, ray->origin);
	const double		numerator = dot(p0l0, checkers->normal);
	const double		denominator = dot(checkers->normal, ray->dir);

	if (fabs(denominator) <= EPSILON)
		return (FALSE);
	root = numerator / denominator;
	if (root < hit->t_min || hit->t_max < root)
		return (FALSE);
	hit->t = root;
	hit->t_max = hit->t;
	hit->point = ray_at(hit->t, ray);
	hit->normal = checkers->normal;
	if (dot(ray->dir, hit->normal) > 0)
		hit->normal = scl_mul(-1, hit->normal);
	hit->albedo = object->albedo;
	if ((int)floorf(0.42 * hit->point.x) + (int)floorf(0.42 * hit->point.y) + \
		(int)floorf(0.42 * hit->point.z) & 1)
		hit->albedo = color3_(0, 0, 0);
	return (TRUE);
}
