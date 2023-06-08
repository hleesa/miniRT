/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:25:39 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/08 21:13:02 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_ambient	_init_ambient(void)
{
	t_ambient	ambient;

	ambient.color = color3_(0, 0, 0);
	ambient.lighting_ratio = INITIAL_VALUE;
	return (ambient);
}

static t_canvas	_init_canvas(int height)
{
	t_canvas	canvas;

	canvas.aspect_ratio = 16.0 / 9.0;
	canvas.height = height;
	canvas.width = height * canvas.aspect_ratio;
	return (canvas);
}

static t_light	*_init_light(t_vars *vars)
{
	t_light		*light;
	t_point3	origin;
	t_color3	color;
	double		bright_ratio;

	origin = point3_(0, 0, 0);
	color = color3_(1, 1, 1);
	bright_ratio = INITIAL_VALUE;
	light = light_(origin, color, bright_ratio, vars);
	return (light);
}

static t_scene	*_init_scene(t_vars *vars)
{
	t_scene	*scene;

	scene = rt_malloc(sizeof(t_scene), vars);
	scene->canvas = _init_canvas(Y_END);
	scene->camera = \
	camera_(scene->canvas, point3_(0, 0, 0), vec3_(0, 0, 1), INITIAL_VALUE);
	scene->ambient = _init_ambient();
	scene->light = \
	object_(LIGHT_POINT, _init_light(vars), color3_(1, 1, 1), vars);
	scene->objects = NULL;
	return (scene);
}

t_vars	*init_vars(void)
{
	t_vars	*vars;
	int		width;
	int		height;

	vars = rt_malloc(sizeof(t_vars), NULL);
	vars->scene = _init_scene(vars);
	width = vars->scene->canvas.width;
	height = vars->scene->canvas.height;
	vars->mlx = NULL;
	vars->win = NULL;
	vars->img.img = NULL;
	vars->img.addr = NULL;
	vars->mlx = rt_mlx_init(vars);
	vars->win = rt_mlx_new_window(vars, width, height, "miniRT");
	vars->img.img = rt_mlx_new_image(vars, width, height);
	vars->img.addr = rt_mlx_get_data_addr(vars);
	return (vars);
}
