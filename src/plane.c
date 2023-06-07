/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:37:51 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/07 17:18:29 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane	*plane_(t_point3 point, t_vec3 normal, t_vars *vars)
{
	t_plane	*plane;

	plane = rt_malloc(sizeof(t_plane), vars);
	plane->point = point;
	plane->normal = normal;
	return (plane);
}
