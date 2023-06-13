/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:20:33 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/13 15:40:55 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	exit_hook(t_vars *vars)
{
	free_struct(vars);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		free_struct(vars);
		exit(0);
	}
	return (0);
}
