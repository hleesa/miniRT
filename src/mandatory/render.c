/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:52:11 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/08 21:15:37 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render(t_vars *vars)
{
	int		x;
	int		y;
	t_scene	*scene;
	t_vec2	pixel_pos;

	scene = vars->scene;
	y = scene->canvas.height - 1;
	while (y >= 0)
	{
		printf("rendering... %.2f%%", \
			(float)(scene->canvas.height - y) / scene->canvas.height * 100);
		x = 0;
		while (x < scene->canvas.width)
		{
			pixel_pos.x = (double) x / (scene->canvas.width - 1);
			pixel_pos.y = 1 - ((double) y / (scene->canvas.height - 1));
			scene->ray = primary_ray(&scene->camera, pixel_pos);
			rt_mlx_pixel_put(&vars->img, x, y, trace_ray(scene));
			x++;
		}
		y--;
		printf("\033[1A\n");
	}
	printf("\n");
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
