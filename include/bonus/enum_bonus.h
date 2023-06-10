/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:16:36 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/09 20:41:19 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_BONUS_H
# define ENUM_BONUS_H

enum e_bool
{
	FALSE,
	TRUE,
};

enum e_cylinder
{
	TOP,
	BASE,
};

enum e_data_type
{
	D_FLOAT,
	D_INT,
};

enum e_object_type
{
	CONE,
	PLANE,
	SPHERE,
	CYLINDER,
	CHECKERS,
	OBJECT_TYPE_SIZE,
};

enum e_property_type
{
	P_COORD,
	P_DIMEN,
	P_FOV,
	P_LIGHT,
	P_NORM,
	P_RGB,
	P_RADIUS,
};

enum e_struct_type
{
	S_COLOR,
	S_POINT,
	S_VEC,
};

#endif
