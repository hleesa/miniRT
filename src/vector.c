/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:23:08 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:23:09 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec2	vec2_(double x, double y)
{
	t_vec2	this;

	this.x = x;
	this.y = y;
	return (this);
}

t_vec3	vec3_(double ai, double bj, double ck)
{
	t_vec3	this;

	this.ai = ai;
	this.bj = bj;
	this.ck = ck;
	return (this);
}

t_point3	point3_(double x, double y, double z)
{
	t_point3	this;

	this.x = x;
	this.y = y;
	this.z = z;
	return (this);
}

t_color3	color3_(double r, double g, double b)
{
	t_color3	this;

	this.r = r;
	this.g = g;
	this.b = b;
	return (this);
}
