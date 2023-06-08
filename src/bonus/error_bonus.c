/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:53:01 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/08 21:53:03 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_custom_error(char *msg, void *data)
{
	printf("Error\n");
	printf("%s\n", msg);
	free_struct(data);
	exit(1);
}

void	print_error(char *msg, void *data)
{
	printf("Error\n");
	perror(msg);
	free_struct(data);
	exit(1);
}

void	print_read_error(char *msg, char *loc, void *data, char **tokens)
{
	printf("Error\n");
	printf("malformed file : ");
	if (loc != NULL)
		printf("%s\n", loc);
	printf("%s\n", msg);
	free_tokens(tokens);
	free_struct(data);
	exit(1);
}
