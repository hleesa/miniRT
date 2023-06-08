/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color3__bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:00:38 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/08 22:00:42 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec_bonus.h"

t_color3	color3_(double r, double g, double b)
{
	t_color3	vec;

	vec.r = r;
	vec.g = g;
	vec.b = b;
	return (vec);
}
