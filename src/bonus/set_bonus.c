/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:54:21 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/09 20:59:27 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	set_ambient(char **tokens, t_vars *vars)
{
	double		lighting_ratio;
	t_color3	color;

	if (vars->scene->ambient.lighting_ratio != INITIAL_VALUE)
		print_read_error("duplicated ambient element", NULL, vars, tokens);
	if (check_element_count(tokens, 3) == FALSE)
		print_read_error("wrong ambient element count", NULL, vars, tokens);
	if (check_element_value(tokens[1], P_LIGHT, D_FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[1], vars, tokens);
	if (check_element_csv(tokens[2], P_RGB, D_INT) == FALSE)
		print_read_error("wrong element values", tokens[2], vars, tokens);
	if (set_vars_value(tokens[1], &lighting_ratio, D_FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[1], vars, tokens);
	if (set_vars_csv(tokens[2], &color, S_COLOR, D_FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[2], vars, tokens);
	vars->scene->ambient.lighting_ratio = lighting_ratio;
	vars->scene->ambient.color = scl_mul(lighting_ratio, color);
}

void	set_camera(char **tokens, t_vars *vars)
{
	t_point3	look_from;
	t_vec3		look_at;
	double		h_fov;

	if (vars->scene->camera.h_fov != INITIAL_VALUE)
		print_read_error("duplicated camera element", NULL, vars, tokens);
	if (check_element_count(tokens, 4) == FALSE)
		print_read_error("wrong camera element count", NULL, vars, tokens);
	if (check_element_csv(tokens[1], P_COORD, D_FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[1], vars, tokens);
	if (check_element_csv(tokens[2], P_NORM, D_FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[2], vars, tokens);
	if (check_element_value(tokens[3], P_FOV, D_FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[3], vars, tokens);
	if (set_vars_csv(tokens[1], &look_from, S_POINT, D_FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[1], vars, tokens);
	if (set_vars_csv(tokens[2], &look_at, S_VEC, D_FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[2], vars, tokens);
	if (set_vars_value(tokens[3], &h_fov, D_FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[3], vars, tokens);
	vars->scene->camera = \
	camera_(vars->scene->canvas, look_from, look_at, h_fov);
}

void	set_light(char **tokens, t_vars *vars)
{
	t_point3	origin;
	t_color3	color;
	double		bright_ratio;
	t_light		*light;

	if (check_element_count(tokens, 4) == FALSE)
		print_read_error("wrong light element count", NULL, vars, tokens);
	if (check_element_csv(tokens[1], P_COORD, D_FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[1], vars, tokens);
	if (check_element_value(tokens[2], P_LIGHT, D_FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[2], vars, tokens);
	if (check_element_csv(tokens[3], P_RGB, D_INT) == FALSE)
		print_read_error("wrong element values", tokens[3], vars, tokens);
	if (set_vars_csv(tokens[1], &origin, S_POINT, D_FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[1], vars, tokens);
	if (set_vars_value(tokens[2], &bright_ratio, D_FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[2], vars, tokens);
	if (set_vars_csv(tokens[3], &color, S_COLOR, D_FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[3], vars, tokens);
	light = light_(origin, color, bright_ratio, vars);
	if (vars->scene->light == NULL)
		vars->scene->light = object_(LIGHT_POINT, light, color, vars);
	else
		append(&vars->scene->light, object_(LIGHT_POINT, light, color, vars));
}

void	set_vars(char **tokens, t_vars *vars)
{
	if (count_tokens(tokens) < 1 || ft_strncmp(tokens[0], "#", 1) == 0)
		return ;
	if (ft_strncmp(tokens[0], "A", 2) == 0)
		set_ambient(tokens, vars);
	else if (ft_strncmp(tokens[0], "C", 2) == 0)
		set_camera(tokens, vars);
	else if (ft_strncmp(tokens[0], "L", 2) == 0)
		set_light(tokens, vars);
	else if (ft_strncmp(tokens[0], "ch", 3) == 0)
		set_object_checkers(tokens, vars);
	else if (ft_strncmp(tokens[0], "co", 3) == 0)
		set_object_cone(tokens, vars);
	else if (ft_strncmp(tokens[0], "cy", 3) == 0)
		set_object_cylinder(tokens, vars);
	else if (ft_strncmp(tokens[0], "pl", 3) == 0)
		set_object_plane(tokens, vars);
	else if (ft_strncmp(tokens[0], "sp", 3) == 0)
		set_object_sphere(tokens, vars);
	else
		print_read_error("mismateched type", tokens[0], vars, tokens);
}
