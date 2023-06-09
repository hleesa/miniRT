/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:16:36 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/09 14:16:44 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_BONUS_H
# define ENUM_BONUS_H

enum e_bool
{
	FALSE,
	TRUE,
};

enum e_object_type
{
	CONE,
	PLANE,
	SPHERE,
	CYLINDER,
	OBJECT_TYPE_SIZE,
};

enum e_cylinder
{
	TOP,
	BASE,
};

#endif
