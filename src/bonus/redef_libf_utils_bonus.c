/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redef_libf_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:54:05 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/12 15:03:56 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	rt_atoi(const char *str, t_bool *is_error, int *sign)
{
	size_t		idx;
	long long	ret;

	idx = 0;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			*sign = -1;
		++idx;
	}
	ret = toll(str, *sign, idx, is_error);
	if (str[idx] == 0 || ret > INT_MAX || ret < INT_MIN)
		*is_error = TRUE;
	return ((int)ret);
}

long long	toll(const char *str, int sign, size_t idx, t_bool *is_error)
{
	long long	acc;
	long long	llmax;

	acc = 0;
	llmax = LONG_LONG_MAX;
	while (str[idx] && str[idx] != '.')
	{
		if (ft_isdigit(str[idx]) == FALSE)
		{
			*is_error = TRUE;
			return (*is_error);
		}
		if ((acc > llmax / 10) \
			|| ((acc == llmax / 10 && (str[idx] - '0') > (llmax % 10))) \
			|| !ft_isdigit(str[idx]))
		{
			if (sign == 1)
				return (llmax);
			else
				return (-llmax - 1LL);
		}
		acc = acc * 10 + str[idx] - '0';
		++idx;
	}
	return (sign * acc);
}

long long	tollp(const char *str, size_t idx, \
					int *precision, t_bool *is_error)
{
	long long		acc;
	long long		llmax;

	acc = 0;
	*precision = 0;
	llmax = LONG_LONG_MAX;
	while (str[idx])
	{
		if (acc > llmax / 10 || (acc == llmax / 10 && str[idx] - '0' \
		> (llmax % 10)) || !ft_isdigit(str[idx]) || *precision >= 15)
		{
			*is_error = TRUE;
			return (*is_error);
		}
		acc = acc * 10 + str[idx] - '0';
		++*precision;
		++idx;
	}
	return (acc);
}
