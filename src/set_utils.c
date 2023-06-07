/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:27:41 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/07 17:25:49 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	set_vars_value(char *elem, void *value, int type_d)
{
	int		error;

	error = FALSE;
	if (type_d == D_FLOAT)
		*(double *)value = rt_atof(elem, &error);
	if (type_d == D_INT)
		*(int *)value = ft_atoi(elem);
	if (error == TRUE)
		return (FALSE);
	return (TRUE);
}

t_bool	set_vars_csv(char *elem, void *csv, int type_s, int type_d)
{
	int		err;
	char	**tokens;

	err = FALSE;
	tokens = ft_split(elem, ',');
	if ((type_s == S_COLOR) && (type_d == D_FLOAT))
		*(t_color3 *)csv = color3_(rt_atof(tokens[0], &err) / 255, \
			rt_atof(tokens[1], &err) / 255, rt_atof(tokens[2], &err) / 255);
	if ((type_s == S_COLOR) && (type_d == D_INT))
		*(t_color3 *)csv = color3_(ft_atoi(tokens[0]) / 255, \
			ft_atoi(tokens[1]) / 255, ft_atoi(tokens[2]) / 255);
	if ((type_s == S_POINT) && (type_d == D_FLOAT))
		*(t_point3 *)csv = point3_(rt_atof(tokens[0], &err), \
			rt_atof(tokens[1], &err), rt_atof(tokens[2], &err));
	if ((type_s == S_POINT) && (type_d == D_INT))
		*(t_point3 *)csv = point3_(ft_atoi(tokens[0]), \
			ft_atoi(tokens[1]), ft_atoi(tokens[2]));
	if ((type_s == S_VEC) && (type_d == D_FLOAT))
		*(t_vec3 *)csv = vec3_(rt_atof(tokens[0], &err), \
			rt_atof(tokens[1], &err), rt_atof(tokens[2], &err));
	if ((type_s == S_VEC) && (type_d == D_INT))
		*(t_vec3 *)csv = vec3_(ft_atoi(tokens[0]), \
			ft_atoi(tokens[1]), ft_atoi(tokens[2]));
	free_tokens(tokens);
	return (!err);
}
