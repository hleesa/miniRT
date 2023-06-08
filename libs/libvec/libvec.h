/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:33:54 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/07 14:46:31 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H

# include <math.h>

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_vector3
{
	union
	{
		struct
		{
			double	ai;
			double	bj;
			double	ck;
		};
		struct
		{
			double	x;
			double	y;
			double	z;
		};
		struct
		{
			double	r;
			double	g;
			double	b;
		};
		struct
		{
			double	arr[3];
		};
	};
}	t_vec3;

typedef t_vec3	t_color3;
typedef t_vec3	t_point3;

t_vec3		add(t_vec3 u, t_vec3 v);
t_color3	color3_(double r, double g, double b);
t_vec3		cross(t_vec3 u, t_vec3 v);
double		dot(t_vec3 u, t_vec3 v);
t_vec3		elem_max(t_vec3 u, t_vec3 v);
t_vec3		elem_min(t_vec3 u, t_vec3 v);
t_vec3		elem_prod(t_vec3 u, t_vec3 v);
double		mag(t_vec3 v);
double		mag_sq(t_vec3 v);
t_vec3		norm(t_vec3 v);
t_point3	point3_(double x, double y, double z);
t_vec3		scl_add(double t, t_vec3 v);
t_vec3		scl_div(double t, t_vec3 v);
t_vec3		scl_sub(double t, t_vec3 v);
t_vec3		scl_mul(double t, t_vec3 v);
t_vec3		sub(t_vec3 u, t_vec3 v);
t_vec2		vec2_(double x, double y);
t_vec3		vec3_(double ai, double bj, double ck);

#endif
