/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:40:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/07 17:17:53 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	_print_usage(void)
{
	printf("Usage: ./miniRT <rt_file>\n");
	printf("<rt_file> should be a file with the '.rt' extension.\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2 || check_file_ext(argv[1]) == FALSE)
		return (_print_usage());
	vars = init_vars();
	read_file(vars, argv[1]);
	render(vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, RED_CROSS, 0, exit_hook, vars);
	mlx_loop(vars->mlx);
	return (0);
}
