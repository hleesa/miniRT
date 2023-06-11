/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:53:46 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/11 19:35:32 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cylinder	*set_cylinder(char **tokens, t_vars *vars)
{
	t_vec2		dh;
	t_point3	center;
	t_vec3		normal;

	if (check_element_count(tokens, 6) == FALSE)
		print_read_error("wrong cylinder element count", NULL, vars, tokens);
	if (check_element_csv(tokens[1], P_COORD, D_FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[1], vars, tokens);
	if (check_element_csv(tokens[2], P_NORM, D_FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[2], vars, tokens);
	if (check_element_value(tokens[3], P_DIMEN, D_FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[3], vars, tokens);
	if (check_element_value(tokens[4], P_DIMEN, D_FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[4], vars, tokens);
	if (set_vars_csv(tokens[1], &center, S_POINT) == FALSE)
		print_read_error("cannot set element values", tokens[1], vars, tokens);
	if (set_vars_csv(tokens[2], &normal, S_VEC) == FALSE)
		print_read_error("cannot set element values", tokens[2], vars, tokens);
	if (set_vars_value(tokens[3], &dh.x, P_RADIUS) == FALSE)
		print_read_error("cannot set element values", tokens[3], vars, tokens);
	if (set_vars_value(tokens[4], &dh.y, D_FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[4], vars, tokens);
	return (cylinder_(center, normal, dh, vars));
}

void	set_object_cylinder(char **tokens, t_vars *vars)
{
	t_cylinder	*cylinder;
	t_color3	color;

	cylinder = set_cylinder(tokens, vars);
	if (check_element_csv(tokens[5], P_RGB, D_INT) == FALSE)
	{
		free(cylinder);
		print_read_error("wrong element values", tokens[5], vars, tokens);
	}
	if (set_vars_csv(tokens[5], &color, S_COLOR) == FALSE)
	{
		free(cylinder);
		print_read_error("cannot set element values", tokens[5], vars, tokens);
	}
	if (vars->scene->objects == NULL)
		vars->scene->objects = object_(CYLINDER, cylinder, color, vars);
	else
		append(&vars->scene->objects, object_(CYLINDER, cylinder, color, vars));
}

t_plane	*set_plane(char **tokens, t_vars *vars)
{
	t_point3	point;
	t_vec3		normal;

	if (check_element_count(tokens, 4) == FALSE)
		print_read_error("wrong plane element count", NULL, vars, tokens);
	if (check_element_csv(tokens[1], P_COORD, D_FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[1], vars, tokens);
	if (check_element_csv(tokens[2], P_NORM, D_FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[2], vars, tokens);
	if (set_vars_csv(tokens[1], &point, S_POINT) == FALSE)
		print_read_error("cannot set element values", tokens[1], vars, tokens);
	if (set_vars_csv(tokens[2], &normal, S_VEC) == FALSE)
		print_read_error("cannot set element values", tokens[2], vars, tokens);
	return (plane_(point, normal, vars));
}

void	set_object_plane(char **tokens, t_vars *vars)
{
	t_plane		*plane;
	t_color3	color;

	plane = set_plane(tokens, vars);
	if (check_element_csv(tokens[3], P_RGB, D_INT) == FALSE)
	{
		free(plane);
		print_read_error("wrong element values", tokens[3], vars, tokens);
	}
	if (set_vars_csv(tokens[3], &color, S_COLOR) == FALSE)
	{
		free(plane);
		print_read_error("cannot set element values", tokens[3], vars, tokens);
	}
	if (vars->scene->objects == NULL)
		vars->scene->objects = object_(PLANE, plane, color, vars);
	else
		append(&vars->scene->objects, object_(PLANE, plane, color, vars));
}
