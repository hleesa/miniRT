# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 16:27:39 by gychoi            #+#    #+#              #
#    Updated: 2023/06/09 20:39:27 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

NAME = miniRT
NAME_BONUS = miniRT_bonus

LIBDIR = libs/
MLXDIR = $(LIBDIR)minilibx_opengl_20191021/
LFTDIR = $(LIBDIR)libft/
LVCDIR = $(LIBDIR)libvec/
LVBNSD = $(LIBDIR)libvec_bonus/
INCDIR = include/
SRCDIR = src/
MDTDIR = mandatory/
BNSDIR = bonus/
MDOBJD = build/
BNOBJD = build_bonus/

CC = cc
CFLAGS = -Wall -Wextra -Werror -O2
DFLAGS = -MMD -MP
CPPFLAGS = -I$(MLXDIR) -I$(LFTDIR)
LDFLAGS = -L$(MLXDIR) -L$(LFTDIR)
LDLIBS = -lmlx -lft
MLXFLAGS = -framework OpenGL -framework AppKit
RM = rm -rf

MLX = $(MLXDIR)libmlx.a
LIBFT = $(LFTDIR)libft.a
LIBVEC = $(LVCDIR)libvec.a
LIBVEC_BONUS = $(LVBNSD)libvec_bonus.a

MDTDIR = src/mandatory/
MDTSRC = ambient.c \
		 camera.c \
		 canvas.c \
		 check.c \
		 check_utils.c \
		 cylinder.c \
		 cylinder_base.c \
		 cylinder_surface.c \
		 diffuse.c \
		 error.c \
		 free.c \
		 hit.c \
		 hook.c \
		 init.c \
		 light.c \
		 main.c \
		 object.c \
		 phong_lighting.c \
		 plane.c \
		 ray.c \
		 read.c \
		 redef_libf.c \
		 redef_libf_utils.c \
		 redef_mlx.c \
		 render.c \
		 set.c \
		 set_object_1.c \
		 set_object_2.c \
		 set_utils.c \
		 specular.c \
		 sphere.c \

BNSDIR = src/bonus/
BNSSRC = ambient_bonus.c \
		 camera_bonus.c \
		 canvas_bonus.c \
		 check_bonus.c \
		 check_utils_bonus.c \
		 checkers_bonus.c \
		 cone_base_bonus.c \
		 cone_bonus.c \
		 cone_surfcae_bonus.c \
		 cylinder_bonus.c \
		 cylinder_base_bonus.c \
		 cylinder_surface_bonus.c \
		 diffuse_bonus.c \
		 error_bonus.c \
		 free_bonus.c \
		 hit_bonus.c \
		 hook_bonus.c \
		 init_bonus.c \
		 light_bonus.c \
		 main_bonus.c \
		 object_bonus.c \
		 phong_lighting_bonus.c \
		 plane_bonus.c \
		 ray_bonus.c \
		 read_bonus.c \
		 redef_libf_bonus.c \
		 redef_libf_utils_bonus.c \
		 redef_mlx_bonus.c \
		 render_bonus.c \
		 set_bonus.c \
		 set_object_1_bonus.c \
		 set_object_2_bonus.c \
		 set_utils_bonus.c \
		 specular_bonus.c \
		 sphere_bonus.c \

MANDATORY = $(addprefix $(MDTDIR), $(MDTSRC))
BONUS = $(addprefix $(BNSDIR), $(BNSSRC))

MDTOBJ = $(patsubst %.c, %.o, $(MDTSRC))
MDOBJS = $(addprefix $(MDOBJD), $(MDTOBJ))
MDDEPS = $(MDOBJS:.o=.d)

BNSOBJ = $(patsubst %.c, %.o, $(BNSSRC))
BNOBJS = $(addprefix $(BNOBJD), $(BNSOBJ))
BNDEPS = $(BNOBJS:.o=.d)

ifdef WITH_BONUS
	CPPFLAGS += -Iinclude/bonus/ -I$(LVBNSD)
	LDFLAGS += -L$(LVBNSD)
	LDLIBS += -lvec_bonus
	COMPILE_LIBRARY = $(LIBVEC_BONUS)
	COMPILE_OBJECT = $(BNOBJS)
	COMPILE_SOURCE_DIR = $(BNSDIR)
	COMPILE_OBJECT_DIR = $(BNOBJD)
	DEPS = $(BNDEPS)
else
	CPPFLAGS += -Iinclude/mandatory/ -I$(LVCDIR)
	LDFLAGS += -L$(LVCDIR)
	LDLIBS += -lvec
	COMPILE_LIBRARY = $(LIBVEC)
	COMPILE_OBJECT = $(MDOBJS)
	COMPILE_SOURCE_DIR = $(MDTDIR)
	COMPILE_OBJECT_DIR = $(MDOBJD)
	DEPS = $(MDDEPS)
endif


$(COMPILE_OBJECT_DIR)%.o: $(COMPILE_SOURCE_DIR)%.c
	@mkdir -p $(COMPILE_OBJECT_DIR)
	$(COMPILE.c) $(DFLAGS) $(OUTPUT_OPTION) $<

$(NAME): $(COMPILE_OBJECT) $(LIBFT) $(MLX) $(COMPILE_LIBRARY)
	$(LINK.o) $^ $(LDLIBS) $(MLXFLAGS) -o $@
	@install_name_tool -change libmlx.dylib $(MLXDIR)libmlx.dylib $(NAME)

$(NAME_BONUS): $(COMPILE_OBJECT) $(LIBFT) $(MLX) $(COMPILE_LIBRARY)
	$(LINK.o) $^ $(LDLIBS) $(MLXFLAGS) -o $@
	@install_name_tool -change libmlx.dylib $(MLXDIR)libmlx.dylib $(NAME_BONUS)

$(LIBFT): .FORCE
	$(MAKE) -C $(LFTDIR)

$(LIBVEC): .FORCE
	$(MAKE) -C $(LVCDIR)

$(LIBVEC_BONUS): .FORCE
	$(MAKE) -C $(LVBNSD)

$(MLX): .FORCE
	$(MAKE) -C $(MLXDIR)

.FORCE:

-include $(DEPS)

.PHONY: all clean fclean re bonus

all:
	$(RM) $(BNOBJD)
	$(RM) $(NAME_BONUS)
	$(MAKE) $(NAME)

bonus:
	$(RM) $(MDOBJD)
	$(RM) $(NAME)
	$(MAKE) $(NAME_BONUS) WITH_BONUS=1

clean:
	$(MAKE) -C $(LFTDIR) clean
	$(MAKE) -C $(LVCDIR) clean
	$(MAKE) -C $(LVBNSD) clean
	$(MAKE) -C $(MLXDIR) clean
	$(RM) $(MDOBJD)
	$(RM) $(BNOBJD)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(LIBVEC)
	$(RM) $(LIBVEC_BONUS)
	$(RM) $(MLX)
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean
	$(MAKE) all
