/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:52:55 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/08 21:52:56 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_color3	get_diffuse(t_vec3 normal, t_vec3 light_dir, t_color3 color)
{
	double		diffuse_reflection_coef;
	t_color3	diffuse;

	diffuse_reflection_coef = fmax(dot(normal, light_dir), 0.0);
	diffuse = scl_mul(diffuse_reflection_coef, color);
	return (diffuse);
}
