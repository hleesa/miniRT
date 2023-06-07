/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:10:26 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/07 17:19:48 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "define.h"
# include "enum.h"
# include "extern.h"
# include "struct.h"
# include "typedef.h"

int			exit_hook(t_vars *vars);
int			key_hook(int keycode, t_vars *vars);

void		print_error(char *msg, void *vars);
void		print_custom_error(char *msg, void *vars);
void		print_read_error(char *msg, char *loc, void *vars, char **tokens);

t_bool		check_element_attr(char *elem, int type_p);
t_bool		check_element_count(char **tokens, size_t size);
t_bool		check_element_csv(char *csv, int type_p, int type_d);
t_bool		check_element_value(char *elem, int type_p, int type_d);
t_bool		check_file_ext(char	*file);

size_t		count_char(char *line, char c);
size_t		count_tokens(char **tokens);
t_bool		is_int_fmt(char *elem);
t_bool		is_float_fmt(char *elem);

t_vars		*init_vars(void);

void		read_file(t_vars *vars, char *file);

void		set_vars(char **tokens, t_vars *vars);
t_bool		set_vars_value(char *elem, void *value, int type_d);
t_bool		set_vars_csv(char *elem, void *csv, int type_s, int type_d);

t_cylinder	*set_cylinder(char **tokens, t_vars *vars);
t_plane		*set_plane(char **tokens, t_vars *vars);
t_sphere	*set_sphere(char **tokens, t_vars *vars);
void		set_object_cylinder(char **tokens, t_vars *vars);
void		set_object_plane(char **tokens, t_vars *vars);
void		set_object_sphere(char **tokens, t_vars *vars);

void		render(t_vars *vars);

void		free_struct(t_vars *vars);
void		free_tokens(char **tokens);

t_camera	camera_(t_canvas canvas, t_point3 from, t_vec3 at, double h_fov);

t_light		*light_(t_point3 orig, t_color3 color, double bright, t_vars *vars);

t_object	*object_(t_object_type type, void *elem, t_color3 albd, t_vars *vars);
void		append(t_object **list, t_object *object);

t_cylinder	*cylinder_(t_point3 center, t_vec3 normal, t_vec2 dh, t_vars *dat);

t_plane		*plane_(t_point3 point, t_vec3 normal, t_vars *vars);

t_sphere	*sphere_(t_point3 center, double radius, t_vars *vars);

double		rt_atof(const char *str, int *error);
int			rt_atoi(const char *str, int *error, int *sign);
void		rt_close(int fd, t_vars *vars);
int			rt_open(char *file, int flag, t_vars *vars);
void		*rt_malloc(size_t size, t_vars *vars);

long long	toll(const char *str, int sign, size_t idx, int *error);
long long	tollp(const char *str, size_t idx, int *precision, int *error);

char		*rt_mlx_get_data_addr(t_vars *vars);
void		*rt_mlx_init(t_vars *vars);
void		*rt_mlx_new_image(t_vars *vars, int width, int height);
void		*rt_mlx_new_window(t_vars *vars, int sx, int sy, char *title);
void		rt_mlx_pixel_put(t_mlx_data *img, int x, int y, t_color3 color);

#endif
