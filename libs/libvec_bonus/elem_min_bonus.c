/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_min_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:01:22 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/08 22:01:26 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec_bonus.h"

t_vec3	elem_min(t_vec3 u, t_vec3 v)
{
	if (v.ai < u.ai)
		u.ai = v.ai;
	if (v.bj < u.bj)
		u.bj = v.bj;
	if (v.ck < u.ck)
		u.ck = v.ck;
	return (u);
}
