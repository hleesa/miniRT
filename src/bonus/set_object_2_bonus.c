/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:54:31 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/09 20:13:09 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

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

t_cone	*set_cone(char **tokens, t_vars *vars)
{
	t_vec2		dh;
	t_point3	center;
	t_vec3		normal;

	if (check_element_count(tokens, 6) == FALSE)
		print_read_error("wrong cone element count", NULL, vars, tokens);
	if (check_element_csv(tokens[1], P_COORD, D_FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[1], vars, tokens);
	if (check_element_csv(tokens[2], P_NORM, D_FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[2], vars, tokens);
	if (check_element_value(tokens[3], P_DIMEN, D_FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[3], vars, tokens);
	if (check_element_value(tokens[4], P_DIMEN, D_FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[4], vars, tokens);
	if (set_vars_csv(tokens[1], &center, S_POINT, D_FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[1], vars, tokens);
	if (set_vars_csv(tokens[2], &normal, S_VEC, D_FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[2], vars, tokens);
	if (set_vars_value(tokens[3], &dh.x, P_RADIUS) == FALSE)
		print_read_error("cannot set element values", tokens[3], vars, tokens);
	if (set_vars_value(tokens[4], &dh.y, D_FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[4], vars, tokens);
	return (cone_(center, normal, dh, vars));
}

void	set_object_cone(char **tokens, t_vars *vars)
{
	t_cone		*cone;
	t_color3	color;

	cone = set_cone(tokens, vars);
	if (check_element_csv(tokens[5], P_RGB, D_INT) == FALSE)
	{
		free(cone);
		print_read_error("wrong element values", tokens[5], vars, tokens);
	}
	if (set_vars_csv(tokens[5], &color, S_COLOR, D_FLOAT) == FALSE)
	{
		free(cone);
		print_read_error("cannot set element values", tokens[5], vars, tokens);
	}
	if (vars->scene->objects == NULL)
		vars->scene->objects = object_(CONE, cone, color, vars);
	else
		append(&vars->scene->objects, object_(CONE, cone, color, vars));
}
