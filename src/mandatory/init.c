/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:25:39 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/09 16:15:02 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_scene	*_init_scene(t_vars *vars)
{
	t_scene	*scene;

	scene = rt_malloc(sizeof(t_scene), vars);
	scene->canvas = canvas_(SCREEN_HEIGHT);
	scene->camera = \
		camera_(scene->canvas, \
		point3_(0, 0, 0), vec3_(0, 0, 1), INITIAL_VALUE);
	scene->ambient = ambient_(color3_(0, 0, 0), INITIAL_VALUE);
	scene->light = object_(POINT_LIGHT, \
		light_(point3_(0, 0, 0), color3_(1, 1, 1), INITIAL_VALUE, vars), \
		color3_(1, 1, 1), vars);
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
