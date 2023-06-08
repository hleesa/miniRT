/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_max_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:01:13 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/08 22:01:17 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec_bonus.h"

t_vec3	elem_max(t_vec3 u, t_vec3 v)
{
	if (u.ai < v.ai)
		u.ai = v.ai;
	if (u.bj < v.bj)
		u.bj = v.bj;
	if (u.ck < v.ck)
		u.ck = v.ck;
	return (u);
}
