/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:19:20 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/09 16:19:32 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_ambient	ambient_(t_color3 color, double lighting_ratio)
{
	t_ambient	ambient;

	ambient.color = color;
	ambient.lighting_ratio = lighting_ratio;
	return (ambient);
}
