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

enum e_cylinder
{
	TOP,
	BASE,
};

#endif
