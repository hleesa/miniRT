/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:52:19 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/12 14:46:13 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_bool	check_element_attr(char *elem, int type_p)
{
	t_bool			is_error;
	const double	ed = rt_atof(elem, &is_error);
	const int		ei = ft_atoi(elem);

	is_error = FALSE;
	if (type_p == P_COORD || type_p == P_DIMEN)
		if (INT_MAX < ed || ed < INT_MIN || is_error == TRUE)
			return (FALSE);
	if (type_p == P_FOV)
		if (180 < ed || ed < 0 || is_error == TRUE)
			return (FALSE);
	if (type_p == P_LIGHT)
		if (1.0 < ed || ed < 0.0 || is_error == TRUE)
			return (FALSE);
	if (type_p == P_NORM)
		if (1.0 < ed || ed < -1.0 || is_error == TRUE)
			return (FALSE);
	if (type_p == P_RGB)
		if (255 < ei || ei < 0)
			return (FALSE);
	return (TRUE);
}

t_bool	check_element_count(char **tokens, size_t size)
{
	size_t	count;

	count = count_tokens(tokens);
	if (count != size)
		return (FALSE);
	return (TRUE);
}

t_bool	check_element_csv(char *csv, int type_p, int type_d)
{
	size_t	token_count;
	t_bool	ret_val;
	char	**csv_tokens;

	ret_val = FALSE;
	csv_tokens = ft_split(csv, ',');
	token_count = count_tokens(csv_tokens);
	if (count_char(csv, ',') == 2 && token_count == 3)
	{
		ret_val = TRUE;
		while (token_count--)
			if (check_element_value(csv_tokens[token_count], \
				type_p, type_d) == FALSE)
				ret_val = FALSE;
	}
	if (ret_val && type_p == P_NORM && is_normalized(csv_tokens) == FALSE)
		ret_val = FALSE;
	free_tokens(csv_tokens);
	return (ret_val);
}

t_bool	check_element_value(char *elem, int type_p, int type_d)
{
	if (type_d == D_INT)
		if (is_int_fmt(elem) == FALSE)
			return (FALSE);
	if (type_d == D_FLOAT)
		if (is_float_fmt(elem) == FALSE)
			return (FALSE);
	if (check_element_attr(elem, type_p) == FALSE)
		return (FALSE);
	return (TRUE);
}

t_bool	check_file_ext(char	*file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4)
		return (FALSE);
	if (file[len - 3] != '.' || file[len - 2] != 'r' || file[len - 1] != 't')
		return (FALSE);
	if (file[len - 4] == '/')
		return (FALSE);
	return (TRUE);
}
