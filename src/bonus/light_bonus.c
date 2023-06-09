/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:53:25 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/09 17:07:16 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_light	*light_(t_point3 origin, t_color3 color, \
				double bright_ratio, t_vars *vars)
{
	t_light	*light;

	light = rt_malloc(sizeof(t_light), vars);
	light->origin = origin;
	light->color = color;
	light->bright_ratio = bright_ratio;
	return (light);
}
