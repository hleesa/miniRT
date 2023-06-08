/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3__bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:02:21 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/08 22:02:25 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec_bonus.h"

t_point3	point3_(double x, double y, double z)
{
	t_point3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}
