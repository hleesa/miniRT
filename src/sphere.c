/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:37:06 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/07 17:25:58 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*sphere_(t_point3 center, double radius, t_vars *vars)
{
	t_sphere	*sphere;

	sphere = rt_malloc(sizeof(t_sphere), vars);
	sphere->center = center;
	sphere->radius = radius;
	sphere->radius_sq = radius * radius;
	return (sphere);
}
