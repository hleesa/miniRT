/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:54:00 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/08 17:25:56 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*set_sphere(char **tokens, t_vars *vars)
{
	t_point3	center;
	double		radius;

	if (check_element_count(tokens, 4) == FALSE)
		print_read_error("wrong sphere element count", NULL, vars, tokens);
	if (check_element_csv(tokens[1], P_COORD, D_FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[1], vars, tokens);
	if (check_element_value(tokens[2], P_DIMEN, D_FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[2], vars, tokens);
	if (set_vars_csv(tokens[1], &center, S_POINT, D_FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[1], vars, tokens);
	if (set_vars_value(tokens[2], &radius, P_RADIUS) == FALSE)
		print_read_error("cannot set element values", tokens[2], vars, tokens);
	return (sphere_(center, radius, vars));
}

void	set_object_sphere(char **tokens, t_vars *vars)
{
	t_sphere	*sphere;
	t_color3	color;

	sphere = set_sphere(tokens, vars);
	if (check_element_csv(tokens[3], P_RGB, D_INT) == FALSE)
	{
		free(sphere);
		print_read_error("wrong element values", tokens[3], vars, tokens);
	}
	if (set_vars_csv(tokens[3], &color, S_COLOR, D_FLOAT) == FALSE)
	{
		free(sphere);
		print_read_error("cannot set element values", tokens[3], vars, tokens);
	}
	if (vars->scene->objects == NULL)
		vars->scene->objects = object_(SPHERE, sphere, color, vars);
	else
		append(&vars->scene->objects, object_(SPHERE, sphere, color, vars));
}
