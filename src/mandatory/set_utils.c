/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:27:41 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/13 14:54:23 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	set_vars_value(char *elem, void *value, int type)
{
	t_bool	is_error;

	is_error = FALSE;
	if (type == D_FLOAT)
		*(double *)value = rt_atof(elem, &is_error);
	else if (type == D_INT)
		*(int *)value = ft_atoi(elem);
	else if (type == P_RADIUS)
		*(double *)value = rt_atof(elem, &is_error) / 2.0;
	else
		is_error = TRUE;
	return (!is_error);
}

t_bool	set_vars_csv(char *elem, void *csv, int type_s)
{
	t_bool	is_error;
	char	**tokens;

	is_error = FALSE;
	tokens = ft_split(elem, ',');
	if (type_s == S_COLOR)
		*(t_point3 *)csv = color3_(rt_atof(tokens[0], &is_error) / 255, \
			rt_atof(tokens[1], &is_error) / 255, \
			rt_atof(tokens[2], &is_error) / 255);
	else if (type_s == S_POINT)
		*(t_point3 *)csv = point3_(rt_atof(tokens[0], &is_error), \
			rt_atof(tokens[1], &is_error), rt_atof(tokens[2], &is_error));
	else if (type_s == S_VEC)
		*(t_vec3 *)csv = vec3_(rt_atof(tokens[0], &is_error), \
			rt_atof(tokens[1], &is_error), rt_atof(tokens[2], &is_error));
	else
		is_error = TRUE;
	free_tokens(tokens);
	return (!is_error);
}
