/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:03:50 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/08 20:41:20 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	_free_mlx(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_del(vars->mlx);
}

static void	_free_objects(t_object *objects)
{
	t_object	*cur;
	t_object	*temp;

	if (objects == NULL)
		return ;
	cur = objects;
	while (cur)
	{
		temp = cur->next;
		free(cur->element);
		free(cur);
		cur = temp;
	}
}

void	free_struct(t_vars *vars)
{
	_free_mlx(vars);
	_free_objects(vars->scene->light);
	_free_objects(vars->scene->objects);
	free(vars->scene);
	free(vars);
}

int	free_tokens(char **tokens)
{
	int	i;

	if (tokens == NULL)
		return (TRUE);
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
	return (TRUE);
}
