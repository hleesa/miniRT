/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redef_mlx_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:54:13 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/08 21:54:14 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*rt_mlx_get_data_addr(t_vars *vars)
{
	char	*ret;
	void	*img;
	int		*bits_per_pixel;
	int		*line_length;
	int		*endian;

	img = vars->img.img;
	bits_per_pixel = &vars->img.bits_per_pixel;
	line_length = &vars->img.line_length;
	endian = &vars->img.endian;
	ret = mlx_get_data_addr(img, bits_per_pixel, line_length, endian);
	if (ret == NULL)
		print_error("mlx_get_vars_addr ", vars);
	return (ret);
}

void	*rt_mlx_init(t_vars *vars)
{
	void	*ret;

	ret = mlx_init();
	if (ret == NULL)
		print_error("mlx_init ", vars);
	return (ret);
}

void	*rt_mlx_new_image(t_vars *vars, int width, int height)
{
	void	*ret;

	ret = mlx_new_image(vars->mlx, width, height);
	if (ret == NULL)
		print_error("mlx_new_image ", vars);
	return (ret);
}

void	*rt_mlx_new_window(t_vars *vars, int sx, int sy, char *title)
{
	void	*ret;

	ret = mlx_new_window(vars->mlx, sx, sy, title);
	if (ret == NULL)
		print_error("mlx_new_window ", vars);
	return (ret);
}

void	rt_mlx_pixel_put(t_mlx_data *img, int x, int y, t_color3 color)
{
	char	*dst;
	int		pixel;

	pixel = (int)(255.999 * color.r) << 16 | \
			(int)(255.999 * color.g) << 8 | \
			(int)(255.999 * color.b);
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = pixel;
}
