/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:01:05 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/08 21:10:48 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*object_(t_object_type type, void *elem, t_color3 albedo, \
					t_vars *vars)
{
	t_object	*object;

	object = rt_malloc(sizeof(t_object), vars);
	object->element = elem;
	object->next = NULL;
	object->albedo = albedo;
	object->type = type;
	return (object);
}

void	append(t_object **list, t_object *object)
{
	t_object	*cur;

	if (*list == NULL)
	{
		*list = object;
		return ;
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = object;
}
