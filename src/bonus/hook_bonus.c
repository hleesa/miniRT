/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:53:16 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/13 15:40:44 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

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
