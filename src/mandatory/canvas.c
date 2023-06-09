/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:04:06 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/09 16:05:10 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_canvas	canvas_(int height)
{
	t_canvas	canvas;

	canvas.aspect_ratio = 16.0 / 9.0;
	canvas.height = height;
	canvas.width = height * canvas.aspect_ratio;
	return (canvas);
}
