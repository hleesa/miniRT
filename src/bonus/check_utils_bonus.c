/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:52:26 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/08 22:06:57 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

size_t	count_char(char *line, char c)
{
	size_t	count;
	size_t	index;

	count = 0;
	index = 0;
	while (line[index] != '\0')
	{
		if (line[index] == c)
			count++;
		index++;
	}
	return (count);
}

size_t	count_tokens(char **tokens)
{
	size_t	count;

	count = 0;
	while (tokens[count])
		count++;
	return (count);
}

t_bool	is_int_fmt(char *elem)
{
	size_t	sign_count;
	size_t	index;

	index = 0;
	sign_count = 0;
	while (elem[index] != '\0')
	{
		if (ft_isdigit(elem[index]) == FALSE)
		{
			if ((elem[index] == '-' || elem[index] == '+') && sign_count == 0)
				sign_count++;
			else
				return (FALSE);
		}
		index++;
	}
	return (TRUE);
}

t_bool	is_float_fmt(char *elem)
{
	size_t	dot_count;
	size_t	sign_count;
	size_t	index;

	index = -1;
	dot_count = 0;
	sign_count = 0;
	while (elem[++index] != '\0')
	{
		if (ft_isdigit(elem[index]) == FALSE)
		{
			if ((elem[index] == '-' || elem[index] == '+') && sign_count == 0)
				sign_count++;
			else if ((elem[index] == '.') && dot_count == 0)
				dot_count++;
			else
				return (FALSE);
		}
	}
	return (TRUE);
}

t_bool	is_normalized(char **csv_tokens)
{
	int		error;
	double	length;
	t_vec3	vec_check;

	vec_check.ai = rt_atof(csv_tokens[0], &error);
	vec_check.bj = rt_atof(csv_tokens[1], &error);
	vec_check.ck = rt_atof(csv_tokens[2], &error);
	if (error == TRUE)
		return (FALSE);
	length = mag(vec_check);
	if (length != 1.0)
		return (FALSE);
	return (TRUE);
}
