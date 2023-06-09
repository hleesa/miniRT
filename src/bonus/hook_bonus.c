/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:53:16 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/09 16:51:36 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static void	check_leaks(void)
{
	// 지우는거 잊지 말기
	system("leaks --list -- miniRT_bonus");
}

int	exit_hook(t_vars *vars)
{
	//mlx_destroy_window(vars->mlx, vars->win);
	free_struct(vars);
	atexit(check_leaks);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		//mlx_destroy_window(vars->mlx, vars->win);
		free_struct(vars);
		atexit(check_leaks);
		exit(0);
	}
	return (0);
}

