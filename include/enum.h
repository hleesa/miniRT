/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:36:07 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/07 16:58:10 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ENUM_H
# define ENUM_H

enum e_root
{
	INVALID_ROOT = -1,
};

enum e_bool
{
	FALSE,
	TRUE,
};

enum e_object_type
{
	PLANE,
	SPHERE,
	CYLINDER,
	OBJECT_TYPE_SIZE,
};

enum e_component
{
	TOP,
	BASE,
};

enum e_light
{
	LIGHT_POINT = 42,
};

enum e_key
{
	ESC = 53,
	LEFT_ARROW = 123,
	RIGHT_ARROW = 124,
	DOWN_ARROW = 125,
	UP_ARROW = 126,
	DOWN_NUM = 84,
	UP_NUM = 91,
	A = 0,
	S = 1,
	D = 2,
	W = 13,
	T = 17,
	V = 9,
	DIR_SIZE = 6,
};

#endif
