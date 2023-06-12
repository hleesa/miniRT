/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:54:40 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/08 21:54:41 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	return (norm(sub(scl_mul(2 * dot(v, n), n), v)));
}

t_color3	get_specular(t_scene *scene, t_vec3 light_dir, t_color3 color)
{
	const double	shininess_exp = 32;
	const double	reflection_coef = 1;
	const t_vec3	reflect_dir = reflect(light_dir, scene->hit.normal);
	const t_vec3	view_dir = norm(scl_mul(-1, scene->ray.dir));
	const double	intensity = pow(fmax(dot(view_dir, reflect_dir), 0.0), \
	shininess_exp);

	return (scl_mul(intensity, scl_mul(reflection_coef, color)));
}
