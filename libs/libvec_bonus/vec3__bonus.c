/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3__bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:02:55 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/08 22:02:59 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec_bonus.h"

t_vec3	vec3_(double ai, double bj, double ck)
{
	t_vec3	vec;

	vec.ai = ai;
	vec.bj = bj;
	vec.ck = ck;
	return (vec);
}
